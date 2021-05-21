 /* Copyright 2020 Bratzworth 
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBEEF
#define PRODUCT_ID      0x0008
#define DEVICE_VER      0x0001
#define MANUFACTURER    xkonni
#define PRODUCT         xk9

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* pin-out */
#define MATRIX_ROW_PINS { D4, C6, D7 }
#define MATRIX_COL_PINS { E6, B5, B4 }

#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* BACKLIGHT */
#define RGB_DI_PIN F6

#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_HUE_STEP 10
// #define RGBLIGHT_SAT_STEP 17
// #define RGBLIGHT_VAL_STEP 17


/* DISPLAY */
#define OLED_DISPLAY_128X64

/* VIAL */
#define VIAL_KEYBOARD_UID {0x41, 0x9E, 0x6F, 0x87, 0xCD, 0xAD, 0x8F, 0xEA}
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#define VIAL_ENCODER_KEYCODE_DELAY 25
