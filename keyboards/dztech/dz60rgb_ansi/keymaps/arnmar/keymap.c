#include QMK_KEYBOARD_H

enum dz60rgb_layers {
    _BASE,
    _NAV,
    _HDUE,
    _SYM,
    _RGB,
}; 

enum {
    TD_SWE1,
    TD_SWE2,
    TD_SWE3
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SWE1] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, RALT(KC_W)), // å
    [TD_SWE2] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, RALT(KC_A)), // ä
    [TD_SWE3] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, RALT(KC_O)), // ö
};

#define WORD_BK C(KC_LEFT)
#define WORD_FW C(KC_RIGHT)

#define SPC     LT(_SYM, KC_SPACE)
#define CAPS    LT(_NAV, KC_ESCAPE)
#define TAB     LT(_HDUE, KC_TAB)
#define KEY_D   LSFT_T(KC_D)
#define KEY_F   LCTL_T(KC_F)
#define KEY_J   RCTL_T(KC_J)
#define KEY_K   RSFT_T(KC_K)
#define L_ALT   MT(MOD_LALT, KC_QUOTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_ansi(
        KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,
        TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_SWE1), KC_RBRC,   KC_BSLS,
        CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SWE3), TD(TD_SWE2),       KC_ENT,
        KC_LSPO,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_RSPC,
        KC_LCTL,   KC_LGUI, KC_LALT,                            SPC,                                KC_RALT, MO(_NAV), MO(_RGB), KC_RCTL
    ),
    [_NAV] = LAYOUT_60_ansi(
        KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        MO(_RGB), _______, WORD_FW, _______, _______, _______, _______, _______, _______, _______, _______, RALT(KC_W), _______, RESET,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, RALT(KC_O), RALT(KC_A),  _______,
        _______,          _______, _______, _______, _______, WORD_BK, KC_BSPC, KC_BSPC, KC_DEL, KC_DEL, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [_HDUE] = LAYOUT_60_ansi(
        _______, _______, _______,   _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   KC_PSCR, _______, _______, _______,
        _______, _______, _______,   _______, _______, _______, KC_HOME,   KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______,
        _______,          _______,   _______, _______, _______, _______, _______, _______, _______,   _______, _______,          _______,
        _______, _______, _______,                              _______,                              _______, _______, _______, _______
    ),
    [_SYM] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,   _______, _______, _______, _______,
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,    KC_8,    KC_9,      KC_0, _______, _______, _______,
        _______, KC_LBRC,  S(KC_LBRC), S(KC_9), _______, S(KC_QUOT), S(KC_GRV), KC_ENT, S(KC_0), S(KC_RBRC), KC_RBRC,  S(KC_SCLN), _______,
        _______,          _______,  _______, _______, _______, _______, _______, _______, _______,   _______, _______,          _______,
        _______, _______, _______,                              _______,                              _______, _______, _______, _______
    ),
    [_RGB] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, RGB_HUD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
        _______, RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
}; 
