/* Copyright 2023 Paulo Pereira
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  '?  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  +*  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ç  | BACK |
    * |------+------+------+------+------+------| GAME  |    |       |------+------+------+------+------+------|
    * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |   .: |  _-  |Shift |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `-------------------''-------'           '------''--------------------'
    */
    [_QWERTY] = LAYOUT(
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
        KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_BSPC,
        KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, TG(_GAME),  XXXXXXX,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                                   KC_LALT, KC_LGUI, TL_LOWR, KC_SPC,   KC_ENT,   TL_UPPR,  KC_RGUI, KC_RALT
    ),

    /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  |  F11 | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |   ´  |  `   |  ~   |  ^   |      |-------.    ,-------|   <  |   >  |   [  |   ]  |   '  | DEL  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |  <<  |  >|| |  >>  |-------|    |-------|      |      |   {  |   }  |   ?  |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `-------------------''-------'           '------''--------------------'
    */
    [_LOWER] = LAYOUT(
          KC_F1,   KC_F2,         KC_F3,   KC_F4,         KC_F5,   KC_F6,                       KC_F7,        KC_F8,      KC_F9,     KC_F10,        KC_F11,  KC_F12,  
        _______,    KC_1,          KC_2,    KC_3,          KC_4,    KC_5,                        KC_6,         KC_7,       KC_8,       KC_9,          KC_0,  _______,
        _______, KC_RBRC, LSFT(KC_RBRC), KC_QUOT, LSFT(KC_QUOT), _______,                      KC_GRV, LSFT(KC_GRV), LALT(KC_8), LALT(KC_9),       KC_MINS,  KC_DEL,
        _______, KC_LBRC, LALT(KC_2), LALT(KC_3), KC_BSLS, LSFT(KC_BSLS),   _______, _______, _______,      _______,  LSA(KC_8),  LSA(KC_9), LSFT(KC_MINS), _______,
                                                _______, _______, _______,  _______, _______, _______,      _______,     _______
    ),

    /* RAISE
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |  SLU |      |      |                    |      |      |  Up  |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |  WS  |  SWL |  SLD |  SWR |      |-------.    ,-------| JWL  | Left | Down |Right | JWR  |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------| HOME | END  |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `-------------------''-------'           '------''--------------------'
    * 
    *  SL (Select Line) - Up and Down
    *  SW (Select Word) - Left and Right
    *  WS (Window Switch in same app)
    *  JW (Jump Word) Left and Right
    */
    [_RAISE] = LAYOUT(
        XXXXXXX,       XXXXXXX,      XXXXXXX,       XXXXXXX,      XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX,
        XXXXXXX,       XXXXXXX,      XXXXXXX,   LSFT(KC_UP),      XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX,        XXXXXXX, _______,
        _______, SGUI(KC_RBRC), LSA(KC_LEFT), LSFT(KC_DOWN), LSA(KC_RGHT), XXXXXXX,                   LALT(KC_LEFT), KC_LEFT, KC_DOWN, KC_RGHT,  LALT(KC_RGHT), _______,
        _______,       XXXXXXX,      XXXXXXX,       XXXXXXX,      XXXXXXX, XXXXXXX, _______, _______,        KC_HOME, KC_END, XXXXXXX, XXXXXXX,        XXXXXXX, _______,
                                                         _______, _______, _______, _______, _______,  _______, _______, _______
    ),   

    /* ADJUST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      | VOL+ | MUTE | VOL- |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |RGB ON| HUE+ | SAT+ | VAL+ |      | BRG+ |-------.    ,-------|      |  <<  |  >|| |  >>  |      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * | MODE | HUE- | SAT- | VAL- |      | BRG- |-------|    |-------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | RGUI | RAlt | 
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'         
    */

    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, KC_BRIU,                   XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    _______, _______, _______, _______, _______,  _______, _______, _______
    ),

    /* GAME
    * ,-----------------------------------------.         
    * |      |      |      |      |      |      |         
    * |------+------+------+------+------+------|         
    * |      |      |      |      |      |      |         
    * |------+------+------+------+------+------|         
    * |      |      |      |      |      |      |-------. 
    * |------+------+------+------+------+------|       | 
    * |      |      |      |      |      |      |-------| 
    * `-----------------------------------------/       / 
    *                   | LAlt | Space|LOWER | / LGUI  /
    *                   `----------------------------'
    */

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______,  _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,  _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,  _______,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                     _______, KC_SPC, _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_270; // flips the display 90 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM mb_logo[] = {
// 'beard2', 32x100px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x04, 0x1e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfc, 0x3c, 0x0c, 
0x0c, 0x3c, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x1e, 0x06, 0x00, 
0xf8, 0xf0, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x81, 0xc0, 0xc0, 0xc0, 
0xc0, 0xc0, 0xc0, 0xc1, 0x83, 0x83, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0xe0, 0xf8, 
0x03, 0x3f, 0xff, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0x87, 0x83, 0xc1, 0xe1, 0xe0, 
0xe0, 0xe0, 0xe0, 0xc1, 0x83, 0x87, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xfc, 0xfe, 0x3f, 0x07, 
0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0x03, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 
0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
    oled_write_raw_P(mb_logo, sizeof(mb_logo));
    //oled_set_cursor(oled_max_chars()/2,oled_max_lines()/2);
    //oled_write_P(PSTR("R2G"), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
    } else {
        // oled_write(read_logo(), false);
        oled_write_ln_P(PSTR("Mago"), false);
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

