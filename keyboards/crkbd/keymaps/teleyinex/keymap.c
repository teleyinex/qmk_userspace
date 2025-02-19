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
#define HOME_A LSFT_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LGUI_T(KC_F)

// Right-hand home row mods
#define HOME_J RGUI_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RSFT_T(ES_NTIL)

enum layer_names {
    _BL,
    _FL,
    _CL,
    _ML,
};

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
      KC_HYPR,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                         KC_H,  HOME_J, HOME_K,  HOME_L, HOME_SCLN, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                     TG(4),  KC_MEH,  LT(1,KC_SPC),                              LT(3,KC_SPC),   LT(2,KC_ENT), KC_HYPR
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
                                          _______, _______,  KC_SPC,     KC_ENT,  _______,_______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_CAPS, ES_EXLM, ES_DQUO, ES_HASH, ES_DLR , ES_PERC,                      ES_ASTR,    ES_7,    ES_8,    ES_9, ES_MINS, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, TD(TD_ES_LCBR_ES_RCBR),TD(TD_ES_LBRC_ES_RBRC) ,                    TD(TD_ES_LPRN_ES_RPRN), ES_EQL, TD(TD_ES_QUES_ES_IEQUE),                      ES_SLSH,    ES_4,    ES_5,    ES_6, ES_PLUS, ES_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, TD(TD_ES_LBRC_ES_RBRC), ES_RBRC, ES_LABK, ES_RABK,  ES_EQL,      ES_0,    ES_1,    ES_2,    ES_3,  ES_DOT, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______,  KC_SPC,     KC_ENT, _______, _______
                                        //`--------------------------'  `--------------------------'

  ),

    [3] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, ES_IEXL,   ES_AT, ES_HASH,  ES_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, ES_FORD, ES_AMPR, ES_PIPE, ES_BSLS, ES_IQUE,                      KC_MPLY, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX ,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX,  ES_NOT, ES_CCED, ES_PERC, XXXXXXX,                      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______,  KC_SPC,     KC_ENT, _______,_______
                                        //`--------------------------'  `--------------------------'

  ),
   [4] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, ES_IEXL,   ES_AT, ES_HASH,  ES_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, MS_UP, XXXXXXX, XXXXXXX, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, ES_FORD, ES_AMPR, ES_PIPE, ES_BSLS, ES_IQUE,                      XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX,  ES_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX,  ES_NOT, ES_CCED, ES_PERC, XXXXXXX,                      XXXXXXX, MS_WHLD , MS_WHLU, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, MS_ACL0, MS_ACL1,  MS_ACL2,    MS_BTN1, MS_BTN2
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

//layer_state_t layer_state_set_user(layer_state_t state) {
//    switch (get_highest_layer(state)) {
//    case _BL:
//        rgblight_setrgb (0x00,  0x00, 0x00);
//        break;
//    case _FL:
//        rgblight_setrgb (0xFF,  0x00, 0x00);
//        break;
//    case _CL:
//        rgblight_setrgb (0x00,  0xFF, 0x00);
//        break;
//    case _ML:
//        rgblight_setrgb (0x7A,  0x00, 0xFF);
//        break;
//    default: //  for any other layers, or the default layer
//        rgblight_setrgb (0x00,  0xFF, 0xFF);
//        break;
//    }
//  return state;
//}
//
// 'Proyecto nuevo', 32x128px
//
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
    return rotation;
}

bool oled_task_user(){

char wpm_str[10];
    // This stores the image content
    static const char hello_world_img [] PROGMEM = {
// 'Proyecto nuevo', 32x128px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0xfe, 0xde, 0x8f, 0x0f, 0x0f, 0x07, 0x07,
0x07, 0x07, 0x0f, 0x0f, 0x8f, 0xde, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x9f, 0xff, 0xfc, 0xfc,
0xf8, 0xfc, 0xfe, 0x9f, 0x8f, 0x07, 0x03, 0x01, 0x00, 0x01, 0xdf, 0xff, 0xff, 0xfc, 0x00, 0x00,
0x00, 0x00, 0x01, 0x0f, 0x3f, 0x7f, 0xfc, 0xf0, 0xf0, 0xfc, 0xde, 0x9f, 0x8f, 0x07, 0x03, 0x01,
0x01, 0x03, 0x07, 0x8f, 0x9f, 0x9e, 0xfc, 0xf8, 0xf0, 0xfc, 0x7f, 0x3f, 0x0f, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x60, 0x70, 0x70, 0x30, 0x30, 0x30,
0x30, 0x30, 0x90, 0xc0, 0x60, 0x18, 0xcc, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xf8, 0xfe, 0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x60, 0x30, 0xf8, 0xfc,
0xfe, 0xff, 0xf7, 0x39, 0x18, 0x08, 0x01, 0x03, 0x07, 0x3f, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0xf8, 0xe0, 0x80, 0x00, 0x20, 0x38, 0xbc, 0xff, 0xff, 0x7f,
0x3f, 0x1d, 0x0c, 0x04, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x7c, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x11, 0x0c, 0x06, 0x03, 0x09, 0x0c, 0x0c,
0x0c, 0x0c, 0x0e, 0x06, 0x06, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0,
0xf0, 0xe0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xc0, 0xf8, 0xfc, 0xdf, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0x0f, 0xfe, 0xff,
0xff, 0xff, 0x1e, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0xfc, 0xf0, 0x00, 0x00,
0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xff, 0xff,
0xff, 0xff, 0xfc, 0xf0, 0xf0, 0xe0, 0xf0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // this displays the image

if (is_keyboard_master()) {
        //render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
oled_write_P(PSTR("Layer\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("BASE\n"), false);
            break;

        case 1:
            oled_write_P(PSTR("BASE\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("ADJ\n"), false);
            break;
   case 4:
            oled_write_P(PSTR("MOUSE\n"), false);
            break;

        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("null"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);


    oled_set_cursor(60, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
    sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // edit the string to change wwhat shows up, edit %03d to change how many digits show up
    oled_write(wpm_str, false);                       // writes wpm on top left corner of string

    return false;
    } else {

    oled_write_raw_P(hello_world_img, sizeof(hello_world_img));
        //oled_scroll_left();  // Turns on scrolling
    }
    return false;

    return false;
}
#endif
