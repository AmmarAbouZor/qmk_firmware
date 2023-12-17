/* Copyright 2023 @ Keychron(https://www.keychron.com)
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

#pragma once

/* RGB Matrix Configuration */
#define RGB_MATRIX_LED_COUNT 89

/* Enable caps-lock LED */
#define CAPS_LOCK_LED_INDEX 23

// ****** My Configs ***********

// This fixes the problem with wake up after restart on windows
#define SPLIT_WATCHDOG_ENABLE

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

#define QUICK_TAP_TERM 200
#define QUICK_TAP_TERM_PER_KEY

// Permissive Hold for index and middle finger in homerow
// #define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// Retro tapping for left gui and left shift home row
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

// This works with combination with retro tapping to suppress left GUI and left ALT
#define DUMMY_MOD_NEUTRALIZER_KEYCODE KC_F18
// Neutralize left alt and left GUI (Default value)
#define MODS_TO_NEUTRALIZE \
    { MOD_BIT(KC_LEFT_ALT), MOD_BIT(KC_LEFT_GUI) }

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
