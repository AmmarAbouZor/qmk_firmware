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

#define HOME_A LALT_T(KC_A)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)
#define HOME_Q MT(MOD_LSFT | MOD_LALT ,KC_Q)
#define HOME_J LCTL_T(KC_J)
#define HOME_K LSFT_T(KC_K)
#define HOME_L LGUI_T(KC_L)
#define HOME_SC LALT_T(KC_SCLN)
#define HOME_SPC LT(SYMB_NAV, KC_SPC)
#define HOME_CPS LT(NUMS, CW_TOGG) // The key hier doesn't matter. I'm toggeling caps words in process_record_user() manually.
// #define HOME_SHFT LSFT_T(KC_CAPS) // TODO: remove if the caps worked.
#define HOME_EQL LCTL_T(KC_EQL)
#define HOME_PLUS LSFT_T(KC_PLUS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MPLY,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,     KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   HOME_Q,   KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,     KC_RBRC,  KC_BSLS,            KC_PGDN,
        _______,  HOME_CPS, HOME_A, HOME_S,   HOME_D,   HOME_F,     KC_G,     KC_H,   HOME_J,   HOME_K,   HOME_L,  HOME_SC,   KC_QUOT, LT(NUMS,KC_ENT), KC_HOME,
        _______, OSM(MOD_LSFT),      KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______, KC_LCTL,  KC_LWIN,  KC_LALT,  MO(FN),              HOME_SPC,                    HOME_SPC,             KC_RALT,  MO(FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [FN] = LAYOUT_91_ansi(
        KC_MUTE,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  DB_TOGG,  KC_MPLY,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,   DE_SFU,   DE_SFA,   DE_SFO,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,     DE_U,     DE_A,     DE_O,     DE_S,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [SYMB_NAV] = LAYOUT_91_ansi(
        KC_MUTE,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  KC_MPLY,
        _______,  _______,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,     KC_F12,  _______,            _______,
        _______,  CW_TOGG,  KC_TILDE,   KC_AT,  KC_HASH, KC_DOLLAR, KC_PERCENT, KC_CIRC,  KC_AMPR, KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_LCBR,    KC_RCBR,  _______,            _______,
        _______,   KC_SPC, KC_EXCLAIM, KC_MINS, HOME_PLUS, HOME_EQL, KC_UNDS,   KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  KC_PIPE,   KC_GRV,               KC_APP,            _______,
        _______,  _______,           TODO_AAZ,  _______,   KC_TAB,   KC_DEL,    KC_APP,  KC_BSPC,   KC_ENT,    KC_LT,    KC_GT,  KC_BSLS,              KC_CAPS,  _______,
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
        case HOME_SPC:
            return TAPPING_TERM - 85;
        case HOME_D:
            return TAPPING_TERM - 85;
        case HOME_K:
            return TAPPING_TERM - 100;
        case HOME_F:
            return TAPPING_TERM - 85;
        case HOME_J:
            return TAPPING_TERM - 90;
        case HOME_A:
        case HOME_SC:
            return TAPPING_TERM + 40;
        case HOME_S:
        case HOME_L:
        case HOME_Q:
            return TAPPING_TERM - 40;
        case HOME_EQL:
        case HOME_PLUS:
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
}

// Hold On Other Key Press for Caps-Lock and Enter
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_CPS:
        case LT(NUMS,KC_ENT):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// Disable quick term for backspace
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_CPS:
        case HOME_SPC:
        case HOME_D:
        case HOME_F:
        case HOME_EQL:
        case HOME_PLUS:
        case HOME_K:
        case HOME_J:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

// Retro tapping for space bar
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_SPC:
            return true;
        default:
            return false;
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


// // *** Keys overrides ***
// // overrides on base layer only
// const key_override_t ctrl_zero_override = ko_make_with_layers(MOD_MASK_CTRL, KC_0, C(KC_BSPC), 1);
// const key_override_t ctrl_nine_override = ko_make_with_layers(MOD_MASK_CTRL, KC_9, KC_BSPC, 1);
// const key_override_t ctrl_eight_override = ko_make_with_layers(MOD_MASK_CTRL, KC_8, KC_BSPC, 1);
//
// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &ctrl_zero_override,
//     &ctrl_nine_override,
//     &ctrl_eight_override,
//     NULL // Null terminate the array of overrides!
// };


// *** Combos ***
enum combos {
    DF_ESC,
    KL_TAB,
    JK_ENTER,
    // ComDot_DEL,
    CV_GERMAN,
};
const uint16_t PROGMEM df_combo[] = {HOME_D, HOME_F, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {HOME_J, HOME_K, COMBO_END};
// const uint16_t PROGMEM comdot_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};

combo_t key_combos[] = {
    [DF_ESC]   = COMBO(df_combo, MT(MOD_LSFT | MOD_LCTL,KC_ESC)),
    [KL_TAB]   = COMBO(kl_combo, MT(MOD_RSFT | MOD_LGUI, KC_TAB)),
    [JK_ENTER]   = COMBO(jk_combo, MT(MOD_RSFT | MOD_RCTL,KC_ENT)),
    // [ComDot_DEL] = COMBO(comdot_combo, KC_DEL),
    [CV_GERMAN] = COMBO(cv_combo, OSL(FN)),
};

// Increase the time for Escape and Tab
int16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case DF_ESC:
            return 100;
        case JK_ENTER:
            return 60;
        // case ComDot_DEL:
        case KL_TAB:
            return 35;
    }

    return COMBO_TERM;
}

// *** achordion ***
void matrix_scan_user(void) {
  achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 230;
}

bool achordion_eager_mod(uint8_t mod) {
    return false;
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
            case HOME_SPC:
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
            case HOME_SPC:
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
            case KC_W:
            case KC_E:
            case KC_R:
            case KC_T:
            case KC_C:
            case KC_V:
                return false;
        }
        break;
    case HOME_A:
        switch (other_keycode) {
            case HOME_S:
            case HOME_D:
            case HOME_F:
            case HOME_SPC:
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
            case HOME_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
                return false;
        }
        break;
    case HOME_J:
        switch (other_keycode) {
            case HOME_K:
            case HOME_L:
            case HOME_SC:
            case HOME_SPC:
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
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_SC:
        switch (other_keycode) {
            case HOME_J:
            case HOME_K:
            case HOME_L:
            case HOME_SPC:
            case KC_U:
            case KC_I:
            case KC_O:
            case KC_P:
            case KC_M:
            case KC_N:
                return false;
        }
        break;
    case HOME_EQL:
        switch (other_keycode) {
            case KC_TILDE:
            case KC_AT:
            case KC_HASH:
            case KC_DOLLAR:
            case KC_PERCENT:
            case KC_EXCLAIM:
            case KC_MINS:
            case KC_PLUS:
            case KC_UNDS:
            case KC_SPC:
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
    // Toggle caps word on shift Caps-Lock
    case HOME_CPS:
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
