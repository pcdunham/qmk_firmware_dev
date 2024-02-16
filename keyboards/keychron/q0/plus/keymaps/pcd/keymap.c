/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "macros.h"

// clang-format off

enum layers {
    BASE,
    FUNC,
    L2,
    L3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Base Layer

    [BASE] = LAYOUT_numpad_6x5(
        TO(FUNC),  KC_MUTE,  KC_ESC,  KC_BSPC,  KC_TAB,
        WINTERM,   KC_NUM,   KC_PSLS, KC_PAST,  KC_PMNS,
        MACRO02,   KC_P7,    KC_P8,   KC_P9,    KC_PPLS,
        MACRO03,   KC_P4,    KC_P5,   KC_P6,
        MACRO04,   KC_P1,    KC_P2,   KC_P3,    KC_PENT,
        EMAIL,     KC_P0,             KC_PDOT),

    // Function Layer

    [FUNC] = LAYOUT_numpad_6x5(
        TO(L2),    KC_MUTE, KC_VOLD,  KC_VOLU,  _______,
        MACRO01,   RGB_MOD,  RGB_VAI, RGB_HUI,  KC_DEL,
        MACRO02,   RGB_RMOD, RGB_VAD, RGB_HUD,  _______,
        MACRO03,   RGB_SAI,  RGB_SPI, _______,
        MACRO04,   RGB_SAD,  RGB_SPD, _______,  _______,
        EMAIL,     _______,           _______),

    // Mouse Key Mod Layer

    [L2] = LAYOUT_numpad_6x5(
        TO(L3),              LCTL(KC_BTN1), LCTL(KC_BTN3), LCTL(KC_BTN2), _______,
        LCTL(LSFT(KC_BTN1)), LSFT(KC_BTN1), LSFT(KC_BTN3), LSFT(KC_BTN2), _______,
        LCTL(LSFT(KC_BTN2)), KC_BTN1,       KC_BTN3,       KC_BTN2,       _______,
        LCA(KC_BTN1),        LALT(KC_BTN1), LALT(KC_BTN3), LALT(KC_BTN2),
        LCA(KC_BTN2),        LSA(KC_BTN1),  LSA(KC_BTN3),  LSA(KC_BTN2),  _______,
        _______,             _______,                      _______),

    // Mouse Key Layer

    [L3] = LAYOUT_numpad_6x5(
        TO(BASE),  _______,  _______,  _______, _______,
        _______,   _______,  _______,  _______,  KC_ACL0,
        _______,   KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_ACL1,
        _______,   KC_MS_L,  KC_BTN3,  KC_MS_R,
        _______,   _______,  KC_MS_D,  _______,  KC_ACL2,
        _______,   _______,            _______),

};

    /*  // Base layer default keymap
        KC_MUTE,   MO(FUNC), KC_ESC,  KC_BSPC,  KC_TAB,
        MACRO01,   KC_NUM,   KC_PSLS, KC_PAST,  KC_PMNS,
        MACRO02,   KC_P7,    KC_P8,   KC_P9,    KC_PPLS,
        MACRO03,   KC_P4,    KC_P5,   KC_P6,
        MACRO04,   KC_P1,    KC_P2,   KC_P3,    KC_PENT,
        MACRO05,   KC_P0,             KC_PDOT),
        // Key Matrix to LED Index
        __,        0,        1,       2,        3,
        4,         5,        6,       7,        8,
        9,         10,       11,      12,       13,
        4,         15,       16,      17,       __,
        18,        19,       20,      21,       22,
        23,        24,       __,      25,       __,
    */


bool rgb_matrix_indicators_user(void) {

    // keyboard LED code

    switch(get_highest_layer(layer_state)) {

        // Set specified keys to colors depending on which layer is selected
        case BASE:  //Layer 0
            rgb_matrix_set_color(24, 255, 255, 255);
            break;
        case FUNC:
            rgb_matrix_set_color(19, 255, 255, 255);
            break;
        case L2:  //layer 2
            rgb_matrix_set_color(20, 255, 255, 255);
            break;
        case L3:  //layer 3
            rgb_matrix_set_color(21, 255, 255, 255);
            break;
        default:
            break;
    }
    return false;
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FUNC] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [L2] = { ENCODER_CCW_CW(_______, _______) },
    [L3] = { ENCODER_CCW_CW(_______, _______) }
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
};
