////////////////////////////////////////////////////////////////////////////////
/// @file           ファイル名
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

#ifndef     __SAC_CTRL_H__
#define     __SAC_CTRL_H__
#include "../comm/typedef_arduino.h"

#define SAC_CTRL_AVGSPD    0
#define SAC_CTRL_LEFTSPD   1
#define SAC_CTRL_RIGHTSPD  2

/**
 * "__GLOBAL_DEFINE__"を定義した場合、externが消える
 * 宣言したいCファイルでのみ"__GLOBAL_DEFINE__"を先に#defineして使用する。
 * その他のファイルでは"__GLOBAL_DEFINE__"をつけないで使う
 *
 */
#ifdef      __GLOBAL_DEFINE__
///     __GLOBALの後ろは空っぽ
#define     __GLOBAL
#else       /* __GLOBAL_DEFINE__ */
///     __GLOBALをexternで置換する
#define     __GLOBAL    extern
#endif      /* __GLOBAL_DEFINE__ */

__GLOBAL void   vdg_sac_ctrl_answpid_EN(void);
__GLOBAL void   vdg_sac_ctrl_answpid_DI(void);
__GLOBAL void   vdg_sac_ctrl_answmtr_EN(void);
__GLOBAL void   vdg_sac_ctrl_answmtr_DI(void);
__GLOBAL void   vdg_sac_ctrl_irldosc_EN(void);
__GLOBAL void   vdg_sac_ctrl_irldosc_DI(void);
__GLOBAL bool   big_sac_ctrl_cnrmkr(void);
__GLOBAL bool   big_sac_ctrl_glmkr(void);
__GLOBAL void   vdg_sac_ctrl_trgtspd_Setf(f4 f4t_speed);
__GLOBAL f4     f4g_sac_ctrl_speedRead(u8 u8t_ch);

/** 一度使用した__GLOBAL_DEFINE__, __GLOBALは再使用しない **/
#ifdef      __GLOBAL_DEFINE__
#undef      __GLOBAL_DEFINE__
#endif /* __GLOBAL_DEFINE__ */
#undef     __GLOBAL
#endif    /*  __SAC_CTRL_H__ */ 
