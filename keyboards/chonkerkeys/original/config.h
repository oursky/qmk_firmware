/*
Copyright 2021 Chonkerkeys

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

#include "config_common.h"

/* USB Device descriptor parameter */
/* Vendor ID is 13616 */
#define VENDOR_ID    0x3530
#define PRODUCT_ID   0x0001
#define DEVICE_VER   0x0001
#define MANUFACTURER Chonkerkeys

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 4

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { D1, D2 }
#define MATRIX_COL_PINS { F7, F6, F5, F4 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define RGB_STRANDS_NUM 8        // number of strands
#define RGB_STRAND_LIMIT_VAL 200 // for limiting max current otherwise it will malfunction

#define RGB_STRAND_0_DI_PIN B6
#define RGB_STRAND_0_NUM 4

#define RGB_STRAND_1_DI_PIN B2
#define RGB_STRAND_1_NUM 4

#define RGB_STRAND_2_DI_PIN B3
#define RGB_STRAND_2_NUM 7

#define RGB_STRAND_3_DI_PIN B1
#define RGB_STRAND_3_NUM 4

#define RGB_STRAND_4_DI_PIN B5
#define RGB_STRAND_4_NUM 4

#define RGB_STRAND_5_DI_PIN B4
#define RGB_STRAND_5_NUM 4

#define RGB_STRAND_6_DI_PIN E6
#define RGB_STRAND_6_NUM 5

#define RGB_STRAND_7_DI_PIN D7
#define RGB_STRAND_7_NUM 5

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
