////////////////////////////////////////////////////////////////////////////////
/// @file           sac_ctrl.c
/// @brief          制御系の隠蔽層
/// @author         作成者
/// @date           ファイル作成年月日
/// $Version:       ファイルバージョン$
/// $Revision:      ファイルリビジョン$
/// @note           ファイルに備考などを明記する場合はここへ書き込む
/// @attention      ファイルに注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
/// Copyright (c) YYYY Sample Inc. All Rights reserved.
///
/// - 本ソフトウェアの一部又は全てを無断で複写複製（コピー）することは、
///   著作権侵害にあたりますので、これを禁止します。
/// - 本製品の使用に起因する侵害または特許権その他権利の侵害に関しては
///   当社は一切その責任を負いません。
///
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*****************************************************************************/
/*  ヘッダファイルのインクルード                                              */
/*****************************************************************************/
/*****************************************************************************/
#include <Arduino.h>
#include "../drv/pinconf.h"
#include "../comm/typedef_arduino.h"
#include "../drv/drv_dac7614.h"
#include "../drv/drv_mcp320x.h"

/*****************************************************************************/
/*****************************************************************************/
/*  自ヘッダファイルのインクルード                                            */
#define __GLOBAL_DEFINE__
/*****************************************************************************/
#include "sac_ctrl.h"


/*****************************************************************************/
/*****************************************************************************/
/* 型定義                                                                    */
/*****************************************************************************/
/*****************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @typedef    typedef名
/// @brief      typedefの説明
///
////////////////////////////////////////////////////////////////////////////////



/*****************************************************************************/
/*****************************************************************************/
/* マクロ */
/*****************************************************************************/
/*****************************************************************************/
/////////////////////////////////////////////////////////////////////////////////
/// @def        define名
/// @brief      defineの説明
///
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*****************************************************************************/
/* クラス */
/*****************************************************************************/
/*****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// @class      class名
/// @brief      classの説明
///
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @struct     構造体名
/// @brief      構造体の説明
///
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
/// @enum       enum型名
/// @brief      enum型の説明
///
////////////////////////////////////////////////////////////////////////////////

/*****************************************************************************/
/*****************************************************************************/
/* 変数定義 */
/*****************************************************************************/
/*****************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @var        変数名
/// @brief      変数の説明
///
////////////////////////////////////////////////////////////////////////////////
Cf4 f4c_sac_ctrl_tgtspdGain = -0.394945;

/*****************************************************************************/
/*****************************************************************************/
/* 内部関数宣言 */
/*****************************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/* 関数定義 */
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/

/*****************************************************************************/
/*****************************************************************************/
/* グローバル関数定義 */
/*****************************************************************************/
/*****************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void vdg_sac_ctrl_setup(void)
{
    pinMode(PNCF_CTRL_ENMTR, OUTPUT);
    pinMode(PNCF_CTRL_ENPID, OUTPUT);
    pinMode(PNCF_CTRL_ENIRLED, OUTPUT);

    vdg_sac_ctrl_answmtr_DI();
    vdg_sac_ctrl_answpid_DI();
    vdg_sac_ctrl_irldosc_DI();
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_EN(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_EN);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////
void   vdg_sac_ctrl_answpid_DI(void)
{
    digitalWrite(PNCF_CTRL_ENPID, PNCF_CTRL_ENPID_DI);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
}

void   vdg_sac_ctrl_answmtr_EN(void)
{
    digitalWrite(PNCF_CTRL_ENMTR, PNCF_CTRL_ENMTR_EN);
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
/*****************************************************************************/
/*****************************************************************************/
/* 内部関数定義 */
/*****************************************************************************/
/*****************************************************************************/

////////////////////////////////////////////////////////////////////////////////
/// @brief          関数の説明
/// @fn             関数名
/// @param[in]      引数(参照専用)
/// @param[out]     引数(ポインタ引数等)
/// @return         関数戻り値の説明
/// @author         関数作成者名
/// @date           関数作成年月日
/// @version        関数やソースにバージョンを明記する場合はここへ書き込む
/// @note           関数に備考などを明記する場合はここへ書き込む
/// @attention      関数に注意書きなどを明記する場合はここへ書き込む
/// @par            History
///                 ファイルに履歴などを明記する場合はここへ書き込む
///
////////////////////////////////////////////////////////////////////////////////

/*********************EOF******************************************************/



