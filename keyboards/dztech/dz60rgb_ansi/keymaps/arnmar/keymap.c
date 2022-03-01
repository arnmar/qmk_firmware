#include QMK_KEYBOARD_H

enum dz60rgb_layers {
    _BASE,
    _NAV,
    _SYM,
    _RGB,
    _GAME,
}; 

enum custom_keycodes {
  SWE_AA = SAFE_RANGE,
  SWE_AE,
  SWE_OE,
  ARROW,
  DOUBLE_COLON
};

char *alt_codes[][2] = {
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_9)), // Alt+0229 → å
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_7)), // Alt+0197 → Å
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_8)), // Alt+0228 → ä
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_1)SS_TAP(X_KP_9)SS_TAP(X_KP_6)), // Alt+0196 → Ä
    },
    {
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_4)SS_TAP(X_KP_6)), // Alt+0246 → ö
        SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_1)SS_TAP(X_KP_4)), // Alt+0214 → Ö
    },
};

enum {
    TD_SWE1,
    TD_SWE2,
    TD_SWE3
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SWE1] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, RALT(KC_W)), // å
    [TD_SWE2] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, RALT(KC_A)), // ä
    [TD_SWE3] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, RALT(KC_O))  // ö
};

#define WORD_BK C(KC_LEFT)
#define WORD_FW C(KC_RIGHT)
#define YANK C(KC_INS)
#define PASTE S(KC_INS)

#define SPC     LT(_NAV, KC_SPACE)
#define CAPS    MT(MOD_LCTL, KC_ESC)
#define KEY_D   LSFT_T(KC_D)
#define KEY_F   LCTL_T(KC_F)
#define KEY_J   RCTL_T(KC_J)
#define KEY_K   RSFT_T(KC_K)
#define L_ALT   MT(MOD_LALT, KC_QUOTE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_ansi(
        KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(TD_SWE1), KC_RBRC,   KC_BSLS,
        CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_SWE3), TD(TD_SWE2),       KC_ENT,
        KC_LSPO,            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,       KC_RSPC,
        KC_LCTL,   KC_LGUI, KC_LALT,                            SPC,                                KC_RALT, MO(_SYM), MO(_RGB), KC_RCTL
    ),
    [_NAV] = LAYOUT_60_ansi(
        KC_GESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, _______, WORD_FW, _______, _______, _______,    YANK, KC_BSPC,  KC_INS, _______,   PASTE, _______, _______,   RESET,
           CAPS, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_ENT, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, _______, _______,         _______,
        _______,          _______, _______, _______, _______, WORD_BK, KC_SPACE, KC_DEL, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, DF(_GAME), _______, _______
    ),
    [_SYM] = LAYOUT_60_ansi(
        KC_GESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_GRV,S(KC_GRV), DOUBLE_COLON, ARROW, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, RALT(KC_O), RALT(KC_A),  _______,
        _______,          _______, _______, _______, _______, WORD_BK, _______, KC_BSPC,  KC_DEL, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [_RGB] = LAYOUT_60_ansi(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, RGB_TOG, RGB_HUD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, RESET,
        _______, RGB_RMOD, RGB_MOD, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    ),
    [_GAME] = LAYOUT_60_ansi(
        KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, DF(_BASE),   MO(2),   KC_RCTL
    ),
}; 

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed) 
        return true;

    switch (keycode) {
        case SWE_AA: 
        case SWE_AE: 
        case SWE_OE: {
            uint16_t index = keycode - SWE_AA;
            uint8_t shift = get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));

            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);

            SEND_STRING(SS_LALT(SS_TAP(X_KP_0)SS_TAP(X_KP_2)SS_TAP(X_KP_2)SS_TAP(X_KP_9)));
            send_string(alt_codes[index][(bool)shift]);

            if (shift & MOD_BIT(KC_LSFT)) register_code(KC_LSFT);
            if (shift & MOD_BIT(KC_RSFT)) register_code(KC_RSFT);

            return false;
        }
        case DOUBLE_COLON:
            if (record->event.pressed) {
                SEND_STRING("::");
            } else {
            }
            break;
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            } else {
            }
            break;
    }
    return true;
}