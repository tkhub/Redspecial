////////////////////////////////////////////////////////////////////////////////
/// @file           ファイル名.c
/// @brief          ファイルの説明
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


/*****************************************************************************/
/*****************************************************************************/
/*  自ヘッダファイルのインクルード                                            */
#define __GLOBAL_DEFINE__
/*****************************************************************************/
#include "sac_sys.h"

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
/// @var        u16c_sac_sys_pwrtmptbl
/// @brief      温度センサの電圧テーブル。NXFT15XH103FA2B050と10k抵抗と10ビットADを前提
///
////////////////////////////////////////////////////////////////////////////////
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

f4 f4g_sac_sys_agndRead(void)
{
    return analogRead(PNCF_SYS_ADANGND) * 0.00488281;
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

f4 f4g_sac_sys_batvolRead(void)
{
    /// 10k/(20k+10k) * BattVol = Adin
    /// addat = adin / (5/1024)
    /// BattVol = Adin / (10k/(10k+20k))
    /// BattVol = addat * (5/1024) / (10k/(10k+20k))
    /// Battvlo = addat * 0.0146484
    return 0.0146484 * analogRead(PNCF_SYS_ADBATT);
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


