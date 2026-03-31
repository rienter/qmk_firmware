/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,
        LGUI_T(KC_A),   LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,                    KC_H,     LSFT_T(KC_J),    LCTL_T(KC_K),    LALT_T(KC_L),    LGUI_T(KC_SCLN),
        KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                    KC_N,     KC_M, KC_COMM,  KC_DOT,      KC_SLSH,
        LT(_MEDIA, KC_ESC),LT(_NUM, KC_BSPC),LT(_MOUSE, KC_TAB),   LT(_SYM, KC_ENT),LT(_NAV, KC_SPC),LT(_FUN, KC_DEL)
      ),

      [_NAV] = LAYOUT_split_3x5_3(
         _______, _______, _______, _______, _______,            KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,            KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_CAPS,
         _______, _______, _______, _______, _______,            KC_AGIN, KC_COPY, KC_PSTE,  KC_CUT,  KC_UNDO,
                           _______, _______, _______,            _______, _______, _______
      ),
      [_MOUSE] = LAYOUT_split_3x5_3(
         _______, _______, _______, _______, _______,            _______, _______, _______, _______,  _______,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,            _______, _______, _______, _______,  _______,
         _______, _______, _______, _______, _______,            _______, _______, _______, _______,  _______,
                           _______, _______, _______,            _______, _______, _______
      ),
      [_MEDIA] = LAYOUT_split_3x5_3(
         _______, _______, _______, _______, _______,            _______, _______, _______, _______,  _______,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,            KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  _______,
         _______, _______, _______, _______, _______,            _______, _______, _______, _______,  _______,
                          _______, _______,  _______,            KC_MSTP, KC_MPLY, KC_MUTE
      ),
      [_NUM] = LAYOUT_split_3x5_3(
         _______, _______, _______, _______, _______,            KC_LBRC,    KC_7,    KC_8,    KC_9,  KC_RBRC,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,            KC_QUOT,    KC_4,    KC_5,    KC_6,  KC_EQL,
         _______, _______, _______, _______, _______,             KC_GRV,    KC_1,    KC_2,    KC_3,  KC_BSLS,
                           _______, _______, _______,            KC_MINS,    KC_0, KC_DOT
      ),
      [_SYM] = LAYOUT_split_3x5_3(
         KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,            _______, _______, _______, _______,  _______,
         KC_DQUO,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,            _______, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
         KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,            _______, _______, _______, _______,  _______,
                           KC_LPRN, KC_RPRN, KC_UNDS,            _______, _______, _______
      ),
      [_FUN] = LAYOUT_split_3x5_3(
          KC_F12,   KC_F7,   KC_F8,   KC_F9, _______,            _______, _______, _______, _______,  _______,
          KC_F11,   KC_F4,   KC_F5,   KC_F6, _______,            _______, KC_LSFT, KC_LCTL, KC_LALT,  KC_LGUI,
          KC_F10,   KC_F1,   KC_F2,   KC_F3, _______,            _______, _______, _______, _______,  _______,
                           _______, _______, _______,            _______, _______, _______
      )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
