#include QMK_KEYBOARD_H
#include <sendstring_french_mac_iso.h>

// KBD75
// #define VENDOR_ID       0x4B42
// #define PRODUCT_ID      0x6061
// #define DEVICE_VER      0x0002

// Magic Keyboard 2nd gen A2450
// #define VENDOR_ID       0x05ac
// #define MANUFACTURER    Apple Inc.
// #define PRODUCT         Magic Keyboard
// #define PRODUCT_ID      0x029c
// #define DEVICE_VER      0x0320
// #define SERIAL_NUMBER   F0T129502BZ13FDAX

// Apple Keyboard with Numeric Keypad A1243
// #define VENDOR_ID       0x05ac
// #define PRODUCT_ID      0x024f

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    DICTATION,
    SPOTLIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_APFN,  KC_DEL,   MO(1),
    KC_NUBS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_DEL,   KC_BSPC,  KC_HOME,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                      KC_ENT,   KC_PGDN,
    KC_LSFT,  KC_GRV,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LALT,  KC_LGUI,                      KC_SPC,   KC_SPC,   KC_SPC,                       KC_RGUI,  KC_RALT,  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  [1] = LAYOUT(
    QMKBEST,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,   _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                      _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case QMKBEST:
        if (record->event.pressed) {
          SEND_STRING("QMK is the best thing ever!");
        } else {
          host_consumer_send(0);
        }
        return false; /* Skip all further processing of this key */

      case DICTATION:
        if (record->event.pressed) {
          host_consumer_send(0xCF);
        } else {
          host_consumer_send(0);
        }
        return false; /* Skip all further processing of this key */

      case SPOTLIGHT:
        if (record->event.pressed) {
          SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
        } else {
          host_consumer_send(0);
        }
        return false; /* Skip all further processing of this key */

      default:
        return true; /* Process all other keycodes normally */
  }
};
