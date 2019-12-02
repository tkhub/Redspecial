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

#ifndef     __TYPEDEF_ARDUINO_H__
#define     __TYPEDEF_ARDUINO_H__

typedef signed short    s16;
typedef signed char     s8;
typedef float           f4;
typedef double          f8;

#define Cu8       volatile const u8
#define Cs8       volatile const s8
#define Cu16      volatile const u16
#define Cs16      volatile const s16
#define Cf4       volatile const f4
#define Cf8       volatile const f8

#define Vbool   volatile bool
#define Vu8     volatile u8
#define Vu16    volatile u16
#define Vs8     volatile s8
#define Vs16    volatile s16
#define Vf4     volatile f4
#define Vf8     volatile f8


#endif    /*  __TYPEDEF_ARDUINO_H_  */
