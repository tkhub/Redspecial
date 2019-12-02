#include <Arduino.h>
#include "pinconf.h"
#include "typedef_arduino.h"
#include "drv_dac7614.h"
#include "drv_mcp320x.h"

#define __GLOBAL_DEFINE__
#include "sac_ctrl.h"


Cf4 f4c_sac_ctrl_tgtspdGain = -0.394945;

void   vdg_sac_ctrl_answpid_EN(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_EN);
}

void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_DI(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_DI);
}

void   vdg_sac_ctrl_irldosc_EN(void)
{
    digitalWrite(PNCF_CTRL_ENIRLED,PNCF_CTRL_ENIRLED_EN);
}

void   vdg_sac_ctrl_irldosc_DI(void)
{
    digitalWrite(PNCF_CTRL_ENIRLED,PNCF_CTRL_ENIRLED_EN);
}

bool   big_sac_ctrl_cnrmkr(void)
{
    if (digitalRead(PNCF_MAKER_CNMKR) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool   big_sac_ctrl_glmkr(void)
{
    if (digitalRead(PNCF_MAKER_GRMKR))
    {
        return true;
    }
    else
    {
        /* code */
        return false;
    }
}

/** 事前にDACのstartは済ませておくこと。endもやらない*/
void vdg_sac_ctrl_trgtspd_Setf(f4 f4t_speed)
{
    f4 f4t_dac;
    f4t_dac = f4t_speed * f4c_sac_ctrl_tgtspdGain + 2.5;
    vdg_drv_dac7614_output(PNCF_DAC7614_SPDTRGT, u16g_drv_dac7614_convf(f4t_dac));
}

f4 f4g_sac_ctrl_speedRead(u8 u8t_ch)
{

}
