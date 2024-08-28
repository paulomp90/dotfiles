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

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SHIFT_D LSFT_T(KC_D)
#define GUI_F LGUI_T(KC_F)

#define CT LCTL_T(KC_TAB)

// Right-hand home row mods
#define GUI_J RGUI_T(KC_J)
#define SHIFT_K RSFT_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// #define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_SPACE LT(_NUM, KC_SPC)


enum layer_number {
    _QWERTY = 0,
    _SYM,
    _NAV,
    _NUM,
    _ADJ,
    _GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |  ESC |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | REP  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  CT  |CTL_A |ALT_S |SHIFTD|GUI_F |   G  |                    |   H  |GUI_J |SHIFTK|ALT_L | CTL_Ç|BK_DEL|
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | SHIFT|   Z  |   X  |   C  |   V  |   B  |-------.     ,------|   N  |   M  |  ,;  |   .: |  _-  |SHIFT |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                          | LGUI | SYM  | /Space  /       \Enter \  | NAV  |  ADJ |
    *                          |      |      |/ NUM   /         \      \ |      |      |
    *                          '-------------''------'           '------''-------------'
    *
    * CT -> ctrl and tab
    * REP -> repeat last
    *
    */
    [_QWERTY] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,     KC_P, QK_REPEAT_KEY,
             CT,   CTL_A,   ALT_S, SHIFT_D,   GUI_F,     KC_G,                       KC_H,   GUI_J, SHIFT_K,   ALT_L, CTL_SCLN, KC_BSPC,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,     KC_B, XXXXXXX,  XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                                // XXXXXXX, MO(_ADJ), MO(_NAV),  KC_SPC,  NUM_ENT, MO(_SYM), KC_RGUI, XXXXXXX
                                   XXXXXXX, KC_LGUI, MO(_SYM), NUM_SPACE,  KC_ENT, MO(_NAV), MO(_ADJ), XXXXXXX
    ),

    /* SYM
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |   !  |   "@ |  €#  |  $   |  %   |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |   &  |   /  |  (   |  )   |  =   |                    |  ºª  | GUI  | SHIFT| ALT  | CTRL |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |  '?  |  \|  |  [{  |  }]  |  <>  |-------.     ,------|      |   ~  |   ^  |   ´  |  `   |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                          | LGUI | SYM  | /Space  /       \Enter \  | NAV  |  ADJ |
    *                          |      |      |/ NUM   /         \      \ |      |      |
    *                          '-------------''------'           '------''-------------'
    *
    */
    [_SYM] = LAYOUT(
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                    XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX,
        _______, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),                    XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX, _______,
        _______, LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),                    KC_LBRC,    KC_RGUI,       KC_RSFT, KC_RALT,       KC_RCTL, _______,
        _______,    KC_MINS,    KC_BSLS, LALT(KC_8), LALT(KC_9),     KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX,    KC_QUOT, LSFT(KC_QUOT), KC_RBRC, LSFT(KC_RBRC), _______,
                                        XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX
    ),

    /* NAV
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    | PGUP | Home |  Up  | End  |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    | PGDN | Left | Down |Right |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------.     ,------|  WS  | SWL  |      | SWR  |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                          | LGUI | SYM  | /Space  /       \Enter \  | NAV  |  ADJ |
    *                          |      |      |/ NUM   /         \      \ |      |      |
    *                          '-------------''------'           '------''-------------'
    *
    *  WS (Window Switch in same app, mac usage)
    *  SW (Select Word) - Left and Right
    */

    [_NAV] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX,      XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______,                         KC_PGUP,      KC_HOME,   KC_UP,       KC_END, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,                         KC_PGDN,      KC_LEFT, KC_DOWN,      KC_RGHT, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, LGUI(KC_RBRC), LSA(KC_LEFT), XXXXXXX, LSA(KC_RGHT), XXXXXXX, _______,
                                   XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX
    ),

    /* NUM
    *
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |  1   |  2   |  3   |  4   |   5  |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |  6   |  7   |  8   |  9   |   0  |                    |      | GUI  | SHIFT| ALT  | CTRL |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |  +   |  -   |  *   |  /   |   .  |-------.     ,------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                          | LGUI | SYM  | /Space  /       \Enter \  | NAV  |  ADJ |
    *                          |      |      |/ NUM   /         \      \ |      |      |
    *                          '-------------''------'           '------''-------------'
    *
    */

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,    KC_1,    KC_2,         KC_3,       KC_4,    KC_5,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______,    KC_6,    KC_7,         KC_8,       KC_9,    KC_0,                   XXXXXXX, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, _______,
        _______,  KC_EQL, KC_SLSH, LSFT(KC_EQL), LSFT(KC_7),  KC_DOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                         XXXXXXX, _______, _______, _______, _______,  _______, _______, XXXXXXX
    ),

    /* ADJUST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |RGB ON| HUE+ | SAT+ | VAL+ | BRG+ |                    | GAME |  <<  |  >|| |  >>  |  F11 |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      | MODE | HUE- | SAT- | VAL- | BRG- |-------.     ,------|      | VOL+ | MUTE | VOL- |  F12 |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                          | LGUI | SYM  | /Space  /       \Enter \  | NAV  |  ADJ |
    *                          |      |      |/ NUM   /         \      \ |      |      |
    *                          `---------------------'           '------''-------------'
    */

    [_ADJ] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_BRIU,                    TG(_GAME), KC_MPRV, KC_MPLY, KC_MNXT,  KC_F11, _______,
        _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_BRID,  XXXXXXX, XXXXXXX,   XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD,  KC_F12, _______,
                                    XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX
    ),

    /* GAME
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |  Up  |      |      | GAME |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      | Left | Down |Right |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------.     ,------|      |      |      |      |      |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                          | ALT  | SPACE| /  GUI  /       \Enter \  |      | RGUI |
    *                          |      |      |/       /         \      \ |      |      |
    *                          `---------------------'           '------''-------------'
    */

    [_GAME] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
         KC_TAB, _______, _______, _______, _______,  _______,                   XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, TG(_GAME),
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,  _______,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                     XXXXXXX, KC_LALT, KC_SPC, KC_LGUI, KC_ENT, XXXXXXX, _______, XXXXXXX
    )
};

// extract from https://getreuer.info/posts/keyboards/macros3/index.html
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case KC_BSPC: {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
        uint8_t shift_mods = mods & MOD_MASK_SHIFT;

        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }

        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    } return false;

    // Other macros...
  }

  return true;
}

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
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("NAV"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case 4:
            oled_write_ln_P(PSTR("_ADJ"), false);
            break;
        case 5:
            oled_write_ln_P(PSTR("Game"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Unknown"), false);
            break;
    }
}

void oled_render_caps_state(void) {
    // Set cursor position
    oled_set_cursor(0, 1);

    // Caps lock status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);
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
        oled_render_caps_state();
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
    } else {
        // oled_write(read_logo(), false);
        oled_write_ln_P(PSTR("Mago"), false);
        oled_render_logo();
    }
    return false;
}
#endif
// OLED_ENABLE
