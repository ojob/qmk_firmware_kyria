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
    _FLÈCHES,
    _SOURIS,
    _FONCTIONS,
    _ADJUST,
};

enum custom_keycodes {
    OLED_BRI_MAX = SAFE_RANGE, // OLED screen brightness max
    OLED_BRI_MID,              // OLED screen brightness middle
    OLED_BRI_DIM,              // OLED screen brightness dimmed
    A_GRAVE_CAPITAL,
    E_ACUTE_CAPITAL,
    AE_LIGATURE,
    OE_LIGATURE,
};

// Aliases for readability
#define VERSION  "2023-08-06.2"
#define OLED_BRIGHTNESS_MAX 255
#define OLED_BRIGHTNESS_MIDDLE 50
#define OLED_BRIGHTNESS_DIMMED 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BÉPO] = LAYOUT(
        LT(_FONCTIONS,KC_ESC), KC_B, KC_2, KC_P, KC_O, KC_7, KC_Z, KC_V, KC_D, KC_L, KC_J, KC_W,
        LT(_SOURIS,KC_TAB), KC_Q, KC_U, KC_I, KC_E, KC_M, KC_C, KC_T, KC_S, KC_R, KC_N, KC_SCLN,
        LCTL_T(KC_DEL), KC_0, KC_Y, KC_X, KC_LT, KC_K, KC_NO, MO(_ADJUST), MO(_ADJUST), KC_4, KC_4, KC_A, KC_G, KC_H, KC_F, RCTL_T(KC_ENT),
        KC_LSFT, KC_LGUI, LALT_T(KC_8), LT(_ACCENTS,KC_SPC), LT(_FLÈCHES,KC_DEL), LT(_FLÈCHES,KC_BSPC), LT(_SYMBOLES,KC_SPC), RSFT_T(KC_6), KC_NO, KC_NO),
	[_ACCENTS] = LAYOUT(
        KC_TRNS, KC_3, E_ACUTE_CAPITAL, KC_QUES, OE_LIGATURE, KC_NO, KC_NO, KC_NO, KC_RBRC, KC_NO, KC_NO, KC_NO,
        KC_TRNS, RALT(KC_0), KC_QUOT, KC_LCBR, RALT(KC_E), KC_COMM, KC_9, KC_SLSH, RALT(KC_3), KC_NO, RALT(KC_2), KC_NO,
        KC_TRNS, A_GRAVE_CAPITAL, AE_LIGATURE, KC_LBRC, KC_DOT, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, RSFT(KC_M), KC_UNDS, KC_NO, KC_NO,KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO),
	[_SYMBOLES] = LAYOUT(
        KC_TRNS, KC_NUBS, LSFT(KC_NUBS), RALT(KC_5), RALT(KC_MINS), KC_NO, RSFT(KC_QUOT), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), RALT(KC_3), KC_EQL,
        KC_TRNS, RALT(KC_6), KC_5, KC_1, KC_MINS, RALT(KC_7), KC_PSLS, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_6, KC_PAST,
        KC_TRNS, KC_DOT, RALT(KC_8), RALT(KC_4), RALT(KC_EQL), KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_M, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_EQL),
        KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PDOT, LSFT(KC_0), KC_NO
    ),
	[_FLÈCHES] = LAYOUT(
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_INS, KC_HOME, KC_UP, KC_END, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_UP), KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_NO,
        KC_TRNS, LGUI(KC_LEFT), LGUI(KC_RGHT), LGUI(KC_DOWN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RCTL(KC_LEFT), KC_NO, RCTL(KC_RGHT), KC_PGDN, KC_TRNS,
        KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    ),
	[_SOURIS] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2, KC_BTN2, KC_MS_U, KC_BTN3, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_WH_L, KC_NO, KC_WH_R, KC_WH_D, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_NO, KC_NO
    ),
	[_FONCTIONS] = LAYOUT(
        KC_TRNS, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_TRNS, KC_F1, KC_NO, KC_NO, LCTL(KC_F5), LCTL(KC_F6), KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_F11), KC_NO,
        KC_TRNS, KC_NO, KC_CUT, KC_COPY, KC_PSTE, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                        KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
    ),
	[_ADJUST] = LAYOUT(
        RGB_HUI, RGB_SAI, RGB_SPI, RGB_MOD, RGB_VAI, OLED_BRI_MAX, KC_BRIU, KC_VOLU, KC_MNXT, KC_NO, KC_NO, QK_UNICODE_MODE_NEXT,
        RGB_HUD, RGB_SAD, RGB_SPD, RGB_RMOD, RGB_VAD, OLED_BRI_MID, KC_BRID, KC_VOLD, KC_MPLY, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, OLED_BRI_DIM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_MUTE, KC_MSTP, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* custom treatment
    <https://docs.qmk.fm/#/custom_quantum_functions>
    */
    if (record->event.pressed) {
        switch (keycode) {
            case A_GRAVE_CAPITAL:
                send_unicode_string("À");
                return false;
            case E_ACUTE_CAPITAL:
                send_unicode_string("É");
                return false;
            case AE_LIGATURE:
                send_unicode_string("æ");
                return false;
            case OE_LIGATURE:
                send_unicode_string("œ");
                return false;
            case OLED_BRI_MAX:
                oled_set_brightness(OLED_BRIGHTNESS_MAX);
                send_unicode_string("É");
                return false; // skip further processing
            case OLED_BRI_MID:
                oled_set_brightness(OLED_BRIGHTNESS_MIDDLE);
                return false; // skip further processing
            case OLED_BRI_DIM:
                oled_set_brightness(OLED_BRIGHTNESS_DIMMED);
                return false; // skip further processing
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
            case _FLÈCHES:
                oled_write_P(PSTR("      fleches\n"), false);
                break;
            case _SOURIS:
                oled_write_P(PSTR("      souris\n"), false);
                break;
            case _FONCTIONS:
                oled_write_P(PSTR("     fonctions\n"), false);
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
