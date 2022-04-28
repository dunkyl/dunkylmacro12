// Copyright 2022 dunkyl (@dunkyl)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define VENDOR_ID    0x26E1
#define PRODUCT_ID   0x0001
#define MANUFACTURER Dunkyl
#define PRODUCT      Macro12

#define MATRIX_ROWS 4
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { C6, D4, D0, D1 }
#define MATRIX_COL_PINS { E6, B4, B5 }
// #define UNUSED_PINS { B7, D0 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B6 }

// #define ENCODER_DIRECTION_FLIP

#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

#define RGB_DI_PIN D7
#define RGBLED_NUM 3

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
