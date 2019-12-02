#include <SPI.h>
#include "pinconf.h"

#define __GLOBALL_DEFINE__
#include "drv_dac7614.h"


SPISettings dac7614SPISetting(1000000, MSBFIRST, SPI_MODE3);

/** 
* @fn       void vdg_drv_dac7614_setup(void)
* @brief    Init DAC7614 IC 
* @return   void
*/
void vdg_drv_dac7614_setup(void)
{
    // SPIの初期化は全体に影響する変更点のためここに隠蔽できない
    // IOピンは占有資源のためここで宣言
    pinMode(PNCF_DAC7614_DACCS, OUTPUT);
     
    /// CSをネゲート
    digitalWrite(PNCF_DAC7614_DACCS, PNCF_DAC7614_DACCS_NEGATE);

    /// LOADDACをネゲート
    digitalWrite(PNCF_DAC7614_LOADDAC, PNCF_DAC7614_LOADDAC_NEGATE);

pinMode(PNCF_DAC7614_LOADDAC, OUTPUT);
}

void vdg_drv_dac7614_start(void)
{
    /* SPI初期化 */
    SPI.begin();
    /* MSB FAST */
    SPI.setBitOrder(MSBFIRST);
    /* 1MHz CLK */
    SPI.setClockDivider(SPI_CLOCK_DIV16);
    /* クロック負パルス 立ち上がりエッジサンプリング */
    SPI.setDataMode(SPI_MODE3);
    
    /// CSをネゲート
    digitalWrite(PNCF_DAC7614_DACCS, PNCF_DAC7614_DACCS_NEGATE);

    /// LOADDACをネゲート
    digitalWrite(PNCF_DAC7614_LOADDAC, PNCF_DAC7614_LOADDAC_NEGATE);

//    SPI.beginTransaction(dac7614SPISetting);
}

/** 
* @fn       void vdg_dac7614_output(u8 ch, u16 outputdat)
* @brief    Init DAC7614 IC 
* @return   void
*/
void vdg_drv_dac7614_output(u8 u8t_ch, u16 u16t_outputdat)
{
    u8  ch_tmp;
    u16  dat_tmp = 0;
    u8  shortdat = 0;
    if (u8t_ch < DRV_DAC7614_CHNUM)
    {
        //  正しいチャンネルのため受け取る
        ch_tmp = u8t_ch;
    }
    else
    {
        //  不正なチャンネル指定のため何もしない
        return ;
    }
    if (DRV_DAC7614_DACMAX < u16t_outputdat)
    {
        dat_tmp  = DRV_DAC7614_DACMAX -1;
    }
    else
    {
        dat_tmp = u16t_outputdat;
    }
    

    // CSアサート
    digitalWrite(PNCF_DAC7614_DACCS, PNCF_DAC7614_DACCS_ASSERT);
    // LOADDACネゲート
    digitalWrite(PNCF_DAC7614_LOADDAC, PNCF_DAC7614_LOADDAC_NEGATE);
    switch(ch_tmp)
    {
        case 0:
            dat_tmp = dat_tmp | 0x0000;
        break;

        case 1:
            dat_tmp = dat_tmp | 0x4000;
        break;

        case 2:
            dat_tmp = dat_tmp | 0x8000;
        break;

        case 3:
            dat_tmp = dat_tmp | 0xC000;
        break;
    }
    shortdat = (dat_tmp >> 8) & 0x00FF;
    SPI.transfer(shortdat);
    shortdat = dat_tmp & 0x00FF;
    SPI.transfer(shortdat);
    //  CSネゲート
    digitalWrite(PNCF_DAC7614_DACCS, PNCF_DAC7614_DACCS_NEGATE);
    //  LOADDACアサート
    digitalWrite(PNCF_DAC7614_LOADDAC, PNCF_DAC7614_LOADDAC_ASSERT);
    // LOADDACネゲート
    digitalWrite(PNCF_DAC7614_LOADDAC, PNCF_DAC7614_LOADDAC_NEGATE);
}

/** 
* @fn       void vdg_drv_dac7614_end(void)
* @brief    Init DAC7614 IC 
* @return   void
*/
void vdg_drv_dac7614_end(void)
{
//    SPI.endTransaction();
    SPI.end();
}

u16 u16g_drv_dac7614_convf(f4 f4t_voltage)
{
    ///    Vdac = DRV_DAC7614_VREF_L + N * ((DRV_DAC7614_VREF_H - DRV_DAC7614_VREF_L) / 4096)
    ///    Vdac - DRV_DAC7614_VREF_L =  N * ((DRV_DAC7614_VREF_H - DRV_DAC7614_VREF_L) / 4096)
    ///    N = (Vdac - DRV_DAC7614_VREF_L) /  ((DRV_DAC7614_VREF_H - DRV_DAC7614_VREF_L) / 4096)
    return  ((f4t_voltage  - DRV_DAC7614_VREF_L) *  DRV_DAC7614_CONV_A * ( 4096 / (DRV_DAC7614_VREF_H - DRV_DAC7614_VREF_L) ) 
                                            + DRV_DAC7614_CONV_B);
}
