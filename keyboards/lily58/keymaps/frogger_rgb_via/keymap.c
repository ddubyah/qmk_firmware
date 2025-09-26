#include QMK_KEYBOARD_H

enum layer_CMD {
  _QWERTY = 0,
  _SECOND,
  _CMD,
  _SYM,
  _LAYER4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   5  |   4  |   3  |   2  |   1  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   P  |   W  |   R  |   A  |   F  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ENT  |   D  |   T  |   H  |   E  |   O  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|LSHIFT |    |       |------+------+------+------+------+------|
 * | LALT |   Y  |   S  |   N  |   I  |   U  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SYMBOL|NUMBER|SECOND|/ Space  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_5,  KC_4,    KC_3,    KC_2,    KC_1,                      _______, _______, _______, _______, _______, _______,
  KC_LCTL, KC_P,   KC_W,    KC_R,    KC_A,    KC_F,                      _______, _______ , _______, _______, _______, _______,
  KC_ENT,  KC_D,   KC_T,    KC_H,    KC_E,    KC_O,                      _______, _______,    _______, _______, _______, _______,
  KC_LALT, KC_Y,   KC_S,    KC_N,    KC_I,    KC_U, KC_LSFT,         _______, _______, _______, _______, _______,  _______,  _______,
                        MO(_SYM), MO(_CMD), MO(_SECOND), KC_SPC, _______, _______, _______, _______
),

/* SECOND
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   0  |   9  |   8  |   7  |   6  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   J  |   M  |   B  |   '  | TAB  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ENT  |   V  |   C  |   L  |   Z  |   Q  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|LSHIFT |    |       |------+------+------+------+------+------|
 * | LALT |   X  |   G  |   K  |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SYMBOL|NUMBER|SECOND|/ Space  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_SECOND] = LAYOUT(
  KC_ESC,   KC_0,  KC_9,    KC_8,    KC_7,    KC_6,                      _______, _______, _______, _______, _______, _______,
  KC_LCTL, KC_J,   KC_M,    KC_B,    KC_QUOT, KC_TAB,                    _______, _______ , _______, _______, _______, _______,
  KC_DOT,  KC_V,   KC_C,    KC_L,    KC_Z,    KC_Q,                      _______, _______,    _______, _______, _______, _______,
  KC_LALT, KC_X,   KC_G,    KC_K,    _______, _______,  KC_LSFT,         _______, _______, _______, _______, _______,  _______,  _______,
                        MO(_SYM), MO(_CMD), MO(_SECOND), KC_SPC, _______, _______, _______, _______
),

/* CMD - Added RGB Matrix controls on right side
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | F5   | F4   | F3   | F2   | F1   |                    |RGB TO| HUE+ | SAT+ | VAL+ | SPD+ |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL| PGUP | PAUSE| END  | HOME | ESC  |                    |RGB MO| HUE- | SAT- | VAL- | SPD- |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ENT  | PGDN | C_UP | ALT  | CTRL | INS  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|LSHIFT |    |       |------+------+------+------+------+------|
 * | LALT | C_RT | C_DN | C_LT | BKSP | DEL  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SYMBOL|NUMBER|SECOND|/ Space  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_CMD] = LAYOUT(
  KC_ESC,   KC_F5,    KC_F4,    KC_F3,   KC_F2,         KC_F1,                     RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, _______,
  KC_LCTL, KC_PGUP,   KC_PAUSE, KC_END,  KC_HOME,       KC_ESC,                    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, RM_SPDD, _______,
  KC_DOT,  KC_PGDN,   KC_UP,    KC_LALT,    KC_LCTL,    KC_INSERT,                      _______, _______,    _______, _______, _______, _______,
  KC_LALT, KC_RGHT,   KC_DOWN,  KC_LEFT, KC_BACKSPACE,  KC_DELETE,  KC_LSFT,         _______, _______, _______, _______, _______,  _______,  _______,
                        MO(_SYM), MO(_CMD), MO(_SECOND), KC_SPC, _______, _______, _______, _______
),

/* SYMBOL (Combined SYM and SSYM layers)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  | F10  |  F9  |  F8  |  F7  |  F6  |                    |   #  |   $  |   =  |   +  | TAB  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   ;  |   :  |   *  |   &  |  ?   |                    |   ^  |   ~  |   |  |   %  |   \  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ENT  |   _  |   @  |   -  |   !  |   /  |-------.    ,-------|   }  |   ]  |   )  |  >   |  `   |      |
 * |------+------+------+------+------+------|LSHIFT |    |       |------+------+------+------+------+------|
 * | LALT |   {  |   [  |   (  |  <   |  "   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SYMBOL|NUMBER|SECOND|/ Space  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_SYM] = LAYOUT(
  KC_ESC,     KC_F10,               KC_F9,            KC_F8,          KC_F7,                    KC_F6,                            KC_HASH,              KC_DOLLAR,        KC_EQUAL,    KC_PLUS, KC_TAB, _______,
  KC_LCTL,    KC_SCLN,              KC_COLON,         KC_ASTERISK,    KC_AMPERSAND,             KC_QUESTION,                      KC_CIRCUMFLEX,        KC_TILDE,         KC_PIPE,       KC_PERCENT, KC_BACKSLASH, _______,
  KC_COMMA,   KC_UNDERSCORE,        KC_AT,            KC_MINUS,       KC_EXCLAIM,               KC_SLASH,                         KC_RIGHT_CURLY_BRACE,  KC_RIGHT_BRACKET,  KC_RPRN, KC_RIGHT_ANGLE_BRACKET, KC_GRAVE, _______,
  KC_LALT,    KC_LEFT_CURLY_BRACE,  KC_LEFT_BRACKET,  KC_LPRN,     KC_LEFT_ANGLE_BRACKET,    KC_DOUBLE_QUOTE, KC_LSFT,         _______, _______, _______, _______, _______,  _______,  _______,
                        MO(_SYM), MO(_CMD), MO(_SECOND), KC_SPC, _______, _______, _______, _______
),

/* LAYER4 (Copy of SECOND layer)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   0  |   9  |   8  |   7  |   6  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   J  |   M  |   B  |   '  | TAB  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ENT  |   V  |   C  |   L  |   Z  |   Q  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|LSHIFT |    |       |------+------+------+------+------+------|
 * | LALT |   X  |   G  |   K  |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |SYMBOL|NUMBER|SECOND|/ Space  /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_LAYER4] = LAYOUT(
  KC_ESC,   KC_0,  KC_9,    KC_8,    KC_7,    KC_6,                      _______, _______, _______, _______, _______, _______,
  KC_LCTL, KC_J,   KC_M,    KC_B,    KC_QUOT, KC_TAB,                    _______, _______ , _______, _______, _______, _______,
  KC_DOT,  KC_V,   KC_C,    KC_L,    KC_Z,    KC_Q,                      _______, _______,    _______, _______, _______, _______,
  KC_LALT, KC_X,   KC_G,    KC_K,    _______, _______,  KC_LSFT,         _______, _______, _______, _______, _______,  _______,  _______,
                        MO(_SYM), MO(_CMD), MO(_SECOND), KC_SPC, _______, _______, _______, _______
)
};

// OLED setup and functions
#ifdef OLED_ENABLE

const char *read_layer_state(void);
const char *read_logo(void);
const char *read_keylog(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_rgb_state(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Layer information
        oled_write_ln(read_layer_state(), false);

        // RGB status
#ifdef RGB_MATRIX_ENABLE
        if (rgb_matrix_is_enabled()) {
            char rgb_info[32];
            snprintf(rgb_info, sizeof(rgb_info), "RGB: ON Mode:%d", rgb_matrix_get_mode());
            oled_write_ln(rgb_info, false);
            
            // HSV values
            HSV hsv = rgb_matrix_get_hsv();
            char hsv_info[32];
            snprintf(hsv_info, sizeof(hsv_info), "H:%d S:%d V:%d", hsv.h, hsv.s, hsv.v);
            oled_write_ln(hsv_info, false);
        } else {
            oled_write_ln("RGB: OFF", false);
        }
#endif

        // Key logging
        oled_write_ln(read_keylog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
  }
  return true;
}

#endif // OLED_ENABLE