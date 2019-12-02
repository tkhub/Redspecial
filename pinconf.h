/*****************************************************************************/
/*                  kagura3.0 Redspecial(v201910) 用ピン設定                  */
/*****************************************************************************/
#ifndef _PINCONF_H_
#define _PINCONF_H_


/**
 *  マイコンピン設定
 */
/********  PIN CONFIG  ********************************************************/
/*  MOSI          SPI           --1 ----1--   SCK     SCK
    NC            RXLED/SS      --2     2--   MISO    MISO
    COM_TX        D1/TX         --3     3--   12V     ----
    COM_RX        D0/RX         --4     4--   GND     ----
    ----          RESET         --5     5--   RESET   ----
    ----          GND           --6     6--   5VOUT   ----
    SDA           D2/SDA        --7     7--   NC
    SCL           D3/SCL        --8     8--   NC
    GREEN_LED     D4/A6         --9     9--   A5/19      SPI_ADC_CS
    RED_LED       D5(PWM)       --10    10--  A4/18      SPI_DAC_CS
    SETDAC        D6(PWM)/A7    --11    11--  A3/17      AD_SW
  X CNMKR         D7            --12    12--  A2/16      AD_AGND
    GRMKR         IO8/A8        --13    13--  A1/15      AD_TEMP
  X EN_PID        IO9(PWM)/A9   --14    14--  A0/14      AD_BATT
  X EN_MTR        IO10(PWM)/A10 --15    15--  VREF    ----
    SP            IO11(PWM)     --16    16--  3.3VOUT ----
  X EN_LED        IO12/A11      --17----17--  IO13    LED
*/
/*****************************************************************************/

//  pin 1-1
//  MOSI

//  pin 1-2
//  NC

//  pin 1-3
//  COM_TX

//  pin 1-4
//  COM_RX

//  pin 1-5
//  RESET

//  pin 1-6
//  RESET

//  pin 1-7
//  SDA

//  pin 1-8
//  SDL

//  pin 1-9
#define     PNCF_UI_GREENLED        4
#define     PNCF_UI_GREENLED_ON     HIGH
#define     PNCF_UI_GREENLED_OFF    LOW

//  pin 1-10
#define     PNCF_UI_REDLED          5
#define     PNCF_UI_REDLED_ON       HIGH
#define     PNCF_UI_REDLED_OFF      LOW

//  pin 1-11
#define     PNCF_DAC7614_LOADDAC        6
#define     PNCF_DAC7614_LOADDAC_ASSERT LOW
#define     PNCF_DAC7614_LOADDAC_NEGATE HIGH

//  pin 1-12
//#define     PNCF_MAKER_CNMKR        7
//#define     PNCF_MAKER_CNMKR_ON     LOW
//#define     PNCF_MAKER_CNMKR_OFF    HIGH
#define     PNCF_CTRL_ENIRLED       7
#define     PNCF_CTRL_ENIRLED_EN    HIGH
#define     PNCF_CTRL_ENIRLED_DI    LOW
#
//  pin 1-13
#define     PNCF_MAKER_GRMKR        8
#define     PNCF_MAKER_GRMKR_ON     LOW
#define     PNCF_MAKER_GRMKR_OFF    HIGH

//  pin 1-14
//#define     PNCF_CTRL_ENPID         9
//#define     PNCF_CTRL_ENPID_EN      HIGH
//#define     PNCF_CTRL_ENPID_DI      LOW
#define     PNCF_MAKER_CNMKR        9
#define     PNCF_MAKER_CNMKR_ON     LOW
#define     PNCF_MAKER_CNMKR_OFF    HIGH

//  pin 1-15
//#define     PNCF_CTRL_ENMTR         10
//#define     PNCF_CTRL_ENMTR_EN      HIGH 
//#define     PNCF_CTRL_ENMTR_DI      LOW
#define     PNCF_CTRL_ENPID         10
#define     PNCF_CTRL_ENPID_EN      HIGH
#define     PNCF_CTRL_ENPID_DI      LOW

//  pin 1-16
#define     PNCF_UI_SP              11

//  pin 1-17
//#define     PNCF_CTRL_ENIRLED       12
//#define     PNCF_CTRL_ENIRLED_EN    HIGH
//#define     PNCF_CTRL_ENIRLED_DI    LOW
#define     PNCF_CTRL_ENMTR         12
#define     PNCF_CTRL_ENMTR_EN      HIGH 
#define     PNCF_CTRL_ENMTR_DI      LOW

//  pin 2-1
//  SCK

//  pin 2-2
//  MISO

//  pin 2-3
//  12V

//  pin 2-4
//  GND

//  pin 2-5
//  RESET

//  pin 2-6
//  5VOUT

//  pin 2-7
//  NC

//  pin 2-8
//  NC

//  pin 2-9
#define     PNCF_MCP320X_ADCCS          A5
#define     PNCF_MCP320X_ADCCS_ASSERT   LOW
#define     PNCF_MCP320X_ADCCS_NEGATE   HIGH

//  pin 2-10
#define     PNCF_DAC7614_DACCS          A4
#define     PNCF_DAC7614_DACCS_ASSERT   LOW
#define     PNCF_DAC7614_DACCS_NEGATE   HIGH

//  pin 2-11
#define     PNCF_UI_ADSW            A3

//  pin 2-12
#define     PNCF_SYS_ADANGND        A2

//  pin 2-13
#define     PNCF_SYS_ADTEMP         A1

//  pin 2-14
#define     PNCF_SYS_ADBATT         A0

//  pin 2-15
//  VREF

//  pin 2-16
//  VREF

//  pin 2-17
#define     PNCF_UI_WTLED           13
#define     PNCF_UI_WTLED_ON        HIGH
#define     PNCF_UI_WTLED_OFF       HIGH

/*********** MCP3208 PIN ID *****/
#define     PNCF_MCP3208_SSR_FLINV      0
#define     PNCF_MCP3208_SSR_RL         1
#define     PNCF_MCP3208_SSR_RRINV      2
#define     PNCF_MCP3208_SSR_FR         3
#define     PNCF_MCP3208_YPID_CCW       4
#define     PNCF_MCP3208_APID_ACT       5
#define     PNCF_MCP3208_TG_R_BK        6
#define     PNCF_MCP3208_TG_L_BK        7

/*********** MCP3208 PIN ID *****/
#define     PNCF_DAC7614_SPDTRGT            0
#define     PNCF_DAC7614_CTRL_IR            1
#define     PNCF_DAC7614_CTRL_IL            2
#define     PNCF_DAC7614_CTRL_STRTRGT  3

#endif

