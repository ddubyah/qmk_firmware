#include "planck.h"

#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   P  |   W  |   R  |   A  |   F  |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ent |   D  |   T  |   H  |   E  |   O  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ent  |   Y  |   S  |   N  |   I  |   U  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  Ent |      |  Sym |  Num |SPC/1 |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[0] = {
  {KC_ESC,        KC_P,    KC_W,    KC_R,   KC_A,   KC_F,          _______, _______, _______, _______, _______, _______},
  {KC_ENT,        KC_D,    KC_T,    KC_H,   KC_E,   KC_O,          _______, _______, _______, _______, _______, _______},
  {KC_ENT,        KC_Y,    KC_S,    KC_N,   KC_I,   KC_U,          _______, _______, _______, _______, _______, _______},
  {OSM(MOD_LSFT), KC_ENT,  _______, OSL(2), OSL(2), LT(1, KC_SPC), _______, _______, _______, _______, _______, _______}
},

/* Raise
* ,-----------------------------------------------------------------------------------.
* | Esc  |   J  |   M  |   B  |   '  | TAB  |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Ent  |   V  |   C  |   L  |   Z  |   Q  |      |      |      |      |      |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Caps |   X  |   G  |   K  | App  |  GUI |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | SLock|   .  |      |  Sym |  Num |SPC/1 |      |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[1] = {
  {KC_ESC,           KC_J,    KC_M,    KC_B,    KC_QUOTE, KC_TAB,  _______, _______, _______, _______, _______, _______},
  {KC_ENT,           KC_V,    KC_C,    KC_L,    KC_Z,     KC_Q,    _______, _______, _______, _______, _______, _______},
  {KC_CAPS,          KC_X,    KC_G,    KC_K,    _______,  KC_LGUI, _______, _______, _______, _______, _______, _______},
  {KC_LOCKING_CAPS,  KC_DOT,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______}
},

/* Symbol
* ,-----------------------------------------------------------------------------------.
* | Esc  |   ;  |   :  |   *  |   &  |  ?   |      |      |      |      |      |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Ent  |   _  |   @  |   -  |   !  |   /  |      |      |      |      |      |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Ent  |   {  |   [  |   (  |   <  |   "  |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Shift|  Ent |      |  Sym |  Num |SPC/1 |      |      |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[2] = {
  {KC_ESC,        KC_SCOLON,         KC_SCLN,     LSFT(KC_8), LSFT(KC_7),     LSFT(KC_SLASH), _______, _______, _______, _______, _______, _______},
  {KC_ENT,        LSFT(KC_MINS),     LSFT(KC_2),  KC_MINS,    LSFT(KC_1),     KC_SLASH,       _______, _______, _______, _______, _______, _______},
  {KC_ENT,        LSFT(KC_LBRACKET), KC_LBRACKET, LSFT(KC_9), LSFT(KC_COMMA), LSFT(KC_QUOTE), _______, _______, _______, _______, _______, _______},
  {OSM(MOD_LSFT), KC_ENT,  _______,  _______,     _______,    KC_SPC,         _______, _______, _______, _______, _______, _______}
},


};


#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(IN_LIKE_FLINT);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 1:
      if (record->event.pressed) {
        layer_on(1);
      } else {
        layer_off(1);
      }
      break;
    case 2:
      if (record->event.pressed) {
        layer_on(2);
      } else {
        layer_off(2);
      }
      break;
  }
  return MACRO_NONE;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
