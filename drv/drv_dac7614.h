////////////////////////////////////////////////////////////////////////////////
/// @file           drv_dac7614.h
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

#ifndef     __DRV_DAC7614_H__
#define     __DRV_DAC7614_H__
#include    "typedef_arduino.h"

#define DRV_DAC7614_CHNUM   4
#define DRV_DAC7614_DACMIN  0
#define DRV_DAC7614_DACMAX  4096
#define DRV_DAC7614_VREF_H  5.0
#define DRV_DAC7614_VREF_L  0.0
#define DRV_DAC7614_CONV_A  1.1749
#define DRV_DAC7614_CONV_B  0.0

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

__GLOBAL    void    vdg_drv_dac7614_setup(void);
__GLOBAL    void    vdg_drv_dac7614_start(void);
__GLOBAL    void    vdg_drv_dac7614_output(u8 u8t_ch, u16 u16t_outputdat);
__GLOBAL    void    vdg_drv_dac7614_end(void);
__GLOBAL    u16     u16g_drv_dac7614_convf(f4 f4t_voltage);

/** 一度使用した__GLOBAL_DEFINE__は再使用しない **/
#ifdef      __GLOBAL_DEFINE__
#undef      __GLOBAL_DEFINE__
#endif /* __GLOBAL_DEFINE__ */
#undef     __GLOBAL

#endif    /*  __DRV_DAC7614_H__ */ 
