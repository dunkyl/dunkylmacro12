#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_4x3(
        KC_F13,   KC_F14,   KC_F15,
        KC_F16,   KC_F17,   KC_F18,
        KC_F19,   KC_F20,   KC_F21,
        KC_F22,   KC_F23,   KC_F24
    )
};

bool encoder_update_user(uint8_t /* encoder index for multiple encoders */ index, bool clockwise) {
    if (index == 0) {
        // uint8_t key = clockwise ? KC_VOLU : KC_VOLD;
        // tap_code(key);
        if (clockwise) {
            rgblight_increase_hue();
        } else {
            rgblight_decrease_hue();
        }
    }
    #ifdef CONSOLE_ENABLE
        uprintf("encoder %u %s\n", index, clockwise ? "CW" : "CCW");
    #endif
    return false;
}
