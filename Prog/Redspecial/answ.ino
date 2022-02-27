/*****************************************************************************/
#include "pinconf.h"
void enpid(void)
{
    // digitalWrite(5,LOW);
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_EN);
}

void dipid(void)
{
    // digitalWrite(5,HIGH);
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

void enmtr(void)
{
//    digitalWrite(7,LOW);
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void dimtr(void)
{
    // digitalWrite(7,HIGH);
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_DI);
}