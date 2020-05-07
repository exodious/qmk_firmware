#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _CL 0
#define _QL 1
#define _FL 2

#define ________ KC_TRNS

// CAPS when tapped, FN when held.
#define FN_CAPS LT(_FL, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _CL: Colemak Layer (default)
   * Shift keys are ( and ) when tapped.
   * Caps lock when tapped, FN when held.
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  F|  P|  G|  J|  L|  U|  Y|  ;|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |FNCAPS |  A|  R|  S|  T|  D|  H|  N|  E|  I|  O|  '|Return |Hme |
   * |----------------------------------------------------------------|
   * |LSPO     |  Z|  X|  C|  V|  B|  K|  M|  ,|  .|  /|RSPC | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_CL] = LAYOUT_ansi(
  KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , KC_GRV  , \
  KC_TAB  , KC_Q    , KC_W    , KC_F    , KC_P    , KC_G    , KC_J    , KC_L    , KC_U    , KC_Y    , KC_SCLN , KC_LBRC , KC_RBRC , KC_BSLS , KC_DEL  , \
  FN_CAPS , KC_A    , KC_R    , KC_S    , KC_T    , KC_D    , KC_H    , KC_N    , KC_E    , KC_I    , KC_O    , KC_QUOT ,       KC_ENT      , KC_HOME , \
  KC_LSPO           , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_K    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSPC , KC_UP   , KC_END  , \
  KC_LCTL , KC_LGUI , KC_LALT ,                        KC_SPC                             , KC_RALT , MO(_FL) , KC_RCTRL, KC_LEFT , KC_DOWN , KC_RGHT),

  /* Keymap _QL: Qwerty Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |FNCAPS |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_QL] = LAYOUT_ansi(
  KC_ESC  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , KC_BSPC , KC_GRV  , \
  KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS , KC_DEL  , \
  FN_CAPS , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,       KC_ENT      , KC_PGUP , \
  KC_LSFT           , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_UP   , KC_PGDN , \
  KC_LCTL , KC_LGUI , KC_LALT ,                        KC_SPC                             , KC_RALT , MO(_FL) , KC_RCTRL, KC_LEFT , KC_DOWN , KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |SCLK|F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Del    |Prsc|
   * |----------------------------------------------------------------|
   * |     |MbL|MsU|MbR|   |   |   |   |   |   |   | CL| QL|     |Ins |
   * |----------------------------------------------------------------|
   * |       |MsL|MsD|MsR|   |   |   |   |   |   |   |   |       |PgUp|
   * |----------------------------------------------------------------|
   * |         |   |   |BL-|BL+| BL|   |MUT|VO-|VO+|   |     |MwU|PgDn|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MwL|MwD|MwR |
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  KC_SLCK , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , KC_DEL  , KC_PSCR , \
  ________, KC_BTN1 , KC_MS_U , KC_BTN2 , ________, ________, ________, ________, ________, ________, ________, DF(_CL) , DF(_QL) , ________, KC_INS  , \
  ________, KC_MS_L , KC_MS_D , KC_MS_R , ________, ________, ________, ________, ________, ________, ________, ________, ________          , KC_PGUP , \
  ________          , ________, ________, BL_DEC  , BL_INC  , BL_TOGG , ________, KC_MUTE , KC_VOLD , KC_VOLU , ________, ________, KC_WH_U , KC_PGDN , \
  ________, ________, ________, ________                                                  , ________, ________, ________, KC_WH_L , KC_WH_D , KC_WH_R),
};
