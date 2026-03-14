/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// This sends whether or not ctrl, shift, etc. are held to the secondary half of
// the keyboard. Note that it seems to "break" one half entirely unless BOTH
// halves have this enabled.
#define SPLIT_MODS_ENABLE

// Allow the current layer to be synced between the halves.
#define SPLIT_LAYER_STATE_ENABLE

// Allow the state of caps lock, num lock, etc. to be synced between the halves.
#define SPLIT_LED_STATE_ENABLE

#define USE_SERIAL_PD2

// RPC to sync `keymap_config` which back magic keycodes.
// See https://github.com/qmk/qmk_firmware/blob/c4551d7ef1ed2c1069f23cc8499b7c7fc30f3ecf/users/drashna/config.h#L32
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_KEYMAP_SYNC

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_SPLIT
#    define RGBLED_NUM 48
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP 10
#    define RGBLIGHT_SAT_STEP 17
#    define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGBLED_NUM 54  // Number of LEDs
#    define DRIVER_LED_TOTAL RGBLED_NUM
#endif

#define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
// Light up keys when pressed, then fade to unlit.
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// Set default RGB mode
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// Set default hue
#define RGB_MATRIX_STARTUP_HUE 200
// Set default saturation
#define RGB_MATRIX_STARTUP_SAT 255
// Set default brightness
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
// Set default animation speed
#define RGB_MATRIX_STARTUP_SPD 35
// Turn off RGB when USB is suspended
#define RGB_DISABLE_WHEN_USB_SUSPENDED

// Setting this to ≤100 makes home-row mods very hard to use since I end up
// holding a key naturally for 100 ms sometimes (especially with my LH).
// However, having it at the default makes modifier keys and the mouse a little
// harder to use since QMK isn't aware of keys pressed on the mouse.
#define TAPPING_TERM 160

// I hold some keys for a just a bit too long (especially "S" for some reason),
// so this lets me increase the tapping term on those keys.
#define TAPPING_TERM_PER_KEY

// Make it so that mod-tap keys run their tap actions when you release the
// mod-tap key before releasing the modified key.
// #define IGNORE_MOD_TAP_INTERRUPT

// Allow mod-tap to work without having to wait for TAPPING_TERM as long as it's
// held for the duration of the modified key being pressed/released.
//
// Tue 12/14/2021 - 09:09 PM - on second thought, this results in too many typos
// and accidental hotkeys.
// #define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY

// See https://configure.zsa.io/moonlander/layouts/bn3qp/latest/config/mouse
// for an explanation.
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_MAX_SPEED 8
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#define MOUSEKEY_WHEEL_DELAY 400

// Allow toggling to a TT layer with just two taps.
#define TAPPING_TOGGLE 2

// Tapping a dual-function key twice will enable its hold action rather than
// repeatedly invoking its tap action.
#define TAPPING_FORCE_HOLD

// Some common bigrams should have lower COMBO_TERMs so that I only activate the
// combo when I really mean to.
#define COMBO_TERM_PER_COMBO
