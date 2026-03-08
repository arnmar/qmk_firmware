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
// Home row mods
#define K_A     LGUI_T(KC_A)
#define K_S     LALT_T(KC_S)
#define K_D     LSFT_T(KC_D)
#define K_F     LCTL_T(KC_F)
#define K_J     RCTL_T(KC_J)
#define K_K     RSFT_T(KC_K)
#define K_L     RALT_T(KC_L)
// Bottom row mods
#define K_Z     LGUI_T(KC_Z)
#define K_X     LALT_T(KC_X)
#define K_C     LSFT_T(KC_C)
#define K_V     LCTL_T(KC_V)
#define K_M     RCTL_T(KC_M)
#define K_COMM  RSFT_T(KC_COMM)
#define K_DOT   RALT_T(KC_DOT)
#define L_ALT   MT(MOD_LALT, KC_QUOTE)
#define K_SLSH  LT(_SYM, KC_SLSH)
#define SWE1    TD(TD_SWE1)
#define SWE2    TD(TD_SWE2)
#define SWE3    TD(TD_SWE3)

// Layers
#define DSYM    MO(_SYM)
#define DRGB    MO(_RGB)
#define DNAV    MO(_NAV)

