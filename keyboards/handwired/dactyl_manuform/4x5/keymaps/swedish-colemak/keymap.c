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

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

#define _BASE    0
#define _COLEMAK 1
#define _RAISE   2
#define _LOWER   3

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define CTL_END  CTL_T(KC_END)
#define ALT_DEL  ALT_T(KC_DEL)
#define ALT_ENT  ALT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define COLEMAK TT(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * ,----------------------------------,                             ,----------------------------------,
     * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |  [   |   ]  |                                                         |   -  |   =  |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      | ESC  |  BS  |                             |      |      |
     *                      |  +   |   +  |                             | SPACE| SHIFT|
     *                      | SHIFT| CTRL |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '--------+------' '---------+----------'
     *                                    | ALT+DEL| HOME | | CTL + END  | ALT+Enter|
     *                                    '--------+------' '---------+----------'
     *                                    | Raise  |  ~   | | GUI     | Lower   |
     *                                    '------+--------' '------+---------'
     */
    [_BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
                          KC_LBRC, KC_RBRC,                                                        KC_MINS, KC_EQL,
                                            SFT_ESC, CTL_BSPC,                     KC_SPC, KC_LSFT,
                                                     ALT_DEL, RAISE,    LOWER, ALT_ENT,
                                                     KC_HOME, KC_GRV,   KC_LGUI, CTL_END
                                //ORIGINAL:         //ALT_DEL, KC_HOME,  CTL_END, ALT_ENT,
                                //(i soldered wrong //RAISE,   KC_GRV,   KC_LGUI, LOWER
    ),
    [_COLEMAK] = LAYOUT(
        KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,                                         KC_J,   KC_L, KC_U,    KC_Y,   KC_SCLN,
        KC_A,    KC_R,    KC_S,    KC_T,   KC_D,                                         KC_H,   KC_N, KC_E,    KC_I,   KC_O,
        KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                                         KC_K,   KC_M, KC_COMM, KC_DOT, KC_QUOT,
                 KC_LBRC, KC_RBRC,                                                               KC_MINS, KC_EQL,
                                            SFT_ESC, CTL_BSPC,                     KC_SPC, KC_LSFT,
                                                     ALT_DEL, RAISE,    LOWER, ALT_ENT,
                                                     KC_HOME, KC_GRV,   KC_LGUI, CTL_END
    ),

    /* Raise
     * ,-----------------------------------,                             ,----------------------------------,
     * |  QK_BOOT |      |  mup |      |       |                             | VOL+ |      |  up  |      | PgUp |
     * |------+------+------+------+-------|                             |-------------+------+------+------|
     * |        | mleft| mdown|mright|       |                             | MUTE | left | down |right | PgDn |
     * |------+------+------+------+-------|                             |------|------+------+------+------|
     * |   å  |      |      |      |COLEMAK|                             | VOL- |  /   |  \   |  ?   |  |   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        |      |      |                                                         | mbtn |mbtn2 |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             | TAB  |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_RAISE] = LAYOUT(
        QK_BOOT, _______, KC_MU,   _______, _______,                                      KC_VOLU, _______, KC_UP,   _______, KC_PGUP,
        _______, KC_ML,   KC_MD,   KC_MR,   _______,                                      KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
        SE_ARNG, _______, _______, _______, COLEMAK,                                      KC_VOLD, KC_SLSH, KC_BSLS, KC_QUES, KC_PIPE,
                 _______, _______,                                                                          KC_MB1,  KC_MB2,
                                   _______, _______,                                      KC_TAB, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    ),

    /* Lower
     * ,----------------------------------,                             ,----------------------------------,
     * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
     * |------+------+------+------+------|                             |-------------+------+------+------|
     * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
     * |------+------+------+------+------|                             |------|------+------+------+------|
     * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
     * |------+------+------+-------------,                             ,-------------+------+------+------,
     *        | F11  | F12  |                                                         |  -   |  =   |
     *        '------+------'-------------'                             '-------------'------+------'
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      |      |      |                             |      |      |
     *                      '------+------'                             '------+------'
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     *                                    |      |      | |      |      |
     *                                    '------+------' '------+------'
     */
    [_LOWER] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                 KC_F11,  KC_F12,                                                                           _______, _______,
                                   _______, _______,                                      _______, _______,
                                                     _______, _______,  _______, _______,
                                                     _______, _______,  _______, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
