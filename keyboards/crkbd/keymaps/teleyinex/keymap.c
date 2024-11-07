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
#include "keymap_spanish.h"

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(ES_NTIL)


enum {
    TD_ES_QUES_ES_IEQUE,
    TD_ES_LCBR_ES_RCBR,
    TD_ES_LPRN_ES_RPRN,
    TD_ES_LBRC_ES_RBRC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ES_QUES_ES_IEQUE] = ACTION_TAP_DANCE_DOUBLE(ES_QUES, ES_IQUE),
    [TD_ES_LCBR_ES_RCBR] = ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR),
    [TD_ES_LPRN_ES_RPRN] = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN),
    [TD_ES_LBRC_ES_RBRC] = ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_HYPR,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                  KC_H,    HOME_J,    HOME_K,    HOME_L, HOME_SCLN, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                     KC_LALT,  MT(MOD_LGUI,KC_LCTL),  LT(1,KC_SPC),     LT(3,KC_SPC),   LT(2,KC_ENT), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, ES_DIAE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, ES_SCLN, ES_COLN, ES_UNDS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,  _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_CAPS, ES_EXLM, ES_DQUO, ES_HASH, ES_DLR , ES_PERC,                      ES_ASTR,    ES_7,    ES_8,    ES_9, ES_MINS, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, TD(TD_ES_LCBR_ES_RCBR),TD(TD_ES_LBRC_ES_RBRC) , TD(TD_ES_LPRN_ES_RPRN), ES_EQL, TD(TD_ES_QUES_ES_IEQUE),                      ES_SLSH,    ES_4,    ES_5,    ES_6, ES_PLUS, ES_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, TD(TD_ES_LBRC_ES_RBRC), ES_RBRC, ES_LABK, ES_RABK,  ES_EQL,                         ES_0,    ES_1,    ES_2,    ES_3,  ES_DOT, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                        //`--------------------------'  `--------------------------'

  ),

    [3] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, ES_IEXL,   ES_AT, ES_HASH,  ES_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLU, ES_MORD, XXXXXXX, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, ES_FORD, ES_AMPR, ES_PIPE, ES_BSLS, ES_IQUE,                      XXXXXXX, KC_MPLY, KC_VOLD, XXXXXXX, ES_TILD,  ES_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX,  ES_NOT, ES_CCED, ES_PERC, XXXXXXX,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_LALT
                                        //`--------------------------'  `--------------------------'

  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case KC_ESC:
        // Detect the activation of only Left Alt
        if (get_mods() == MOD_BIT(KC_LGUI)) {
            if (record->event.pressed) {
                // No need to register KC_LALT because it's already active.
                // The Alt modifier will apply on this KC_TAB.
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            // Do not let QMK process the keycode further
            return false;
        }
        // Else, let QMK process the KC_ESC keycode as usual
        return true;



    };
    return true;
};
