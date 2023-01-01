#include QMK_KEYBOARD_H
// #include "dunkylmacro12.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─────┬─────┬─────┐
     * │ F13 │ F14 │ F15 │
     * ├─────┼─────┼─────┤
     * │ F16 │ F17 │ F18 │
     * ├─────┼─────┼─────┤
     * │ F19 │ F20 │ F21 │
     * ├─────┼─────┼─────┤
     * │ F22 │ F23 │ F24 │
     * └─────┴─────┴─────┘
     */
    [0] = LAYOUT_4x3_sw(
        KC_F13,   KC_F14,   KC_F15,
        KC_F16,   KC_F17,   KC_F18,
        KC_F19,   KC_F20,   KC_F21,
        KC_F22,   KC_F23,   KC_F24,
        KC_MEDIA_PLAY_PAUSE
    )
};

int led_i_ = 0;

bool encoder_update_user(uint8_t /* encoder index for multiple encoders */ index, bool clockwise) {
    if (index == 0) {
        // uint8_t key = clockwise ? KC_VOLU : KC_VOLD;
        uint8_t key = clockwise ? KC_DOT : KC_COMMA;
        tap_code(key);
        // rgblight_setrgb_at(0, 0, 0, led_i_);
        // if (clockwise) {
        //     led_i_ = (led_i_ + 1) % 12;
        // } else {
        //     if (led_i_ == 0) {
        //         led_i_ = 12;
        //     }
        //     led_i_ = (led_i_ - 1) % 12;
        // }
        // rgblight_setrgb_at(255, 0, 0, led_i_);
    }
    #ifdef CONSOLE_ENABLE
        uprintf("encoder %u %s\n", led_i_, clockwise ? "CW" : "CCW");
    #endif
    return false;
}

uint16_t led_fade_time = 255;
uint16_t led_fade[4][3] = {0};
uint8_t led_colors[4][3][3] = {
    {{RGB_GREEN}, {RGB_BLUE}, {RGB_RED}},
    {{RGB_AZURE}, {RGB_AZURE}, {RGB_AZURE}},
    {{RGB_GOLDENROD}, {RGB_GOLDENROD}, {RGB_GOLDENROD}},
    {{RGB_CORAL}, {RGB_CORAL}, {RGB_CORAL}}
};
uint8_t led_index[4][3] = {
    {0, 1, 2},
    {5, 4, 3},
    {6, 7, 8},
    {11, 10, 9}
};
// uint8_t led_is_active[4][3] = {
//     {0, 0, 0},
//     {0, 0, 0},
//     {0, 0, 0},
//     {0, 0, 0}
// };

#define kc_to_led_fade(kc, x, y) \
    case kc: \
        led_fade[y][x] = 255; \
        led_fade_time = 255; \
        return true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    rgblight_set();
    #ifdef CONSOLE_ENABLE
        uprintf("keycode %u \n", keycode);
    #endif
    switch (keycode) {
        kc_to_led_fade(KC_F13, 0, 0)
        kc_to_led_fade(KC_F14, 1, 0)
        kc_to_led_fade(KC_F15, 2, 0)
        kc_to_led_fade(KC_F16, 0, 1)
        kc_to_led_fade(KC_F17, 1, 1)
        kc_to_led_fade(KC_F18, 2, 1)
        kc_to_led_fade(KC_F19, 0, 2)
        kc_to_led_fade(KC_F20, 1, 2)
        kc_to_led_fade(KC_F21, 2, 2)
        kc_to_led_fade(KC_F22, 0, 3)
        kc_to_led_fade(KC_F23, 1, 3)
        kc_to_led_fade(KC_F24, 2, 3)

        default:
            return true; // Process all other keycodes normally
    }

    return true;
}

void matrix_scan_user() {
    if (led_fade_time > 0) {
        --led_fade_time;
        // #ifdef CONSOLE_ENABLE
        //     uprintf("led_fade_time %u \n", led_fade_time);
        // #endif
        // if (led_fade_time % 2 == 0) {
            for (uint8_t y = 0; y < 4; ++y) {
                for (uint8_t x = 0; x < 3; ++x) {
                    if (led_fade[y][x] > 10) {
                        --led_fade[y][x];
                        uint8_t power_r = (led_fade[y][x] * led_colors[y][x][0]) / 255;
                        uint8_t power_g = (led_fade[y][x] * led_colors[y][x][1]) / 255;
                        uint8_t power_b = (led_fade[y][x] * led_colors[y][x][2]) / 255;
                        setrgb(power_r, power_g, power_b, (LED_TYPE *)&led[led_index[y][x]]);

                        // #ifdef CONSOLE_ENABLE
                        //     uprintf("led %u : %u %u %u \n", led_index[y][x], power_r, power_g, power_b);
                        // #endif
                    }
                }
                // rgblight_set();
            }
        // }

        rgblight_set();
    }
}

void keyboard_post_init_user() {
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 3; ++x) {

            led_fade[y][x] = 255;
            setrgb(led_colors[y][x][0], led_colors[y][x][1], led_colors[y][x][2], (LED_TYPE *)&led[led_index[y][x]]);
        }
    }
    rgblight_set();

}
