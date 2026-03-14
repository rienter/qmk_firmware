// Taken from here: https://github.com/callum-oakley/qmk_firmware/blob/d63988caaf86217cfddf903c2c32dc042a8ef4da/users/callum/oneshot.c
#include "oneshot.h"

#include QMK_KEYBOARD_H

void update_oneshot(oneshot_state *state, bool *sent_keycode, uint16_t mod, uint16_t trigger, uint16_t keycode, keyrecord_t *record) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            // Trigger keydown
            if (*state == os_up_unqueued) {
                register_code(mod);
            }
            *state = os_down_unused;
        } else {
            // Trigger keyup
            switch (*state) {
                case os_down_unused:
                    // If we didn't use the mod while trigger was held, queue it.
                    *state = os_up_queued;
                    break;
                case os_down_used:
                    // If we did use the mod while trigger was held, unregister it.
                    *state = os_up_unqueued;
                    unregister_code(mod);
                    break;
                default:
                    break;
            }
        }
    } else {
        if (record->event.pressed) {
            if (is_oneshot_cancel_key(keycode) && *state != os_up_unqueued) {
                // Cancel oneshot on designated cancel keydown.
                *state = os_up_unqueued;
                unregister_code(mod);
            }
            if (!is_oneshot_ignored_key(keycode)) {
                // On non-ignored keydown, consider the oneshot used. We
                // immediately send the keycode so that it can have the current
                // modifiers applied.
                switch (*state) {
                    case os_down_unused:
                        if (!*sent_keycode) {
                            register_code16(keycode);
                            *sent_keycode = true;
                        }
                        *state = os_down_used;
                        break;
                    case os_up_queued:
                        if (!*sent_keycode) {
                            register_code16(keycode);
                            *sent_keycode = true;
                        }
                        *state = os_up_unqueued;
                        unregister_code(mod);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
