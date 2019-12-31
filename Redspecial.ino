#include "boot.h"
#include "drv/drv_dac7614.h"
#include "drv/pinconf.h"


void setup()
{
// put your setup code here, to run once:
//    vdg_sys_boot_basicInit();
//  vdg_sys_boot_basicInit();
//    vdg_sys_boot_basicInit();

//vdg_sys_boot_mainInit();
    //vdg_drv_dac7614_setup();
    vdg_sys_boot_basicInit();
}

void loop()
{
    digitalWrite(PNCF_CTRL_ENIRLED, HIGH);
    delay(100);
    digitalWrite(PNCF_CTRL_ENIRLED, LOW);
    delay(100);
}
