#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layer_names {
  _DVORAK,
  _NUMBER,
  _SYMBOL,
  _MOUSE,
  _ARROW,
  _FUNCTION,
};

//Tap Dance Declarations
enum {
  TD_SEMI_COLON,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SEMI_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};
#define CTLESC LCTL_T(KC_ESCAPE)
#define NumA LT(_NUMBER, KC_A)
#define SymO LT(_SYMBOL, KC_O)
#define MseE LT(_MOUSE, KC_E)
#define ArwU LT(_ARROW, KC_U)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT(
            /* _DVORAK
             * ,-----------------------------------------------------------------------------------.
             * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |CtlEsc|A/Num |O/Sym |E/Mse |U/Arw |   I  |   D  |   H  |   T  |   N  |   S  | Bksp |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * | Func |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      | Ctrl | Alt  | LGUI |Shift |     Space   | RGUI | Shift| Alt  | Ctrl |      |
             * `-----------------------------------------------------------------------------------'
             */
          KC_TAB,         KC_QUOTE,          KC_COMMA, KC_DOT,  KC_P,    KC_Y,     KC_F,  KC_G,    KC_C,    KC_R,    KC_L,  KC_SLASH,
          CTLESC,         NumA,              SymO,     MseE,    ArwU,    KC_I,     KC_D,  KC_H,    KC_T,    KC_N,    KC_S,  KC_BSPACE,
          OSL(_FUNCTION), TD(TD_SEMI_COLON), KC_Q,     KC_J,    KC_K,    KC_X,     KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,  KC_ENTER,
          _______,        KC_LCTRL,          KC_LALT,  KC_LGUI, KC_LSFT, KC_SPACE, KC_SPACE, KC_RGUI, KC_RSFT, KC_RALT, KC_RCTRL, _______
          ),

  [_NUMBER] = LAYOUT(
            /* _NUMBER
             * ,-----------------------------------------------------------------------------------.
             * |      |      |      |      |      |      |      |   7  |   8  |   9  |  *   |      |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |      | Num  |      |      |      |      |      |   4  |   5  |   6  |  /   |      |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |      |      |      |      |      |      |      |   1  |   2  |   3  |  +   |      |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      |      |      |      |      |    Space    |   =  |   0  |Enter |  -   |      |
             * `-----------------------------------------------------------------------------------'
             */
          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_7,    KC_8, KC_9,    KC_PAST, KC_NO,
          KC_NO, _______, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_4,    KC_5, KC_6,    KC_PSLS, KC_NO,
          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_1,    KC_2, KC_3,    KC_PPLS, KC_NO,
          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_SPACE, KC_SPACE, KC_PEQL, KC_0, KC_PENT, KC_PMNS, KC_NO
          ),

  [_SYMBOL] = LAYOUT(
            /* _SYMBOL
             * ,-----------------------------------------------------------------------------------.
             * |      |      |      |      |      |  (   |  )   |  &   |  *   |  -   |  _   |  `   |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |      |      | Sym  |      |      |  {   |  }   |  $   |  %   |  ^   |  =   |  ~   |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |      |      |      |      |      |  [   |  ]   |  !   |  @   |  #   |  +   |  \   |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      |      |      |      |      |    Space    |      |      |      |  -   |  |   |
             * `-----------------------------------------------------------------------------------'
             */

          KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_LPRN,  KC_RPRN, KC_AMPR, KC_ASTR, KC_MINS, KC_UNDS, KC_GRV,
          KC_NO, KC_NO, _______, KC_NO, KC_NO, KC_LCBR,  KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_TILD,
          KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_LBRC,  KC_RBRC, KC_EXLM, KC_AT,   KC_HASH, KC_PLUS, KC_BSLS,
          KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_SPACE, KC_SPACE,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_PIPE
          ),

  [_MOUSE] = LAYOUT(
            /* _MOUSE
             * ,-----------------------------------------------------------------------------------.
             * |      |      |      |      |      |      |      |ScrlUp|MseUp |ScrlDn|      |      |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |      |      |      | Mse  |      |      |      |MseLft|MseDn |MseRgt|      |      |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |      |      |      |      |      |      |      |      |      |      |      |      |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      |      |      |      |MseBt1|    Space    |MseBt2|      |      |      |      |
             * `-----------------------------------------------------------------------------------'
             */

          KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_WH_U, KC_MS_U, KC_WH_D, KC_NO, KC_NO, 
          KC_NO, KC_NO, KC_NO, _______, KC_NO,   KC_NO,    KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO,          
          KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO,   KC_BTN1, KC_SPACE, KC_SPACE, KC_BTN2, KC_NO,   KC_NO,   KC_NO, KC_NO
          ),

  [_ARROW] = LAYOUT(
            /* _ARROW
             * ,-----------------------------------------------------------------------------------.
             * |      |      |      |      |      |      |      |      |      |      |      |      |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |      |      |      |      | Arw  |      | LEFT | DOWN |  UP  |RIGHT |      |      |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |      |      |      |      |      |      |      |      |      |      |      |      |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      |      |      |      |      |    Space    |      |      |      |      |      |
             * `-----------------------------------------------------------------------------------'
             */

          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, 
          KC_NO, KC_NO, KC_NO, KC_NO, _______, KC_NO,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,          
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_SPACE, KC_SPACE,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO
          ),

  [_FUNCTION] = LAYOUT(
            /* _FUNCTION
             * ,-----------------------------------------------------------------------------------.
             * |Reset |      |      |      |      |WIN-TL|WIN-TR|      |      |      |WIN-R |      |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |      |      |      |      |      |WIN-BL|WIN-BR|WIN-L |      |      |      |      |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |Func  |      |      |WIN-B |WIN-T |      |      |      |      |      |      |      |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * | BASE |LAYER4|      |      |      |    Space    |      |      |      |      |      |
             * `-----------------------------------------------------------------------------------'
             */

          RESET,   KC_NO,   KC_NO, KC_NO,            KC_NO,            LALT(LCTL(KC_7)), LALT(LCTL(KC_8)), KC_NO,            KC_NO, KC_NO, LALT(LCTL(KC_L)), RGB_TOG, 
          KC_NO,   KC_NO,   KC_NO, KC_NO,            KC_NO,            LALT(LCTL(KC_U)), LALT(LCTL(KC_I)), LALT(LCTL(KC_H)), KC_NO, KC_NO, KC_NO,            KC_NO,          
          _______, KC_NO,   KC_NO, LALT(LCTL(KC_J)), LALT(LCTL(KC_K)), KC_NO,            KC_NO,            KC_NO,            KC_NO, KC_NO, KC_NO,            LALT(LCTL(KC_ENTER)),
          _______, _______, KC_NO, KC_NO,            KC_NO,            KC_SPACE,         KC_SPACE,            KC_NO,            KC_NO, KC_NO, KC_NO,            KC_NO
          )


};

