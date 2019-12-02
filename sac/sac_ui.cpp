#include <Arduino.h>
#include "pinconf.h"
#define __GLOBAL_DEFINE__
#include "sac_ui.h"
/*****************************************************************************/
/*****************************************************************************/
/* 変数定義 */
/*****************************************************************************/
/*****************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @var        
/// @brief      変数の説明
///
///////////////////////////////////////////////////////////////////////////////
/// ADSWの電圧設定
/**
 * PU=10k
 * GO,ESC,UP,DOWN
 * GO = 0ohm
 * ESC = R1
 * UP = R1 + R2
 * DOWN = R1 + R2 + R3
 * 
 * RU 10k
 * R1 3.3k
 * R2 6.8k
 * R3 18k
 * GO = 0V = 0~127
 * ESC = 1.24V = 128 ~ 254 ~ 383
 * UP = 2.51V = 384 ~ 514 ~ 635
 * DOWN = 3.69V = 636 ~ 756 ~ 877
 */
const s16 s16c_sac_ui_sw_GO_THL = -10;
const s16 s16c_sac_ui_sw_GO_THH = 255;
const s16 s16c_sac_ui_sw_ESC_THL = 256;   //
const s16 s16c_sac_ui_sw_ESC_THH = 596;     //  
const s16 s16c_sac_ui_sw_UP_THL = 597;
const s16 s16c_sac_ui_sw_UP_THH = 724;
const s16 s16c_sac_ui_sw_DOWN_THL = 725;
const s16 s16c_sac_ui_sw_DOWN_THH = 811;

//const unsigned int sound_f[] = {262, 277, 311, 330, 349, 370, 392, 415, 440, 466, 494, 523};



en_sac_ui_sw eng_sac_ui_sw(void)
{
    u16 adsw = analogRead(PNCF_UI_ADSW);
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


void vdg_sac_ui_tone_piroU(void)
{
    tone(PNCF_UI_SP, 2000, 200);
    tone(PNCF_UI_SP, 3000, 100);
}
void vdg_sac_ui_tone_piroD(void)
{
    tone(PNCF_UI_SP, 3000, 2000);
    tone(PNCF_UI_SP, 2000, 100);
}
void vdg_sac_ui_tone_pi(void)
{
    tone(PNCF_UI_SP, 3000, 100);
}

void vdg_sac_ui_tone_WRN(void)
{
    tone(PNCF_UI_SP, 4000, 500);
    tone(PNCF_UI_SP, 1000, 500);
}
