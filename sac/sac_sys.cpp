#include <Arduino.h>
#include "pinconf.h"
#include "typedef_arduino.h"

#define __GLOBAL_DEFINE__
#include "sac_sys.h"


Cu16 u16c_sac_sys_pwrtmptbl[] = 
{
    930, // -25
    904, // -20
    873, // -15
    839, // -10
    799, // -5
    756, // 0
    710, // 5
    661, // 10
    612, // 15
    561, // 20
    512, // 25
    464, // 30
    419, // 35
    376, // 40
    337, // 45
    300, // 50
    267, // 60
    238, // 65
    212, // 70
    189, // 75
    168, // 80
    149, // 85
    133, // 90
    106, // 95
    95,  // 100
    1   // over flow
};

Cu16 u16c_sac_sys_btryemty_TH =  663;
Cu16 u16c_sac_sys_btrylow_TH =  714;
Cu16 u16c_sac_sys_btrymid_TH =  775;
Cu16 u16c_sac_sys_btryfll_TH =  812;
Cu16 u16c_sac_sys_btryovr_TH =  925;

f4 f4g_sac_sys_agndRead(void)
{
    return analogRead(PNCF_SYS_ADANGND) * 0.00488281;
}


f4 f4g_sac_sys_batvolRead(void)
{
    /// 10k/(20k+10k) * BattVol = Adin
    /// addat = adin / (5/1024)
    /// BattVol = Adin / (10k/(10k+20k))
    /// BattVol = addat * (5/1024) / (10k/(10k+20k))
    /// Battvlo = addat * 0.0146484
    return 0.0146484 * analogRead(PNCF_SYS_ADBATT);
}

s16 s16g_sac_sys_pwrtempRead(void)
{
    u8 u8t_tblsize = (sizeof(u16c_sac_sys_pwrtmptbl)/sizeof(u16c_sac_sys_pwrtmptbl[0]));
    u8 cnt;
    u16 u16t_tempad = analogRead(PNCF_SYS_ADTEMP);
    for (cnt = 0; cnt < u8t_tblsize && (u16t_tempad < u16c_sac_sys_pwrtmptbl[cnt]) ; cnt++)
    { /* LOOP */  }

    return 5 * cnt  - 25;
}

en_sac_sys_btryst eng_sac_sys_btrychk(void)
{
    u16 u16t_batad = analogRead(PNCF_SYS_ADBATT);

    if (u16t_batad < u16c_sac_sys_btryemty_TH)
    {
        return EMPTYVOLTAGE;
    }
    else if (u16t_batad < u16c_sac_sys_btrylow_TH)
    {
        return LOWVOLTAGE;
    }
    else if (u16t_batad < u16c_sac_sys_btrymid_TH)
    {
        return MIDVOLTAGE;
    }
    else if (u16t_batad < u16c_sac_sys_btryfll_TH)
    {
        return FULLVOLTAGE;
    }
    else
    {
        return OVERVOLTAGE;
    }
    
}
