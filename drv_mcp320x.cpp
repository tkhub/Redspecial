#include <SPI.h>
#include "pinconf.h"
#include "typedef_arduino.h"

#define __GLOBAL_DEFINE__
#include "drv_mcp320x.h"

   
u8 u8s_drv_mcp320x_chnum;

SPISettings settings(1000000, MSBFIRST, SPI_MODE0);

/** 
* @fn       void vdg_dac7614_setup(u8 ch)
* @brief    Init MCP320x IC 
* @return   void
*/
void    vdg_drv_mcp320x_setup(u8 u8t_ch)
{
    // SPIの初期化は全体に影響する変更点のためここに隠蔽できない
    // IOピンは占有資源のためここで宣言
    pinMode(PNCF_MCP320X_ADCCS, OUTPUT);
    if (u8t_ch == DRV_MCP3204_CH)
    {
        u8s_drv_mcp320x_chnum = DRV_MCP3204_CH;
    }
    else
    {
        u8s_drv_mcp320x_chnum = DRV_MCP3208_CH;
    }
    /// CSネゲート
    digitalWrite(PNCF_MCP320X_ADCCS, PNCF_MCP320X_ADCCS_NEGATE);
}

void vdg_drv_mcp320x_start(void)
{
    /* SPI初期化 */
    SPI.begin();
    /* MSB FAST */
    SPI.setBitOrder(MSBFIRST);
    /* 1MHz CLK */
    SPI.setClockDivider(SPI_CLOCK_DIV16);
    /* クロック正パルス 立ち上がりエッジサンプリング */
    SPI.setDataMode(SPI_MODE0);
    /// CSネゲート
    digitalWrite(PNCF_MCP320X_ADCCS, PNCF_MCP320X_ADCCS_NEGATE);
}

/**
 * @fn      u
 * 
 * 
 */
u16 u16g_drv_mcp320x_sinput(u8 u8t_ch)
{
   u8 ch_tmp;
   u8 senddat = 0x00;
   u8 rcvdatl = 0x00;
   u8 rcvdath = 0x00;
   u16 rcvdat = 0x0000;

   if (u8t_ch < u8s_drv_mcp320x_chnum ) {
       //  ただしいチャンネルなので受け取る
       ch_tmp = u8t_ch;
   }
   else
   {
       return 0;
   }
   /*
       MCP320xの仕様
       byte0 = 00000 + 1 + 1 + D2
       byte1 = D1 + D0 + 000000
       byte2 = 0x00
   */
   /// CSアサート
   digitalWrite(PNCF_MCP320X_ADCCS, PNCF_MCP320X_ADCCS_ASSERT);
   ///  0000 0XXX & (0000 0110 | (0000 0001 & (0000 0321 >> 2) )
   ///  0000 0XXX & (0000 0110 | (0000 0001 & (0000 0003) )
   ///  0000 0113
   senddat = 0x07 & (0x06 | (0x01 & (ch_tmp >> 2)));
   SPI.transfer(senddat);

   /// (0000 0321 << 6) & 1100 0000 
   /// (2100 0000) & 1100 0000 
   senddat = (ch_tmp << 6) & 0xC0;
   rcvdath  =  SPI.transfer(senddat);
   rcvdatl  =  SPI.transfer(0x00);
   /// CSネゲート
   digitalWrite(PNCF_MCP320X_ADCCS, PNCF_MCP320X_ADCCS_NEGATE);
   ///  (0000 0000  000N BA98  << 8) & 0x0
   ///  (000N BA98  0000 0000 & 0x0F00
   rcvdat = ((u16)rcvdath << 8) & 0x0F00;
   rcvdat = rcvdat | rcvdatl;
   return rcvdat;
}



short s16g_drv_mcp320x_dinput(u8 ch)
{
    return -1;
}


void    vdg_drv_mcp320x_end(void)
{
    SPI.end();
}


f4 f4g_drv_mcp320x_sconvf(u16 u16t_adcdat)
{
    return (u16t_adcdat) * (DRV_MCP320x_VREF / DRV_MCP320x_MAXDAT) * DRV_MCP320x_CONV_A + DRV_MCP320x_CONV_B;
}
