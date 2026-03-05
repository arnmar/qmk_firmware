#pragma once

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
  D_COLON
};

const uint16_t PROGMEM kl_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_bspc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM df_del[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sd_tab[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[] = {
    COMBO(kl_ent, KC_ENT),
    COMBO(jk_bspc, KC_BSPC), // keycodes with modifiers are possible too!
    COMBO(df_del, KC_DEL), // keycodes with modifiers are possible too!
    COMBO(sd_tab, KC_TAB) // keycodes with modifiers are possible too!
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

tap_dance_action_t tap_dance_actions[] = {
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
#define TAB     LT(_HDUE, KC_TAB)
#define _LGUI   LT(_NUM, KC_LGUI)
// Home row mods
#define K_A   LGUI_T(KC_A)
#define K_S   LALT_T(KC_S)
#define K_D   LSFT_T(KC_D)
#define K_F   LCTL_T(KC_F)
#define K_J   RCTL_T(KC_J)
#define K_K   RSFT_T(KC_K)
#define K_L   RALT_T(KC_L)
// Bottom row mods
#define K_Z   LGUI_T(KC_Z)
#define K_X   LALT_T(KC_X)
#define K_C   LSFT_T(KC_C)
#define K_V   LCTL_T(KC_V)
#define K_M   RCTL_T(KC_M)
#define K_COMM RSFT_T(KC_COMM)
#define K_DOT  RALT_T(KC_DOT)
#define L_ALT   MT(MOD_LALT, KC_QUOTE)
#define SWE1    TD(TD_SWE1)
#define SWE2    TD(TD_SWE2)
#define SWE3    TD(TD_SWE3)

#define DSYM    MO(_SYM)
#define DRGB    MO(_RGB)
#define DNAV    MO(_NAV)

