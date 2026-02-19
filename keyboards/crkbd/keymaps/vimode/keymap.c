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
    _BASE,
    _NAV,
    _NUM,
    _SYM,
    _MOUSE,
};

enum custom_keycodes {
    BACK_WORD = SAFE_RANGE,
    FORWARD_WORD,
    VIM_VIS_TOG,
};


static bool visual_mode = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_HYPR,  HOME_A,  HOME_S,  HOME_D,  HOME_F,   KC_G,                         KC_H,  HOME_J, HOME_K,  HOME_L, HOME_SCLN, ES_ACUT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, ES_COMM,  ES_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                     TG(4),  MO(2), LT(1, KC_SPC),                              KC_SPC,   LT(3,KC_ENT), KC_HYPR
                                      //`--------------------------'  `--------------------------'


  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   XXXXXXX,    FORWARD_WORD,  XXXXXXX  , XXXXXXX   ,  XXXXXXX  ,                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, ES_DIAE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, VIM_VIS_TOG, BACK_WORD,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______ ,    _______, _______ ,_______
                                      //`--------------------------'  `--------------------------'

  ),

    [2] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      ES_ASTR,    ES_7,    ES_8,    ES_9, ES_MINS, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      ES_SLSH,    ES_4,    ES_5,    ES_6, ES_PLUS, ES_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        ES_0,    ES_1,    ES_2,    ES_3,  ES_DOT, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______,  _______,     KC_SPC, _______, _______
                                        //`--------------------------'  `--------------------------'

  ),



    [3] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       ES_AMPR, ES_EXLM,   ES_AT, ES_HASH,  ES_DLR, ES_PERC,                      XXXXXXX, ES_IEXL, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ES_PIPE, ES_LCBR, ES_RCBR, ES_LPRN, ES_RPRN,  ES_EQL,                      KC_MPLY, ES_DQUO, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       ES_BSLS, ES_LBRC, ES_RBRC, ES_LABK, ES_RABK, ES_QUES,                      XXXXXXX, ES_IQUE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______,  _______,     KC_SPC, _______, _______
                                        //`--------------------------'  `--------------------------'

  ),
   [4] = LAYOUT_split_3x6_3(
     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        TO(0), ES_IEXL,   ES_AT, ES_HASH,  ES_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, OM_U, XXXXXXX, XXXXXXX, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, OM_L, OM_D, OM_R, OM_SLOW,  ES_GRV,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, OM_W_D , OM_W_U, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, MS_ACL0, MS_ACL1,  MS_ACL2,    OM_BTNS, OM_BTN2
                                        //`--------------------------'  `--------------------------'

  )

};


layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, 1)) {
        visual_mode = false;
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {


        case (VIM_VIS_TOG):
    if (record->event.pressed) {
            visual_mode = !visual_mode;
            }
            return false;


    case BACK_WORD:

    if (record->event.pressed) {
        switch (detected_host_os()) {
            case OS_MACOS:
            case OS_IOS:
                if (visual_mode) {
                            tap_code16(LSFT(LALT(KC_LEFT)));
                        } else {
                            tap_code16(LALT(KC_LEFT));
                }
                break;
            case OS_WINDOWS:
            case OS_LINUX:
            case OS_UNSURE:
                if (visual_mode) {
                                    tap_code16(LSFT(LCTL(KC_LEFT)));
                                } else {
                tap_code16(LCTL(KC_LEFT));
}
                break;
        }
            }
        return false;


    case FORWARD_WORD:
    if (record->event.pressed) {
        switch (detected_host_os()) {
            case OS_MACOS:
            case OS_IOS:
                                if (visual_mode) {
                                    tap_code16(LSFT(LALT(KC_RIGHT)));
                    } else {
                tap_code16(LALT(KC_RIGHT));
                                }
                break;
            case OS_WINDOWS:
            case OS_LINUX:
            case OS_UNSURE:
                    if (visual_mode) {
                        tap_code16(LSFT(LCTL(KC_RIGHT)));
                    } else {
                tap_code16(LCTL(KC_RIGHT));
                    }
                break;
        }
            }
        return false;


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


uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_ENT):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:      // LSFT_T(KC_A)
            return 220;
        case HOME_SCLN:  // RSFT_T(ES_NTIL)
            return 220;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_SCLN:
            return true;
        default:
            return false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(3, KC_ENT):
            return true;
        default:
            return false;
    }
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(){

    // =====================================================================
    // ORIGINAL GRAPHICS (commented out, kept for reference)
    // To restore: uncomment this block and comment out the new code below
    // =====================================================================
    /*
    -- original layer images available in git history --
    */

    // =====================================================================
    // LEFT DISPLAY: layer indicator + visual mode status
    // =====================================================================
    if (is_keyboard_master()) {
        // Show active layer name
        oled_set_cursor(0, 0);
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("NAV \n"), false);
                break;
            case _NUM:
                oled_write_P(PSTR("NUM \n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("SYM \n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("MOUS\n"), false);
                break;
            default:
                oled_write_P(PSTR("??? \n"), false);
        }

        // Separator line
        oled_write_P(PSTR("----\n"), false);

        // Show visual mode indicator (only when active, inverted for visibility)
        if (visual_mode) {
            oled_write_P(PSTR("VIS \n"), true);
        } else {
            oled_write_P(PSTR("    \n"), false);
        }

        return false;

    // =====================================================================
    // RIGHT DISPLAY: real-time WPM graph
    // =====================================================================
    } else {
        // WPM history buffer - 32 samples (matches OLED width when rotated)
        #define WPM_GRAPH_SAMPLES 32
        #define WPM_GRAPH_MAX     120  // scale ceiling in WPM
        #define WPM_UPDATE_MS     200  // sampling interval in milliseconds

        static uint8_t  wpm_history[WPM_GRAPH_SAMPLES] = {0};
        static uint32_t last_wpm_update                 = 0;

        // Sample WPM at fixed interval and shift history left
        if (timer_elapsed32(last_wpm_update) > WPM_UPDATE_MS) {
            memmove(wpm_history, wpm_history + 1, WPM_GRAPH_SAMPLES - 1);
            uint8_t wpm = get_current_wpm();
            wpm_history[WPM_GRAPH_SAMPLES - 1] = wpm > WPM_GRAPH_MAX ? WPM_GRAPH_MAX : wpm;
            last_wpm_update = timer_read32();
        }

        // Draw WPM graph pixel by pixel
        // x = time (left = oldest, right = newest)
        // y = WPM value scaled to OLED height (32px)
        oled_clear();
        for (uint8_t x = 0; x < WPM_GRAPH_SAMPLES; x++) {
            uint8_t height = (wpm_history[x] * 32) / WPM_GRAPH_MAX;
            for (uint8_t y = 0; y < 32; y++) {
                oled_write_pixel(x, 31 - y, y < height);
            }
        }

        // Current WPM as text overlaid on graph
        char wpm_str[5];
        snprintf(wpm_str, sizeof(wpm_str), "%3d", get_current_wpm());
        oled_set_cursor(0, 0);
        oled_write(wpm_str, false);

        return false;
    }
}
#endif
