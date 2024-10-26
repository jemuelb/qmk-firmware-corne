//
// Created by Jemuel on 10/22/2024.
// qmk compile -kb boardsource/unicorne -km jemuel-home-row

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,          KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    HOME_S,  HOME_D,  HOME_F,    KC_G,          KC_H,    HOME_J,    HOME_K,  HOME_L,  KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,          KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                               KC_LALT, LOWER,     KC_LSFT,       KC_SPC,  RAISE,   KC_LGUI
 ),

 [_LOWER] = LAYOUT(
     KC_GRV,    S(KC_1), S(KC_2), S(KC_3), S(KC_4),    S(KC_5),       KC_7,    KC_8,    KC_9, KC_MINS,    KC_EQL,    KC_BSLS,
     S(KC_GRV), S(KC_6), S(KC_7), S(KC_8), S(KC_9),    S(KC_0),       KC_4,    KC_5,    KC_6, S(KC_MINS), S(KC_EQL), S(KC_BSLS),
     _______,   _______, KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC),    KC_1,    KC_2,    KC_3, _______,    _______,   _______,
                                  _______, _______,    _______,       KC_0,    _______, _______
 ),

 [_RAISE] = LAYOUT(
     _______, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,         KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_DEL,
     _______, KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,
     _______, KC_F11, KC_F12, _______, _______, _______,       _______, KC_APP,  _______, _______, _______, _______,
                              _______, _______, _______,       _______, _______, _______
 ),

  [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,       KC_VOLU, _______, _______, _______, KC_PSCR, _______,
      QK_BOOT, _______, _______, _______, _______, _______,       KC_VOLD, _______, _______, _______, _______, _______,
      _______, _______, _______, KC_CAPS, _______, _______,       KC_MUTE, _______, _______, _______, _______, _______,
                                 _______, _______, _______,       _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 100;
        case LALT_T(KC_S):
            return TAPPING_TERM + 100;
        case LSFT_T(KC_D):
            return TAPPING_TERM + 100;
        case LCTL_T(KC_F):
            return TAPPING_TERM + 100;
        case RCTL_T(KC_J):
            return TAPPING_TERM + 100;
        case RSFT_T(KC_K):
            return TAPPING_TERM + 100;
        case RALT_T(KC_L):
            return TAPPING_TERM + 100;
        case RGUI_T(KC_SCLN):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}