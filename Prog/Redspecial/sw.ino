/*****************************************************************************/
#include "sw.h"
#include "typedef_arduino.h"
#include "pinconf.h"

#define SW_GO_TH    (u16)(100)     /*  */
#define SW_ESC_TH   (u16)(520)     /*  */
#define SW_UP_TH    (u16)(700)     /* */
#define SW_DOWN_TH  (u16)(800)    /*  */
const s16 s16c_sac_ui_sw_GO_THL = -10;
const s16 s16c_sac_ui_sw_GO_THH = 255;
const s16 s16c_sac_ui_sw_ESC_THL = 256;   //
const s16 s16c_sac_ui_sw_ESC_THH = 596;     //  
const s16 s16c_sac_ui_sw_UP_THL = 597;
const s16 s16c_sac_ui_sw_UP_THH = 724;
const s16 s16c_sac_ui_sw_DOWN_THL = 725;
const s16 s16c_sac_ui_sw_DOWN_THH = 811;

byte swnow;      //  スイッチの現在状態
byte swold;         //  スイッチの前回値    
byte  swbff[SW_BUFFSIZE];   //  スイッチの前状態
byte  swedge;     //  エッジがあるかないかを保存

int sw_intvcnt;

void swinit()
{
    for (int cnt = 0; cnt < SW_BUFFSIZE; cnt++)
    {
        swbff[cnt] = SW_NON;
    }
    swedge = SW_EDGE_NON;
    swnow = SW_NON;
    swold = SW_NON;
    sw_intvcnt = 0;
}

byte swread()
{
    return swnow;
}

byte swreadold()
{
    return swold;
}

byte swreadedge()
{
    byte tmp = swedge;
    if (tmp != SW_EDGE_NON)
    {
        noInterrupts();
        swedge = SW_EDGE_NON;
        interrupts();
    }
    return tmp;
}


void swmntr()
{
    Serial.print("<<sw>>[n=");
    Serial.print(swnow);
    Serial.print(",o=");
    Serial.print(swold);
    Serial.print(",b=[");
    for (int cnt = 0; cnt < SW_BUFFSIZE; cnt++)
    {
        Serial.print(swbff[cnt]);
        Serial.print(",");
    }
    Serial.print("],e=");
    Serial.print(swedge);
    Serial.print("]<<sw>>");
}

void swintr()
{
    int cnt;
    //  sw buffer
    if (10 < sw_intvcnt)
    {
        sw_intvcnt = 0;
        for (cnt = 0; cnt < (SW_BUFFSIZE - 1); cnt++)
        {
            swbff[cnt + 1] = swbff[cnt];
        }
        swbff[0] = swreadad(); 
        //  nois fillter
        for (cnt = 0; (cnt < (SW_BUFFSIZE -1)) && (swbff[cnt] == swbff[cnt+1]); cnt++)
        {/* empty */}
        //if (cnt > SW_NOISCUT_LEN)
        if (cnt > (SW_BUFFSIZE - 2))
        {
            swold = swnow;
            swnow = swbff[0];
            if (swold != swnow)
            {
                if (swnow == SW_NON)
                {
                    swedge = SW_EDGE_DOWN;
                }
                else
                {
                    swedge = SW_EDGE_UP;
                }
            }
        }
    }
    sw_intvcnt++;
}



byte swreadad(void)
{
    s16 adsw;
    //tmp = analogRead(8);
    adsw = analogRead(PNCF_UI_ADSW);
    if ( (s16c_sac_ui_sw_GO_THL <= adsw) && (adsw < s16c_sac_ui_sw_GO_THH) )
    {
        return SW_GO;
    }
    else if ( (s16c_sac_ui_sw_ESC_THL < adsw) && (adsw < s16c_sac_ui_sw_ESC_THH) )
    {
        return SW_ESC;
    }
    else if ( (s16c_sac_ui_sw_UP_THL < adsw) && (adsw < s16c_sac_ui_sw_UP_THH) )
    {
        return SW_UP;
    }
    else if ( (s16c_sac_ui_sw_DOWN_THL < adsw) && (adsw < s16c_sac_ui_sw_DOWN_THH) )
    {
        return SW_DOWN;
    }
    else
    {
        return SW_NON;
    }
}


