#include QMK_KEYBOARD_H

#include "keymap_slovenian.h"
#include "sendstring_slovenian.h"

enum custom_keycodes
{
    CALC
    , WORD
    , PPT
    , EXCEL
    , SOLIDWORKS
    , VSCODE
    , DISCORD
    , CHROME
    , WINSCR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [0] = LAYOUT_ortho_3x3(
        CALC,   SOLIDWORKS,   VSCODE,
        WORD,  PPT, EXCEL,
        DISCORD,   CHROME,   WINSCR
    )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
        case CALC:
            if (record->event.pressed)
            {
                SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "calc" SS_TAP(X_ENTER));
            }
            else
            {
                // key released
            }
            return false;
        case WORD:
            if (record->event.pressed)
            {
                // Open Microsoft Word via Win+R -> winword
                SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "winword" SS_TAP(X_ENTER));
            }
            return false;
        case PPT:
            if (record->event.pressed)
            {
                // Open Microsoft PowerPoint via Win+R -> powerpnt
                SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "powerpnt" SS_TAP(X_ENTER));
            }
            return false;
        case EXCEL:
            if (record->event.pressed)
            {
                // Open Microsoft Excel via Win+R -> excel
                SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "excel" SS_TAP(X_ENTER));
            }
            return false;
        case SOLIDWORKS:
            if (record->event.pressed)
            {
                // Open SolidWorks via Start menu: tap Win, type display name, Enter
                // More reliable than short command names when application isn't on PATH
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "SolidWorks" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;
        case VSCODE:
            if (record->event.pressed)
            {
                // Open VS Code via Win+R -> code (ensure 'code' is on PATH) or use full path
                SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "code" SS_TAP(X_ENTER));
            }
            return false;
        case DISCORD:
            if (record->event.pressed)
            {
                // Open Discord via Start menu: tap Win, type display name, Enter
                SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(150) "Discord" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;
        case CHROME:
            if (record->event.pressed)
            {
                // Open Google Chrome via Win+R -> chrome
                SEND_STRING(SS_DOWN(X_LGUI)  SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "chrome" SS_TAP(X_ENTER));
            }
            return false;
        case WINSCR:
            if (record->event.pressed)
            {
                // Press Win+PrintScreen to take a full-screen screenshot on Windows
                register_code(KC_LGUI);
                tap_code(KC_PSCR);
                unregister_code(KC_LGUI);
            }
            return false;
    }
    return true;

}
