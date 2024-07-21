/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include "transactions.h"
#include QMK_KEYBOARD_H

// clang-format off
static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0
};
// clang-format on
// clang-format off
static const char PROGMEM kyria_logo[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
    0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};
// clang-format on

enum layers {
    _BÉPO = 0,
    _ACCENTS,
    _SYMBOLES,
    _FUN_FLÈCHES,
    _FUN_SOURIS,
    _FONCTIONS,
    _ADJUST,
};

enum custom_keycodes { // processed by function `process_record_user`, see below
    // French letters
    M_À = SAFE_RANGE,
    M_É,
    M_æ,
    M_œ,
    // brightness controls
    OLED_BRI, // OLED screen brightness increase
    OLED_BRD,             // OLED screen brightness decrease
    OLED_TOG,  // OLED screen display toggle
};

// Aliases for readability
#define VERSION  "2024-07-21.2"

// French keys
#define F_a KC_Q
#define F_é KC_2
#define F_è KC_7
#define F_ù KC_QUOTE
#define F_q KC_A
#define F_z KC_W
#define F_w KC_Z
#define F_m KC_SCLN
#define F_à KC_0
#define F_ç KC_9
#define F_DOT KC_LT
#define F_VIRG KC_M
#define F_QUOT KC_4
#define F_DASH KC_6
#define F_UNDERSC KC_8
#define F_TREMA KC_LCBR
#define F_CIRCO KC_LBRC
#define F_LT KC_NUBS
#define F_GT LSFT(KC_NUBS)
#define F_€ RALT(KC_E)
#define F_AT RALT(KC_0)
#define F_PIPE RALT(KC_6)
#define F_LBRK RALT(KC_5)
#define F_RBRK RALT(KC_MINS)
#define F_COLON KC_DOT
#define F_MICOL KC_COMM
#define F_SLSH KC_PSLS
#define F_BSLSH RALT(KC_8)
#define F_PARGR KC_QUES
#define F_LPAR KC_5
#define F_RPAR KC_MINS
#define F_LCURL RALT(KC_4)
#define F_RCURL RALT(KC_EQL)
#define F_BTICK RALT(KC_7)
#define F_PCT RSFT(KC_QUOT)
#define F_TILD RALT(KC_2)
#define F_HASH RALT(KC_3)
#define F_EXCL KC_SLSH
#define F_QUEST RSFT(KC_M)
#define F_DOLL KC_RBRC
#define F_AMP KC_1
#define F_0 LSFT(KC_0)
#define F_1 LSFT(KC_1)
#define F_2 LSFT(KC_2)
#define F_3 LSFT(KC_3)
#define F_4 LSFT(KC_4)
#define F_5 LSFT(KC_5)
#define F_6 LSFT(KC_6)
#define F_7 LSFT(KC_7)
#define F_8 LSFT(KC_8)
#define F_9 LSFT(KC_9)
#define F_EQL LSFT(KC_EQL)

#define WORDBEF RCTL(KC_LEFT)
#define WORDAFT RCTL(KC_RGHT)

// home-row mods
#define a_GUI LGUI_T(F_a)
#define u_ALT LALT_T(KC_U)
#define i_SFT LSFT_T(KC_I)
#define e_CTL LCTL_T(KC_E)
#define t_CTL RCTL_T(KC_T)
#define s_SFT RSFT_T(KC_S)
#define r_ALT LALT_T(KC_R)
#define n_GUI RGUI_T(KC_N)

// tap-holds & navigation
#define DEL_ARR LT(_FUN_FLÈCHES, KC_DEL)
#define BSP_ARR LT(_FUN_FLÈCHES, KC_BSPC)
#define SPC_ACC LT(_ACCENTS, KC_SPC)
#define SPC_SYM LT(_SYMBOLES, KC_SPC)
#define DSH_ADJ LT(_ADJUST, F_DASH)
#define UND_MSE LT(_FUN_SOURIS, F_UNDERSC)

// brightness values
#define OLED_BRI_MAX 255
#define OLED_BRI_MIN 0
#define OLED_BRI_STEP 64

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BÉPO] = LAYOUT(
        KC_ESC , KC_B   , F_é    , KC_P   , KC_O   , F_è    ,                                     F_w    , KC_V   , KC_D   , KC_L   , KC_J   , F_z    ,
        KC_NO  , a_GUI  , u_ALT  , i_SFT  , e_CTL  , F_VIRG ,                                     KC_C   , t_CTL  , s_SFT  , r_ALT  , n_GUI  , F_m    ,
        KC_NO  , F_à    , KC_Y   , KC_X   , F_DOT  , KC_K   , KC_NO  , KC_NO  , KC_NO  , KC_NO  , F_QUOT , F_q    , KC_G   , KC_H   , KC_F   , KC_ENT ,
                                   KC_NO  , KC_NO  , UND_MSE, SPC_ACC, DEL_ARR, BSP_ARR, SPC_SYM, DSH_ADJ, KC_NO  , KC_NO  ),
	[_ACCENTS] = LAYOUT(
        KC_TRNS, KC_3   , M_É    , F_PARGR, M_œ    , KC_NO  ,                                     KC_NO  , KC_NO  , F_DOLL , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, F_AT   , F_ù    , F_TREMA, F_€    , F_MICOL,                                     F_ç    , F_EXCL , KC_NO  , KC_NO  , F_TILD , KC_NO  ,
        KC_TRNS, M_À    , M_æ    , F_CIRCO, F_COLON, KC_TAB , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , F_QUEST, KC_UNDS, F_HASH , KC_NO  , KC_NO  ,
                                   KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_NO  ),
	[_SYMBOLES] = LAYOUT(
        KC_TRNS, F_LT   , F_GT   , F_LBRK , F_RBRK , KC_NO  ,                                     F_PCT  , F_7    , F_8    , F_9    , F_HASH , KC_EQL ,
        KC_TRNS, F_PIPE , F_LPAR , F_AMP  , F_RPAR , F_BTICK,                                     F_SLSH , F_4    , F_5    , F_6    , KC_6   , KC_PAST,
        KC_TRNS, F_COLON, F_BSLSH, F_LCURL, F_RCURL, F_DOT  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , F_VIRG , F_1    , F_2    , F_3    , F_EQL  , KC_TRNS,
                                   KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, F_0    , KC_NO  , KC_NO  ),
	[_FUN_FLÈCHES] = LAYOUT(
        KC_TRNS, KC_NO  , KC_F2  , KC_F3  , KC_F4  , KC_PSTE,                                     KC_INS , KC_HOME, KC_UP  , KC_END , KC_NO  , KC_NO  ,
        KC_TRNS, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_COPY,                                     KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_NO  ,
        KC_TRNS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_CUT , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , WORDBEF, KC_NO  , WORDAFT, KC_PGDN, KC_TRNS,
                                   KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ),
	[_FUN_SOURIS] = LAYOUT(
        KC_NO  , KC_NO  , KC_F2  , KC_F3  , KC_F4  , KC_NO  ,                                     KC_ACL2, KC_BTN2, KC_MS_U, KC_BTN3, KC_NO  , KC_NO  ,
        KC_NO  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_NO  ,                                     KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_NO  ,
        KC_NO  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ACL0, KC_WH_L, KC_NO  , KC_WH_R, KC_WH_D, KC_NO  ,
                                   KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_NO  , KC_NO  ),
	[_ADJUST] = LAYOUT(
        RGB_HUI, RGB_SAI, RGB_SPI, RGB_MOD, RGB_VAI, OLED_BRI,                                    KC_BRIU, KC_VOLU, KC_MNXT, KC_NO  , KC_NO  , QK_UNICODE_MODE_NEXT,
        RGB_HUD, RGB_SAD, RGB_SPD, RGB_RMOD,RGB_VAD, OLED_BRD,                                    KC_BRID, KC_VOLD, KC_MPLY, KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , RGB_TOG, OLED_TOG,KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MUTE, KC_MSTP, KC_NO  , KC_NO  , KC_NO  ,
                                   KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_NO  , KC_NO  )
};

void set_both_oled_brightness(uint8_t target) {
    oled_set_brightness(target);
}

void increase_oled_brightness(void) {
    uint8_t current = oled_get_brightness();
    // Take care not to overflow uint8
    uint8_t target = (
        (OLED_BRI_MAX - OLED_BRI_STEP < current) ?
        (OLED_BRI_MAX) : (current + OLED_BRI_STEP)
    );
    set_both_oled_brightness(target);
}

void decrease_oled_brightness(void) {
    uint8_t current = oled_get_brightness();
    // Take care not to underflow uint8
    uint8_t target = (
        (OLED_BRI_MIN + OLED_BRI_STEP > current) ?
        (OLED_BRI_MIN) : (current - OLED_BRI_STEP)
    );
    oled_set_brightness(target);
}

void toggle_oled_display(void) {
    uint8_t current = oled_get_brightness();
    uint8_t target = ((current > 0) ? 0 : OLED_BRI_STEP);
    oled_set_brightness(target);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* custom treatment
    <https://docs.qmk.fm/#/custom_quantum_functions>
    */
    if (record->event.pressed) {
        switch (keycode) {
            case M_À:
                send_unicode_string("À");
                return false;
            case M_É:
                send_unicode_string("É");
                return false;
            case M_æ:
                send_unicode_string("æ");
                return false;
            case M_œ:
                send_unicode_string("œ");
                return false;
            case OLED_BRI:
                increase_oled_brightness();
                return false; // skip further processing
            case OLED_BRD:
                decrease_oled_brightness();
                return false; // skip further processing
            case OLED_TOG:
                toggle_oled_display();
                return false;
            default:
                return true; // process all other keycodes normally
        };
    }
    return true;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(qmk_logo, false);

        // meta informations
        oled_write_P(PSTR("      "), false); // padding
        oled_write_P(PSTR(VERSION), false);
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("\n"), false);

        // layer information
        // oled_write_P(PSTR("couche: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _BÉPO:
                oled_write_P(PSTR("       bepo\n"), false);
                break;
            case _ACCENTS:
                oled_write_P(PSTR("      accents\n"), false);
                break;
            case _SYMBOLES:
                oled_write_P(PSTR("chiffres & symboles\n"), false);
                break;
            case _FUN_FLÈCHES:
                oled_write_P(PSTR("   f-keys & fleches\n"), false);
                break;
            case _FUN_SOURIS:
                oled_write_P(PSTR("   f-keys & souris\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("      adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("        ???\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("numlck ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("caplck ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("scrlck ") : PSTR("       "), false);
    } else {
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
};
