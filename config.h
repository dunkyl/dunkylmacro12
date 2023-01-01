// Copyright 2022 dunkyl (@dunkyl)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define VENDOR_ID    0x26E1
#define PRODUCT_ID   0x0001
#define MANUFACTURER Dunkyl
#define PRODUCT      Macro12

#define MATRIX_ROWS 5
#define MATRIX_COLS 4

#define MATRIX_ROW_PINS { C6, D4, D0, D1, B7 }
#define MATRIX_COL_PINS { E6, B4, B5, D5 }
// #define UNUSED_PINS { B7, D0 }

#define DIODE_DIRECTION COL2ROW

// #define ENCODERS_PAD_A { B2 }
// #define ENCODERS_PAD_B { B6 }
#define ENCODERS_PAD_A { D2 }
#define ENCODERS_PAD_B { D3 }

// #define ENCODER_DIRECTION_FLIP

#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

#define RGB_DI_PIN D7

#ifdef RGBLIGHT_NUM
#undef RGBLIGHT_NUM
#endif //RGBLIGHT_NUM

#define RGBLED_NUM 12

#define RGBLIGHT_MODE_SNAKE 0

#define WS2812_TRST_US 100
#define WS2812_TIMING 1250
#define WS2812_T0H 350
#define WS2812_T1H 650

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
