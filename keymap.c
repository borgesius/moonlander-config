#include QMK_KEYBOARD_H

enum layers {
    BASE, // QWERTY
    SYM,  // Symbols & operators
    NAV,  // Navigation (vim arrows)
    NUM,  // Numpad & F-keys
};

// Tap-hold: tap Esc, hold Ctrl (on Caps Lock position)
#define CTL_ESC LCTL_T(KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* ┌───────────────────────────────────────────────────────────────────────────────┐
     * │  BASE – Programmer QWERTY                                                    │
     * │                                                                               │
     * │  Standard QWERTY with direct-access brackets on inner columns.               │
     * │  Caps Lock position is Ctrl (hold) / Esc (tap).                              │
     * │                                                                               │
     * │  `~   1!   2@   3#   4$   5%   =+       -_   6^   7&   8*   9(   0)   Bksp  │
     * │  Tab  Q    W    E    R    T    [        ]    Y    U    I    O    P    \|      │
     * │  C/E  A    S    D    F    G    {        }    H    J    K    L    ;:   '"      │
     * │  Shft Z    X    C    V    B                  N    M    ,<   .>   /?   Shft    │
     * │  Ctrl Alt  GUI  NUM  SYM      Spc      Ent       NAV  NUM  GUI  Alt  Ctrl    │
     * │                      Bksp Shft Del      Esc  Shft Tab                        │
     * └───────────────────────────────────────────────────────────────────────────────┘ */
    [BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,     KC_MINS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,    KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LCBR,    KC_RCBR, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LALT, KC_LGUI, MO(NUM), MO(SYM),          KC_SPC,     KC_ENT,           MO(NAV), MO(NUM), KC_RGUI, KC_RALT, KC_RCTL,
                                            KC_BSPC, KC_LSFT, KC_DEL,     KC_ESC,  KC_RSFT, KC_TAB
    ),

    /* ┌───────────────────────────────────────────────────────────────────────────────┐
     * │  SYM – Symbols & operators                                                    │
     * │                                                                               │
     * │  All programming symbols on the home block. Bracket pairs on the left hand,  │
     * │  operators on the right. F-keys across the top.                               │
     * │                                                                               │
     * │  ___  F1   F2   F3   F4   F5   ___      ___  F6   F7   F8   F9   F10  F11   │
     * │  ___  !    @    #    $    %    <        >    ^    &    *    -    =    F12     │
     * │  ___  (    )    [    ]    `    ___      ___  _    +    |    \    :    "       │
     * │  ___  <    >    {    }    ~                  /    ?    ___  ___  ___  ___      │
     * │  ___  ___  ___  ___  ___      ___      ___       ___  ___  ___  ___  ___      │
     * │                      ___  ___  ___      ___  ___  ___                         │
     * └───────────────────────────────────────────────────────────────────────────────┘ */
    [SYM] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LABK,    KC_RABK, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_F12,
        _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_GRV,  _______,    _______, KC_UNDS, KC_PLUS, KC_PIPE, KC_BSLS, KC_COLN, KC_DQUO,
        _______, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_TILD,                      KC_SLSH, KC_QUES, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,           _______,    _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),

    /* ┌───────────────────────────────────────────────────────────────────────────────┐
     * │  NAV – Navigation                                                             │
     * │                                                                               │
     * │  Vim-style HJKL arrows on the right home row. Home row mods on the left so   │
     * │  you can do Shift+Arrow (select), Ctrl+Arrow (word jump), etc.               │
     * │                                                                               │
     * │  ___  ___  ___  ___  ___  ___  ___      ___  ___  ___  ___  ___  ___  ___    │
     * │  ___  ___  ___  ___  ___  ___  ___      ___  Home PgDn PgUp End  ___  ___    │
     * │  ___  GUI  Alt  Ctrl Shft ___  ___      ___  Left Down Up   Rght ___  ___    │
     * │  ___  ___  ___  ___  ___  ___                ___  ___  ___  ___  ___  ___     │
     * │  ___  ___  ___  ___  ___      ___      ___       ___  ___  ___  ___  ___      │
     * │                      ___  ___  ___      ___  ___  ___                         │
     * └───────────────────────────────────────────────────────────────────────────────┘ */
    [NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,    _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,    _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),

    /* ┌───────────────────────────────────────────────────────────────────────────────┐
     * │  NUM – Numpad & F-keys                                                        │
     * │                                                                               │
     * │  Right-hand numpad. Home row mods on left for Ctrl+number shortcuts.          │
     * │  QK_BOOT on top-left for firmware flashing.                                   │
     * │                                                                               │
     * │  BOOT F1   F2   F3   F4   F5   ___      ___  F6   F7   F8   F9   F10  F11   │
     * │  ___  ___  ___  ___  ___  ___  ___      ___  /    7    8    9    -    F12     │
     * │  ___  GUI  Alt  Ctrl Shft ___  ___      ___  *    4    5    6    +    ___     │
     * │  ___  ___  ___  ___  ___  ___                0    1    2    3    .    ___      │
     * │  ___  ___  ___  ___  ___      ___      ___       0    .    ___  ___  ___      │
     * │                      ___  ___  ___      ___  ___  ___                         │
     * └───────────────────────────────────────────────────────────────────────────────┘ */
    [NUM] = LAYOUT(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______,    _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, KC_F12,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,    _______, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______,                      KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
        _______, _______, _______, _______, _______,          _______,    _______,          KC_0,    KC_DOT,  _______, _______, _______,
                                            _______, _______, _______,    _______, _______, _______
    ),
};
// clang-format on
