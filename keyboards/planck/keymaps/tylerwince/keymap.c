#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  TOGGLE_LAYER_COLOR,
};

enum planck_layers {
  _DVORAK,
  _NUMBER,
  _SYMBOL,
  _FUNCTION,
  _MOUSE,
  _QWERTY,
};

//Tap Dance Declarations
enum {
  TD_SEMI_COLON,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SEMI_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define CTLESC LCTL_T(KC_ESCAPE)
#define NumA LT(_NUMBER, KC_A)
#define SymO LT(_SYMBOL, KC_O)
#define MseE LT(_MOUSE, KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_planck_grid(
            /* _DVORAK
             * ,-----------------------------------------------------------------------------------.
             * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |CtlEsc|A/Num |O/Sym |E/Mse |   U  |   I  |   D  |   H  |   T  |   N  |   S  | Bksp |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |Func  |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      | Ctrl | Alt  | GUI  |      |     Space   | Ctrl | GUI  |      |      |      |
             * `-----------------------------------------------------------------------------------'
             */
          KC_TAB,        KC_QUOTE,          KC_COMMA, KC_DOT,  KC_P,    KC_Y,     KC_F,  KC_G,    KC_C,    KC_R,    KC_L,    KC_SLASH,
          CTLESC,        NumA,              SymO,     MseE,    KC_U,    KC_I,     KC_D,  KC_H,    KC_T,    KC_N,    KC_S,    KC_BSPACE,
          MO(_FUNCTION), TD(TD_SEMI_COLON), KC_Q,     KC_J,    KC_K,    KC_X,     KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENTER,
          _______,       KC_LCTRL,          KC_LALT,  KC_LGUI, KC_LSFT, KC_SPACE, KC_NO, KC_RCTL, KC_RGUI, _______, _______, _______
          ),

  [_NUMBER] = LAYOUT_planck_grid(
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
          KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_SPACE, KC_NO, KC_PEQL, KC_0, KC_PENT, KC_PMNS, KC_NO
          )

  [_SYMBOL] = LAYOUT_planck_grid(
            /* _SYMBOL
             * ,-----------------------------------------------------------------------------------.
             * |      |      |      |      |      |  (   |  )   |  &   |  *   |  -   |  _   |      |
             * |------+------+------+------+------+-------------+------+------+------+------+------|
             * |      |      | Sym  |      |      |  {   |  }   |  $   |  %   |  ^   |  =   |      |
             * |------+------+------+------+------+------|------+------+------+------+------+------|
             * |      |      |      |      |      |  [   |  ]   |  !   |  @   |  #   |  +   |      |
             * |------+------+------+------+------+------+------+------+------+------+------+------|
             * |      |      |      |      |      |    Space    |      |      |      |  -   |      |
             * `-----------------------------------------------------------------------------------'
             */

          KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_LPRN,  KC_RPRN, KC_AMPR, KC_ASTR, KC_MINS, KC_UNDS, KC_NO,
          KC_NO, KC_NO, _______, KC_NO, KC_NO, KC_LCBR,  KC_RCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_NO,
          KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_LBRC,  KC_RBRC, KC_EXLM, KC_AT,   KC_HASH, KC_PLUS, KC_NO,
          KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO, KC_SPACE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS, KC_NO
          ),

  [_MOUSE] = LAYOUT_planck_grid(
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
          KC_NO, KC_NO, KC_NO, KC_NO,   KC_BTN1, KC_SPACE, KC_NO, KC_BTN2, KC_NO,   KC_NO,   KC_NO, KC_NO
          ),

  [_FUNCTION] = LAYOUT_planck_grid(
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

          RESET,   KC_NO, KC_NO, KC_NO,            KC_NO,            LALT(LCTL(KC_7)), LALT(LCTL(KC_8)), KC_NO,            KC_NO, KC_NO, LALT(LCTL(KC_L)), KC_NO, 
          KC_NO,   KC_NO, KC_NO, KC_NO,            KC_NO,            LALT(LCTL(KC_U)), LALT(LCTL(KC_I)), LALT(LCTL(KC_H)), KC_NO, KC_NO, KC_NO,            KC_NO,          
          _______, KC_NO, KC_NO, LALT(LCTL(KC_J)), LALT(LCTL(KC_K)), KC_NO,            KC_NO,            KC_NO,            KC_NO, KC_NO, KC_NO,            LALT(LCTL(KC_ENTER)),
          TO(0),   TO(4), KC_NO, KC_NO,            KC_NO,            KC_SPACE,         KC_NO,            KC_NO,            KC_NO, KC_NO, KC_NO,            KC_NO
          ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;
bool disable_layer_color = 0;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {32,255,234}, {32,255,234}, {12,225,241}, {12,225,241}, {0,204,255}, {0,204,255}, {169,120,255}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255},
            {32,255,234}, {32,255,234}, {12,225,241}, {12,225,241}, {0,204,255}, {0,204,255}, {169,120,255}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255},
            {32,255,234}, {32,255,234}, {12,225,241}, {12,225,241}, {0,204,255}, {0,204,255}, {169,120,255}, {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255}, 
            {32,255,234}, {32,255,234}, {12,225,241}, {12,225,241}, {0,204,255}, {0,0,0},     {169,120,255}, {169,120,255}, {146,224,255}, {146,224,255}, {146,224,255} },

    [1] = { {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255},
            {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255},
            {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,0,0},     {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255},
            {0,0,0},     {0,204,255}, {0,204,255}, {0,204,255}, {0,204,255}, {0,0,0},     {0,0,0},     {0,0,0},     {0,204,255}, {0,204,255}, {0,0,0} },

    [2] = { {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {0,0,0},
            {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {169,120,255}, {0,0,0}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255},
            {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0},
            {169,120,255}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {169,120,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255}, {105,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || disable_layer_color) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 4:
      set_layer_color(4);
      break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case RGB_TOG:
  if (record->event.pressed) {
    if (rgb_matrix_config.val) {
      rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 0);
    } else {
      rgb_matrix_sethsv(rgb_matrix_config.hue, rgb_matrix_config.sat, 255);
    }
  }
  return false;
    case TOGGLE_LAYER_COLOR:
      if (record->event.pressed) {
        disable_layer_color ^= 1;
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    palClearPad(GPIOB, 8);
    palClearPad(GPIOB, 9);
    uint8_t layer = biton32(state);
    switch (layer) {
        case _NUMBER:
            palSetPad(GPIOB, 9);
            break;
        case _MOUSE:
            palSetPad(GPIOB, 8);
            break;
        case _FUNCTION:
            palSetPad(GPIOB, 9);
            palSetPad(GPIOB, 8);
            break;
        default:
            break;
    }
    return update_tri_layer_state(state, _NUMBER, _MOUSE, _FUNCTION);
}
