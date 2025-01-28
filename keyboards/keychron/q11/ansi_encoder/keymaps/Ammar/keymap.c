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

#include "features/achordion.h"
#include QMK_KEYBOARD_H

// Remove the defines down here if this should be used
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
    TODO_AAZ,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define HOME_A LGUI_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LT(SYMB_NAV, KC_F)
#define HOME_Q MT(MOD_LSFT | MOD_LALT ,KC_Q)
#define HOME_J LT(SYMB_NAV, KC_J)
#define HOME_K LSFT_T(KC_K)
#define HOME_L LCTL_T(KC_L)
#define HOME_SC LGUI_T(KC_SCLN)
#define HOME_CPS LT(NUMS, KC_ESC)
#define HOME_SFT LSFT_T(KC_CAPS) // The key hier doesn't matter. I'm toggeling caps words in process_record_user() manually.
#define HOME_MINS LCTL_T(KC_MINS)
#define HOME_PLUS LSFT_T(KC_PLUS)
#define HOME_Z LT(FN, KC_Z)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MPLY,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,     KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   HOME_Q,   KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,     KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  HOME_CPS, HOME_A, HOME_S,   HOME_D,   HOME_F,     KC_G,     KC_H,   HOME_J,   HOME_K,   HOME_L,  HOME_SC,   KC_QUOT,        KC_ENT,   KC_HOME,
        _______,  HOME_SFT,         HOME_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______, KC_LCTL,  KC_LWIN,  KC_LALT,  MO(FN),                KC_SPC,                      KC_SPC,             KC_RALT,  MO(FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FN] = LAYOUT_91_ansi(
        KC_MUTE,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______, QK_REBOOT, KC_MPLY,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            EE_CLR ,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,   DE_SFU,   DE_SFA,   DE_SFO,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,     DE_U,     DE_A,     DE_O,     DE_S,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [SYMB_NAV] = LAYOUT_91_ansi(
        KC_MUTE,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  KC_MPLY,
        _______,  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        _______,  CW_TOGG,  KC_TILDE,   KC_AT,  KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_LCBR,    KC_RCBR,  _______,            _______,
        _______,   KC_SPC, KC_EXCLAIM, HOME_MINS, HOME_PLUS, KC_EQL, KC_UNDS,   KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_PIPE,   KC_GRV,               KC_APP,            _______,
        _______,  _______,           TODO_AAZ,   KC_DEL,   KC_ESC,   KC_TAB,    KC_APP,  KC_BSPC,   KC_ENT,    KC_LT,    KC_GT,  KC_BSLS,              KC_CAPS,  _______,
        _______,  _______,  _______,  _______,  _______,             KC_SPC,                        KC_SPC,            _______,  _______,    _______,  _______,  _______,  _______),

    [NUMS] = LAYOUT_91_ansi(
        KC_MUTE,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  KC_MPLY,
        _______,  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        _______,  _______,  _______,  _______,  KC_PGUP,  _______,  _______,  _______,       KC_7,    KC_8,      KC_9,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  KC_HOME,  KC_PGDN,   KC_END, _______,        KC_0,  KC_4,    KC_5,      KC_6,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,  _______,       KC_0,      KC_1,      KC_2,     KC_3,  _______,             _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                         KC_0,            _______,  _______,    _______,  _______,  _______,  _______),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [FN]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYMB_NAV] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [NUMS]   = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE


// **************************************************
// My changes

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_D:
            return TAPPING_TERM - 90;
        case HOME_K:
        case HOME_CPS:
            return TAPPING_TERM - 110;
        case HOME_F:
        case HOME_S:
            return TAPPING_TERM - 85;
        case HOME_J:
        case HOME_L:
            return TAPPING_TERM - 95;
        case HOME_A:
        case HOME_SC:
        case HOME_Z:
            return TAPPING_TERM + 30;
        case HOME_Q:
            return TAPPING_TERM - 50;
        case HOME_MINS:
        case HOME_PLUS:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

// Permissive hold for Ctrl, Shift, Layer-switch and Q
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_D:
        case HOME_F:
        case HOME_J:
        case HOME_K:
        case HOME_Q:
        case HOME_SFT:
        case HOME_MINS:
        case HOME_PLUS:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_CPS:
        case HOME_L:
        case HOME_S:
        case HOME_D:
        case HOME_F:
        case HOME_MINS:
        case HOME_PLUS:
        case HOME_K:
        case HOME_J:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

// *** Caps Words ***
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        // AMMAR: This is the only difference from the default.
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// *** achordion ***
void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 230;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
        return true;  // Eagerly apply Shift and Ctrl mods.

        default:
        return false;
    }
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
    case HOME_D:
        switch (other_keycode) {
            case HOME_A:
            case HOME_S:
            case HOME_F:
            case KC_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_G:
                return false;
        }
        break;
    case HOME_F:
        switch (other_keycode) {
            case HOME_A:
            case HOME_S:
            case HOME_D:
            case KC_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
                return false;
        }
        break;
    case HOME_S:
        switch (other_keycode) {
            case HOME_A:
            case HOME_D:
            case HOME_F:
            case KC_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_C:
            case KC_V:
            case KC_Z:
            case KC_X:
            case KC_B:
            case KC_G:
                return false;
        }
        break;
    case HOME_A:
        switch (other_keycode) {
            case HOME_S:
            case HOME_D:
            case HOME_F:
            case KC_SPC:
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_C:
            case KC_V:
                return false;
        }
        break;
    case HOME_K:
        switch (other_keycode) {
            case HOME_J:
            case HOME_L:
            case HOME_SC:
            case KC_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_J:
        switch (other_keycode) {
            case HOME_K:
            case HOME_L:
            case HOME_SC:
            case KC_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
                return false;
        }
        break;
    case HOME_L:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_SC:
            case KC_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
            case KC_Y:
            case KC_H:
                return false;
        }
        break;
    case HOME_SC:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_L:
            case KC_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_MINS:
        switch (other_keycode) {
            case KC_TILDE:
            case KC_AT:
            case KC_HASH:
            case KC_DOLLAR:
            case KC_PERCENT:
            case KC_EXCLAIM:
            case KC_EQL:
            case KC_PLUS:
            case KC_UNDS:
            case KC_SPC:
            case HOME_A:
            case HOME_S:
            case HOME_D:
            case HOME_Q:
            case HOME_CPS:
                return false;
        }
        break;
    case HOME_PLUS:
        switch (other_keycode) {
            case KC_TILDE:
            case KC_AT:
            case KC_HASH:
            case KC_DOLLAR:
            case KC_PERCENT:
            case KC_EXCLAIM:
            case KC_MINS:
            case KC_EQL:
            case KC_UNDS:
            case KC_SPC:
            case HOME_A:
            case HOME_S:
            case HOME_F:
            case HOME_Q:
            case HOME_CPS:
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
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00dc"SS_TAP(X_SPC));
        } else {
            // when keycode DE_SFU is released
        }
        break;

    case DE_U:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00fc"SS_TAP(X_SPC));
        }
        break;

    case DE_SFA:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00c4"SS_TAP(X_SPC));
        }
        break;

    case DE_A:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00e4"SS_TAP(X_SPC));
        }
        break;

    case DE_SFO:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00d6"SS_TAP(X_SPC));
        }
        break;

    case DE_O:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00f6"SS_TAP(X_SPC));
        }
        break;

    case DE_S:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u"))"00df"SS_TAP(X_SPC));
        }
        break;
    case TODO_AAZ:
        if (record->event.pressed) {
            SEND_STRING("TODO AAZ:");
        }
        break;
    // Toggle caps word on Shift
    case HOME_SFT:
        if (record->tap.count) {
            if(record->event.pressed) {
                caps_word_toggle();
            }
            return false;
        }
        break;
    // Plus can't be sent with the shift together and must be sent manually
    case HOME_PLUS:
        if (record->tap.count) {
            if(record->event.pressed) {
                tap_code16(KC_PLUS);
            }
            return false;
        }
        break;
    }

    return true;
};
