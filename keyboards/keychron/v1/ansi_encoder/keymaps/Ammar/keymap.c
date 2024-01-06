/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "features/achordion.h"
#include QMK_KEYBOARD_H
// #include "keychron_common.h"

// clang-format off

enum layers{
    BASE,
    FN,
    SYMB_NAV,
    NUMS
};

enum custom_keycodes {
    DE_SFU = SAFE_RANGE,
    DE_U,
    DE_SFA,
    DE_A,
    DE_SFO,
    DE_O,
    DE_S,
    WIN_DESK_PREV,
    WIN_DESK_NEXT,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,   KC_BSPC,  KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,            KC_PGDN,
        LT(NUMS,KC_ESC), LALT_T(KC_A), LGUI_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), MT(MOD_LALT | MOD_LSFT, KC_G), KC_H, LCTL_T(KC_J), LSFT_T(KC_K), LGUI_T(KC_L), LALT_T(KC_SCLN),  KC_QUOT, LT(NUMS,KC_ENT),  KC_HOME,
        OSM(MOD_LSFT),      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              OSM(MOD_RSFT),  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                     LT(SYMB_NAV,KC_SPC),                             KC_RALT,  MO(FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,   DE_SFU,   DE_SFA,   DE_SFO,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,     DE_U,     DE_A,     DE_O,     DE_S,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [SYMB_NAV] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        CW_TOGG,  KC_TILDE,   KC_AT,  KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN, KC_LCBR,    KC_RCBR,  _______,            _______,
        KC_LCTL, KC_EXCLAIM, KC_MINS, KC_PLUS,   KC_EQL,  KC_UNDS,   KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_PIPE,  _______,              KC_APP,            _______,
        _______,            _______,   KC_GRV,  KC_LSFT,  KC_LCTL,   CW_TOGG,   KC_TAB,   KC_ENT,    KC_LT,    KC_GT,  KC_BSLS,              KC_CAPS,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [NUMS] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        _______,  _______,  _______,  KC_PGUP,  _______,  _______,  _______,    KC_7,    KC_8,      KC_9,  _______,  _______,    _______,  _______,            _______,
        _______,  _______, KC_HOME, KC_PGDN, LCTL_T(KC_END), _______, KC_BSPC,  KC_4,    KC_5,      KC_6,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,   KC_1,      KC_2,     KC_3,  _______,              _______,  _______,
        _______,  _______,  _______,                                KC_0,                                _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [SYMB_NAV] = { ENCODER_CCW_CW(WIN_DESK_PREV, WIN_DESK_NEXT)},
    [NUMS]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
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
        case LT(SYMB_NAV,KC_SPC):
            return TAPPING_TERM - 40;
        case LSFT_T(KC_D):
        case LSFT_T(KC_K):
            return TAPPING_TERM - 68;
        case LCTL_T(KC_F):
        case LCTL_T(KC_J):
            return TAPPING_TERM - 60;
        case LALT_T(KC_A):
        case LALT_T(KC_SCLN):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}

// // Permissive Hold for index and middle finger in homerow
// bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case LSFT_T(KC_D):
//         // case LSFT_T(KC_K):
//         case LCTL_T(KC_F):
//         case LCTL_T(KC_J):
//             // Immediately select the hold action when another key is tapped.
//             return true;
//         default:
//             // Do not select the hold action when another key is tapped.
//             return false;
//     }
// }

// Hold On Other Key Press for Caps-Lock and Enter
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(NUMS,KC_ESC):
        case LT(NUMS,KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Disable quick term for backspace, spacebar, Control and Shift
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(SYMB_NAV,KC_BSPC):
        case LT(NUMS,KC_ESC):
        case LT(SYMB_NAV,KC_SPC):
        case LSFT_T(KC_D):
        case LSFT_T(KC_K):
        case LCTL_T(KC_F):
        case LCTL_T(KC_J):
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
        case LT(SYMB_NAV,KC_SPC):
            return true;
        default:
            return false;
    }
}


// This made problems with the fast shift modifier with words ending with d or k
// // *** Keys overrides
// const key_override_t backspace_space_override = ko_make_basic(MOD_MASK_SHIFT, LT(SYMB_NAV,KC_SPC), KC_BSPC);
//
// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &backspace_space_override,
//     NULL // Null terminate the array of overrides!
// };
//

// *** Combos ***
enum combos {
    DF_ESC,
    KL_TAB,
    ComDot_DEL,
    CV_GERMAN,
};
const uint16_t PROGMEM df_combo[] = {LSFT_T(KC_D), LCTL_T(KC_F), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {LSFT_T(KC_K), LGUI_T(KC_L), COMBO_END};
const uint16_t PROGMEM comdot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    [DF_ESC]   = COMBO(df_combo, KC_ESC),
    [KL_TAB]   = COMBO(kl_combo, KC_TAB),
    [ComDot_DEL] = COMBO(comdot_combo, KC_DEL),
    [CV_GERMAN] = COMBO(cv_combo, OSL(FN)),
};

// *** achordion ***
void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 200;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
    case LSFT_T(KC_D):
        switch (other_keycode) {
            case LALT_T(KC_A):
            case LT(SYMB_NAV,KC_SPC):
                return false;
        }
        break;
    case LCTL_T(KC_F):
        switch (other_keycode) {
            case LSFT_T(KC_D):
            case LT(SYMB_NAV,KC_SPC):
                return false;
        }
        break;
    case LSFT_T(KC_K):
        switch (other_keycode) {
            case LT(SYMB_NAV,KC_SPC):
                return false;
        }
        break;
    case LCTL_T(KC_J):
        switch (other_keycode) {
            case LT(SYMB_NAV,KC_SPC):
                return false;
        }
        break;
    }

    return true;
}

// *** achordion & macros ***
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) { return false; }

    switch (keycode) {
    case DE_SFU:
        if (record->event.pressed) {
            // when keycode DE_SFU is pressed
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P4)SS_UP(X_LALT));
        } else {
            // when keycode DE_SFU is released
        }
        break;

    case DE_U:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P1)SS_TAP(X_P2)SS_TAP(X_P9)SS_UP(X_LALT));
        }
        break;

    case DE_SFA:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P1)SS_TAP(X_P4)SS_TAP(X_P2)SS_UP(X_LALT));
        }
        break;

    case DE_A:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P1)SS_TAP(X_P3)SS_TAP(X_P2)SS_UP(X_LALT));
        }
        break;


    case DE_SFO:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P1)SS_TAP(X_P5)SS_TAP(X_P3)SS_UP(X_LALT));
        }
        break;

    case DE_O:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P1)SS_TAP(X_P4)SS_TAP(X_P8)SS_UP(X_LALT));
        }
        break;


    case DE_S:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P5)SS_UP(X_LALT));
        }
        break;

    case WIN_DESK_PREV:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_LEFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        }
        break;

    case WIN_DESK_NEXT:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_RGHT)SS_UP(X_LCTL)SS_UP(X_LGUI));
        }
        break;
    }

    return true;
};

