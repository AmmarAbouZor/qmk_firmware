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

// Remove the defines down here if this should be used
// #include "keychron_common.h"

// clang-format off


enum layers{
    BASE,
    FN,
    SYMBOL,
    NAV
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  LT(NAV,KC_BSPC), LALT_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, LCTL_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LALT_T(KC_SCLN),  KC_QUOT, LT(NAV,KC_ENT), KC_HOME,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(FN),    LT(NAV,KC_SPC),                   LT(SYMBOL,KC_BSPC),   KC_RALT,  MO(FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FN] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [SYMBOL] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        _______,  _______,  KC_TILDE,   KC_AT,  KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,    _______,  _______,            _______,
        _______,  KC_CAPS, KC_EXCLAIM, KC_MINS, KC_PLUS,    KC_EQL,   KC_LCBR, KC_RCBR,  KC_UNDS,  KC_PIPE,  KC_LBRC,  KC_RBRC,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  KC_LALT,  KC_LCTL,  KC_LT,  KC_GT,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [NAV] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        _______,  _______,  _______,     KC_7,     KC_8,    KC_9,  _______,   _______,  KC_HOME,  KC_END,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  LALT_T(KC_0),  LGUI_T(KC_4),  LSFT_T(KC_5),  LCTL_T(KC_6),  _______,   KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_END,  _______,              _______,            _______,
        _______,  _______,            _______,     KC_1,    KC_2,     KC_3,   _______,  _______,  KC_PGDN,  KC_PGUP,  _______,   _______,             _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [SYMBOL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NAV]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE


// **************************************************
// My changes
// this is copied from keychron layout.
// TODO: check if I can delete this.
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//         if (!process_record_keychron(keycode, record)) {
//         return false;
//     }
//     return true;
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // QUICK_TAP_TERM can't be greater than tapping term, which affect vim movement
        // If this is ever solved I work better with less TAPPING_TERM with my index and middle fingers
        //
        // case LSFT_T(KC_D):
        // case LCTL_T(KC_F):
        // case LCTL_T(KC_J):
        // case LSFT_T(KC_K):
        //     return TAPPING_TERM - 10;
        case LALT_T(KC_A):
        case LALT_T(KC_SCLN):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}

// Permissive Hold for index and middle finger in homerow
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_D):
        case LCTL_T(KC_D):
        case LSFT_T(KC_F):
        case LCTL_T(KC_F):
        case LSFT_T(KC_J):
        case LCTL_T(KC_J):
        case LSFT_T(KC_K):
        case LCTL_T(KC_K):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

// Hold On Other Key Press for Caps-Lock and Enter and the second backspace
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NAV,KC_BSPC):
        case LT(NAV,KC_ENT):
        case LT(SYMBOL,KC_BSPC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Deactivate quick tap for Caps-Lock and Spacebar and enter
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SYMBOL,KC_SPC):
        case LT(NAV,KC_BSPC):
        case LT(NAV,KC_ENT):
           return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

// Retro tapping for left gui and left shift home row
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_T(KC_S):
        case LGUI_T(KC_L):
        case LALT_T(KC_A):
        case LALT_T(KC_SCLN):
            return true;
        default:
            return false;
    }
}

// Combos
enum combos {
    DF_ESC,
    JK_ENTER,
    KL_TAB,
    MCom_BSC,
    ComDot_DEL,
    CV_GERMAN,
};
const uint16_t PROGMEM df_combo[] = {LSFT_T(KC_D), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM jk_combo[] = {LCTL_T(KC_J), LSFT_T(KC_K), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {LSFT_T(KC_K), LGUI_T(KC_L), COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM comdot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    [DF_ESC]   = COMBO(df_combo, KC_ESC),
    [JK_ENTER]   = COMBO(jk_combo, KC_ENT),
    [KL_TAB]   = COMBO(kl_combo, KC_TAB),
    [MCom_BSC]   = COMBO(mcom_combo, KC_BSPC),
    [ComDot_DEL] = COMBO(comdot_combo, KC_DEL),
    [CV_GERMAN] = COMBO(cv_combo, OSL(FN)),
};
