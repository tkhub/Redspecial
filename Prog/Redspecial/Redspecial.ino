#include <SPI.h>
#include <Wire.h>
#include <MsTimer2.h>
#include <TimerOne.h>
#include "sw.h"
#include "marker.h"

#include "pinconf.h"
#include "drv_dac7614.h"

/********  PIN CONFIG  *****************/
/*  MOSI          SPI           --1 ----1--   SCK     SCK
    NC            RXLED/SS      --2     2--   MISO    MISO
    COM_TX        D1/TX         --3     3--   12V     ----
    COM_RX        D0/RX         --4     4--   GND     ----
    ----          RESET         --5     5--   RESET   ----
    ----          GND           --6     6--   5VOUT   ----
    SDA           D2/SDA        --7     7--   NC
    SCL           D3/SCL        --8     8--   NC
    IR_ADC        D4/A6         --9     9--   A5      SPD_PID_ADC
    DIV_ENPID_DO  D5(PWM)       --10    10--  A4      STR_PID_ADC
    IL_ADC        D6(PWM)/A7    --11    11--  A3      TG_L_ADC
    DIV_ENMTR_DO   D7            --12    12--  A2      TG_R_ADC
    SW_ADC        IO8/A8        --13    13--  A1      SSR_L_ADC
    BATTERY_ADC   IO9(PWM)/A9   --14    14--  A0      SSR_R_ADC
    CS            IO10(PWM)/A10 --15    15--  VREF    ----
    LOADDAC       IO11(PWM)     --16    16--  3.3VOUT ----
    CORNER_MK     IO12/A11      --17----17--  IO13    GOAL_MK
*/
/*****************************************************************************/

#define SW_UP   3
#define SW_DOWN 4
#define SW_GO   1
#define SW_ESC  2 
#define SW_NON  0

volatile const f4 f4c_sac_ctrl_tgtspdGain = -0.394945;

void setupdio()
{
  pinMode(PNCF_UI_GREENLED, OUTPUT);
  pinMode(PNCF_UI_REDLED, OUTPUT);
  pinMode(PNCF_UI_WTLED, OUTPUT);
  pinMode(PNCF_UI_SP, OUTPUT);

  //  peripheral init
  //  GOAL Marker  
  // pinMode(13, INPUT);
  pinMode(PNCF_MAKER_GRMKR, INPUT);
  //  CORNER_MK 
  //pinMode(12, INPUT);  
  pinMode(PNCF_MAKER_CNMKR, INPUT);

  //  CS setup
  //pinMode(10,OUTPUT);
  //pinMode(PNCF_DAC7614_CTRL_STRTRGT, OUTPUT);

  //  LOADDACsetup
  // pinMode(11,OUTPUT);
  //pinMode(PNCF_DAC7614_LOADDAC, OUTPUT);
  vdg_drv_dac7614_setup();

  //pinMode(5, OUTPUT);
  pinMode(PNCF_CTRL_ENPID, OUTPUT);
  
  //pinMode(7, OUTPUT);
  pinMode(PNCF_CTRL_ENMTR, OUTPUT);

  pinMode(PNCF_CTRL_ENIRLED, OUTPUT);
  //  CS Negate
  // digitalWrite(10,HIGH);
  //digitalWrite(PNCF_DAC7614_DACCS, HIGH);
  //  LOADDAC Negate
  //digitalWrite(11,LOW);
  // digitalWrite(PNCF_DAC7614_LOADDAC,LOW);
  // DIV_ENPID_DO   
  dipid();
  // DIV_ENMTR_DO  
  dimtr();


  digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_ON);
  digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_ON);
  digitalWrite(PNCF_UI_WTLED, HIGH);
  digitalWrite(PNCF_CTRL_ENIRLED, PNCF_CTRL_ENIRLED_DI);
}

void setupperipheral()
{
  Serial.begin(38400);
  Serial.print("Serial Init");

  /* SPI初期化 */
  // SPI.begin();
  /* MSB FAST */
  // SPI.setBitOrder(MSBFIRST);
  /* 1MHz CLK */
  // SPI.setClockDivider(SPI_CLOCK_DIV16);
  /* クロック負パルス 立ち上がりエッジサンプリング */
  // SPI.setDataMode(SPI_MODE3);
  // ここではスタートしない
  // vdg_drv_dac7614_start();

  Serial.print("SPI Init");

  MsTimer2::set(1, fastintvlint);
  //Timer1.initialize(500);
  //Timer1.attachInterrupt(fastintvlint);
//  Wire.begin();
}

void setupsoftware()
{
  u16 u16t_dat = u16g_drv_dac7614_convf(2.5);
  vdg_drv_dac7614_start();
  vdg_drv_dac7614_output(PNCF_DAC7614_SPDTRGT, u16t_dat);
  vdg_drv_dac7614_output(PNCF_DAC7614_CTRL_STRTRGT, u16t_dat);
  vdg_drv_dac7614_output(PNCF_DAC7614_CTRL_IL,u16t_dat);
  vdg_drv_dac7614_output(PNCF_DAC7614_CTRL_IR,u16t_dat);
  vdg_drv_dac7614_end();
  Serial.print("DAC OUT 0V");
  
  //lcd.begin();
//  lcd.print("hello!");
  swinit();
  mkrinit();
  Serial.print("Kagura2 Start");


}


void setup()
{
  // put your setup code here, to run once:

  setupdio();
  setupperipheral();
  // Software init
  setupsoftware();
  MsTimer2::start();
  digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_OFF);
  digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_OFF);
  digitalWrite(PNCF_UI_WTLED, LOW);
}




/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/**                        loop                                            ***/
/*****************************************************************************/
/*****************************************************************************/
#define RUN_SQ_INIT       0
#define RUN_SQ_GOWAIT     1
#define RUN_SQ_STARTWAIT  2
#define RUN_SQ_STGTWAIT   3
#define RUN_SQ_GRGTWAIT   4
#define RUN_SQ_SLWWAIT    5
#define RUN_SQ_STPWAIT    6
#define RUN_SQ_STPEND     7
#define TGTSPEED_LEN      3
#define RN_SQ_CNTMAX      10000
#define RN_SQ_CNTMSK      100   // RNSQCNTMSK x 10ms
//#define RN_SQ_CNTMSK      500   // RNSQCNTMSK x 10ms
#define RN_SQ_CNTRSTVAL   10   // x 10ms

byte modesw = SW_NON;
int run_sq = RUN_SQ_INIT;
int timecnt;
int run_spd_md;
u32   intvlcnt = 0;
unsigned long time_tmp;
unsigned long time_tmp2;
float tgtspeed[] ={0.5, 0.75, 1.0, 1.5, 2.0, 2.5};
void loop(){
  // put your main code here, to run repeatedly:
  switch(run_sq)
  {
    case RUN_SQ_INIT:
       mkrreadivnt();
       swreadedge();
       timecnt = 0;
       run_spd_md = 0;
       run_sq = RUN_SQ_GOWAIT;
       digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_OFF);
       digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_OFF);
       digitalWrite(PNCF_UI_WTLED, PNCF_UI_WTLED_ON);
       
    break;
    case RUN_SQ_GOWAIT:
      if(swreadedge() == SW_EDGE_UP)
      {
        modesw = swread();
        if (modesw == SW_UP)
        {
          tone(PNCF_UI_SP, 2000, 100);
          run_spd_md++;
          if ((sizeof(tgtspeed)/sizeof(tgtspeed[0])) <= run_spd_md)
          {
            run_spd_md = sizeof(tgtspeed)/sizeof(tgtspeed[0]) - 1;
          }
          Serial.print(run_spd_md);
          Serial.print(" speed UP\n");
        }
        else if (modesw == SW_DOWN)
        {
          tone(PNCF_UI_SP, 1000, 100);
          run_spd_md--;
          if (run_spd_md < 0);
          {
            run_spd_md == 0;
          } 
          Serial.print(run_spd_md);
          Serial.print(" speed DOWN\n");
        }
        else if (modesw == SW_GO)
        {
          tone(PNCF_UI_SP, 4000, 100);
          run_sq = RUN_SQ_STARTWAIT;
          Serial.print("speed=");
          Serial.print(tgtspeed[run_spd_md]);
          Serial.print(",<GOWAIT -> STARTWAIT>\n");
          mkrreadivnt();
          swreadedge();
          timecnt = 0;
        }
      }
    break;

    case RUN_SQ_STARTWAIT:
      timecnt++;
      if (timecnt % 2)
      {
        digitalWrite(PNCF_UI_GREENLED,PNCF_UI_GREENLED_OFF);
      }
      if ((timecnt % 10) == 0)
      {
        Serial.println(timecnt);
      }
      else
      {
        /* code */
        digitalWrite(PNCF_UI_GREENLED,PNCF_UI_GREENLED_ON);
      }
      if (50 < timecnt)
      {
        digitalWrite(PNCF_CTRL_ENIRLED, PNCF_CTRL_ENIRLED_EN);
      }
      if (100 < timecnt)
      {
        run_sq = RUN_SQ_STGTWAIT;
        tone(PNCF_UI_SP, 4000, 200);
        digitalWrite(PNCF_CTRL_ENIRLED, PNCF_CTRL_ENIRLED_EN);
        digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_OFF);
        digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_OFF);
        vdg_drv_dac7614_start();
        vdg_sac_ctrl_trgtspd_Setf(0.5);
        vdg_drv_dac7614_end();
        enpid();
        enmtr();
        Serial.print(",<STARTWAIT -> STGTWAIT>\n");
        timecnt = 0;
      }
    break;

    case RUN_SQ_STGTWAIT:
      if (mkrreadivnt())
      {
        if (mkrread() == MKR_GR)
        {
          time_tmp = millis();
          vdg_drv_dac7614_start();
          vdg_sac_ctrl_trgtspd_Setf(tgtspeed[run_spd_md]);
          vdg_drv_dac7614_end();
          digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_ON);
          digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_OFF);
          run_sq = RUN_SQ_GRGTWAIT;
          tone(PNCF_UI_SP, 5000, 200);
          Serial.print(",<STGTWAIT -> GRGTWAIT>\n");
          timecnt = 0;
        }
      }
    break;

    case RUN_SQ_GRGTWAIT:
      if (timecnt < RN_SQ_CNTMAX)
      {
        timecnt++;
      }
      if (mkrreadivnt())
      {
        if ((mkrread() == MKR_GR) && 
            ((millis()-time_tmp) > (3000 / (tgtspeed[run_spd_md])) && 
            (millis() - time_tmp2) > (100 / (tgtspeed[run_spd_md]))))
        {
          run_sq = RUN_SQ_SLWWAIT;
          vdg_drv_dac7614_start();
          vdg_sac_ctrl_trgtspd_Setf(0.5);
          vdg_drv_dac7614_end();
          time_tmp = millis();
          tone(PNCF_UI_SP, 4000, 100);
          digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_OFF);
          digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_ON);
          Serial.print(",<GRGTWAIT -> SLWWAIT>\n");
          timecnt = 0;
        }
        else if(mkrread() == MKR_CN || mkrread() == MKR_CRS)
        {
          // 他のイベント
          time_tmp2 = millis();
          timecnt = RN_SQ_CNTMSK - RN_SQ_CNTRSTVAL;
        }
      }
    break;
    
    case RUN_SQ_SLWWAIT:
      if (timecnt < 10000)
      {
        timecnt++;
      }
      if ((millis() - time_tmp) > (250 / (tgtspeed[run_spd_md])))
      {
        run_sq = RUN_SQ_STPWAIT;
        vdg_drv_dac7614_start();
        vdg_sac_ctrl_trgtspd_Setf(0.0);
        vdg_drv_dac7614_end();
        Serial.print(",<SLWWAIT -> STPWAIT>\n");
        digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_OFF);
        digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_ON);
        tone(PNCF_UI_SP, 4000, 100);
        timecnt = 0;
      }
    break;

    case RUN_SQ_STPWAIT:
      if (timecnt < RN_SQ_CNTMAX)
      {
        timecnt++;
      }
      if(10 < timecnt)
      {
        run_sq = RUN_SQ_STPEND;
        dimtr();
        dipid();
        digitalWrite(PNCF_CTRL_ENIRLED, PNCF_CTRL_ENIRLED_DI);
        digitalWrite(PNCF_UI_GREENLED, PNCF_UI_GREENLED_ON);
        digitalWrite(PNCF_UI_REDLED, PNCF_UI_REDLED_ON);
        Serial.print(",<STPWAIT -> END>\n");
        tone(PNCF_UI_SP, 4000, 100);
        delay(100);
        tone(PNCF_UI_SP, 5000, 100);
        delay(100);
        tone(PNCF_UI_SP, 4000, 100);
        delay(100);
        tone(PNCF_UI_SP, 5000, 100);
        timecnt = 0;
      }
    break; 

    case RUN_SQ_STPEND:
      if(swreadedge() == SW_EDGE_UP)
      {
        run_sq = RUN_SQ_INIT;
        Serial.print(",<RETURN to First>\n");
        tone(PNCF_UI_SP, 1000, 300);
        timecnt = 0;
      }

    break;

    default :
      run_sq = RUN_SQ_GOWAIT;
    break;
  }
//  Serial.print(", ");
//  Serial.print(intvlcnt);
//  Serial.print("\n");
 // ioextoutput(mode);
  delay(10);
}
/*

/** 事前にDACのstartは済ませておくこと。endもやらない*/
void vdg_sac_ctrl_trgtspd_Setf(f4 f4t_speed)
{
    f4 f4t_dac;
    f4t_dac = f4t_speed * f4c_sac_ctrl_tgtspdGain + 2.5;
    vdg_drv_dac7614_output(PNCF_DAC7614_SPDTRGT, u16g_drv_dac7614_convf(f4t_dac));
}

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/**                        Intr                                            ***/
/*****************************************************************************/
/*****************************************************************************/

void fastintvlint()
{
  swintr() ;
  mkrintr();
  intvlcnt++;
}
