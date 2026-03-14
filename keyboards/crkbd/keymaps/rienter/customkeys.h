#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    // Switch app: cmd+tab on Mac, alt+tab on Win
    SW_APP = SAFE_RANGE,
    // Switch window: cmd+` (just for Mac since Windows doesn't have something like this)
    SW_WIN,
    // Close window: cmd+w on Mac, ctrl+w on Windows
    CLS_WIN,
    // (, or { based on which modifier is held
    KC_LEFT_ENCLOSE,
    // ), or } based on which modifier is held
    KC_RIGHT_ENCLOSE,

    // Evaluate selection in VSCode (ctrl+shift+E or cmd+shift+E)
    VSC_EVAL,

    // Type three backticks at once
    KC_3GRV,

    // Ctrl+backspace on Windows, alt+backspace on Mac
    KC_DWRD,

    // Mac/Windows variants for common commands
    MW_UNDO,
    MW_CUT,
    MW_COPY,
    MW_PSTE,
    MW_REDO,
    MW_NWTB,   // new tab or window (ctrl+T or ctrl+N)
    MW_MKLNK,  // make link (ctrl+K)
    MW_SELECT_ALL, // select all (ctrl+A)

    // Previous/next/new tabs in most editors/programs
    PRV_TAB,
    NXT_TAB,

    // Colon on its own, semicolon when shift is pressed. In this sense, it's
    // reversed from the regular colon key. I did this for my number layer where
    // I type colons much, much more frequently than semicolons.
    REV_COLON,

    // One-shot (Callum) mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};
