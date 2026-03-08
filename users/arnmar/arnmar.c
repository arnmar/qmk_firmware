#include QMK_KEYBOARD_H
#include "arnmar.h"

combo_t key_combos[] = {
    COMBO(kl_ent, KC_ENT),
    COMBO(jk_bspc, KC_BSPC), // keycodes with modifiers are possible too!
    COMBO(df_del, KC_DEL), // keycodes with modifiers are possible too!
    COMBO(sd_tab, KC_TAB) // keycodes with modifiers are possible too!
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SWE1] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, RALT(KC_W)), // å
    [TD_SWE2] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, RALT(KC_A)), // ä
    [TD_SWE3] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, RALT(KC_O))  // ö
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    if (!record->event.pressed)
        return true;

    switch (keycode) {
        case D_COLON:
            if (record->event.pressed) {
                SEND_STRING("::");
            }
            else {
            }
            break;
        case ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            else {
            }
            break;
    }
    return true;
}
