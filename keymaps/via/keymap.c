 /* Copyright 2020 Bratzworth *
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    LT(1, KC_F1),KC_F2, KC_F3,
    KC_F4,    KC_F5,    KC_F6,
    KC_F7,    KC_F8,    KC_MUTE
  ),
  [1] = LAYOUT(
    _______, KC_F9,     KC_F10,
    KC_F11,   KC_F12,   _______,
    _______,  TO(2),    RESET
  ),
  [2] = LAYOUT(
    _______,  _______,  _______,
    _______,  _______,  _______,
    _______,  TO(3),    RESET
  ),
  [3] = LAYOUT(
    _______,  _______,  _______,
    _______,  _______,  _______,
    _______,  TO(0),    RESET
  )
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code(KC_VOLU);
  } else {
    tap_code(KC_VOLD);
  }
}
#endif

#ifdef OLED_DRIVER_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
        0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
        0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2,
        0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA,
        0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2,
        0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5,
        0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD,
        0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void oled_task_user(void) {
    oled_set_cursor(0,5);
    render_logo();
    oled_set_cursor(0,0);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("first layer"), false);
            oled_write_ln_P(PSTR("-----------"), false);
            oled_write_ln_P(PSTR("FN"), false);
            oled_write_ln_P(PSTR("1  2  3 4  5 6  7  8"), false);
            // oled_write_ln_P(PSTR("123456789012345678901"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("second layer"), false);
            oled_write_ln_P(PSTR("------------"), false);
            oled_write_ln_P(PSTR("FN"), false);
            oled_write_ln_P(PSTR(". 9 10 11 12 . L2  RS"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("third layer"), false);
            oled_write_ln_P(PSTR("-----------"), false);
            oled_write_ln_P(PSTR(""), false);
            oled_write_ln_P(PSTR(". . . . . . . L3 RS"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("fourth layer"), false);
            oled_write_ln_P(PSTR("------------"), false);
            oled_write_ln_P(PSTR(""), false);
            oled_write_ln_P(PSTR(". . . . . . . L0 RS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("undefined"), false);
            oled_write_ln_P(PSTR("\n\n"), false);
    }
}

#endif
