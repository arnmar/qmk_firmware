#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _HDUE,
    _SYM,
    _RGB,
    _GAME,
    _NUM,
};

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    D_COLON,
    M_DQUOT, // ""|  (auto-pair)
    M_BRACK, // []|  (auto-pair)
    M_CBRAC, // {}|  (auto-pair)
    M_PAREN  // ()|  (auto-pair)
};

const uint16_t PROGMEM kl_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_bspc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_del[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sd_tab[] = {KC_S, KC_D, COMBO_END};

enum {
    TD_SWE1,
    TD_SWE2,
    TD_SWE3
};

#define WORD_BK C(KC_LEFT)
#define WORD_FW C(KC_RIGHT)
#define YANK    C(KC_INS)
#define PASTE   S(KC_INS)

#define SPC     LT(_NAV, KC_SPACE)
#define CAPS    MT(MOD_LCTL, KC_ESC)
#define TAB     LT(_HDUE, KC_TAB)
#define _LGUI   LT(_NUM, KC_LGUI)

#define K_Q     KC_Q
#define K_W     KC_W
#define K_E     LSFT_T(KC_E)
#define K_R     LCTL_T(KC_R)
#define K_T     KC_T
#define K_Y     KC_Y
#define K_U     RCTL_T(KC_U)
#define K_I     RSFT_T(KC_I)
#define K_O     KC_O
#define K_P     KC_P

#define K_A     LT(_SYM, KC_A)
#define K_S     KC_S
#define K_D     KC_D
#define K_F     KC_F
#define K_G     KC_G
#define K_H     KC_H
#define K_J     KC_J
#define K_K     KC_K
#define K_L     KC_L

#define K_Z     KC_Z
#define K_X     KC_X
#define K_C     KC_C
#define K_V     KC_V
#define K_B     KC_B
#define K_N     KC_N
#define K_M     KC_M
#define K_COMM  KC_COMM
#define K_DOT   KC_DOT
#define L_ALT   MT(MOD_LALT, KC_QUOTE)
#define K_SLSH  LT(_SYM, KC_SLSH)

#define SWE1    TD(TD_SWE1)
#define SWE2    TD(TD_SWE2)
#define SWE3    TD(TD_SWE3)

// Layers
#define DSYM    MO(_SYM)
#define DRGB    MO(_RGB)
#define DNAV    MO(_NAV)

