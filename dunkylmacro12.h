#include "quantum.h"

// clang-format off

// layout with all the switches supported by the PCB
#define LAYOUT_4x3_sw( \
	K00, K01, K02, \
    K10, K11, K12, \
    K20, K21, K22, \
    K30, K31, K32, \
    KSW \
) { \
	{ K00,   K01,   K02,   KC_NO }, \
    { K10,   K11,   K12,   KC_NO }, \
    { K20,   K21,   K22,   KC_NO }, \
    { K30,   K31,   K32,   KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KSW} \
}
