////////////////////////////////////////////////////////////////////////////////
/// @file           sac_ui.h
/// @brief          
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

#ifndef     __SAC_UI_H__
#define     __SAC_UI_H__
#include "typedef_arduino.h"


////////////////////////////////////////////////////////////////////////////////
/// @enum       en_sac_ui_sw
/// @brief      スイッチパターン
///
////////////////////////////////////////////////////////////////////////////////
typedef enum {SW_NON, SW_GO, SW_ESC, SW_UP, SW_DOWN} en_sac_ui_sw;

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


/*****************************************************************************/
/*      グローバル関数・変数の宣言                                             */
/*****************************************************************************/
/** How to USE? **/
/*
__GLOBAL void   vdg_layname_modname_funcname(void)
__GLOBAL u16    u16g_layname_modname_ramname
*/
__GLOBAL    en_sac_ui_sw    eng_sac_ui_sw(void);
__GLOBAL    void            vdg_sac_ui_tone_piroU(void);
__GLOBAL    void            vdg_sac_ui_tone_piroD(void);
__GLOBAL    void            vdg_sac_ui_tone_pi(void);
__GLOBAL    void            vdg_sac_ui_tone_WRN(void);

/** 一度使用した__GLOBAL_DEFINE__は再使用しない **/
#ifdef      __GLOBAL_DEFINE__
#undef      __GLOBAL_DEFINE__
#endif /* __GLOBAL_DEFINE__ */
#undef     __GLOBAL
#endif    /*  __SAC_UI_H__ */
