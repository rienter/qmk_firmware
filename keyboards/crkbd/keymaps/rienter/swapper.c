// Taken from here: https://github.com/callum-oakley/qmk_firmware/tree/d63988caaf86217cfddf903c2c32dc042a8ef4da/users/callum
#include "swapper.h"

#include QMK_KEYBOARD_H
#include "customkeys.h"

bool is_swapper_ignored_key(uint16_t keycode, uint16_t tabish) {
    // Cmd+` should only ignore shift since it doesn't spawn a UI and just
    // immediately switches windows.
    if (tabish == KC_GRV) {
        return keycode == KC_LSFT || keycode == OS_SHFT;
    }

    // For other "tabish" keycodes like tab itself, the arrow keys and shift
    // shouldn't count since they're typically used to help navigate in a
    // typical window-switching scenario.
    switch (keycode) {
        case KC_LSFT:
        case OS_SHFT:
        case KC_UP:
        case KC_LEFT:
        case KC_DOWN:
        case KC_RGHT:
            return true;
        default:
            return false;
    }
}

void update_swapper(bool *active, uint16_t cmdish, uint16_t tabish, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            // Don't unregister cmdish until some other key is hit or released.
            unregister_code(tabish);
        }
    } else if (*active && !is_swapper_ignored_key(keycode, tabish)) {
        unregister_code(cmdish);
        *active = false;
    }
}
