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
        KC_LCTL, KC_LALT, KC_LGUI, MO(NUM), MO(SYM),          KC_NO,      KC_NO,            MO(NAV), MO(NUM), KC_RGUI, KC_RALT, KC_RCTL,
                                            KC_SPC,  KC_BSPC, KC_DEL,     KC_TAB,  KC_RSFT, KC_ENT
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

// ---------------------------------------------------------------------------
//  Per-key RGB: light up active keys by category, turn off transparent ones
// ---------------------------------------------------------------------------
#ifdef RGB_MATRIX_ENABLE

// Palette (R, G, B)
#define C_OFF        0,   0,   0
#define C_RED      255,   0,   0    // boot / danger
#define C_ORANGE   255, 140,   0    // misc active symbols
#define C_GREEN      0, 220, 100    // nav arrows, numbers
#define C_CYAN       0, 180, 180    // operators
#define C_BLUE      60,  60, 255    // modifiers
#define C_DIMBLUE   60,  60, 140    // F-keys
#define C_PURPLE   140,   0, 255    // brackets

static bool is_bracket(uint16_t kc) {
    switch (kc) {
        case KC_LPRN: case KC_RPRN:
        case KC_LBRC: case KC_RBRC:
        case KC_LCBR: case KC_RCBR:
        case KC_LABK: case KC_RABK:
            return true;
        default:
            return false;
    }
}

static bool is_nav(uint16_t kc) {
    switch (kc) {
        case KC_LEFT: case KC_DOWN: case KC_UP: case KC_RGHT:
        case KC_HOME: case KC_END:  case KC_PGUP: case KC_PGDN:
            return true;
        default:
            return false;
    }
}

static bool is_operator(uint16_t kc) {
    switch (kc) {
        case KC_PLUS: case KC_MINS: case KC_ASTR: case KC_SLSH:
        case KC_EQL:  case KC_UNDS: case KC_PIPE: case KC_BSLS:
        case KC_AMPR: case KC_CIRC: case KC_TILD: case KC_GRV:
        case KC_EXLM: case KC_AT:   case KC_HASH: case KC_DLR:
        case KC_PERC: case KC_QUES:
            return true;
        default:
            return false;
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    if (layer == BASE) return false; // default animation on base

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t idx = g_led_config.matrix_co[row][col];
            if (idx == NO_LED || idx < led_min || idx >= led_max) continue;

            uint16_t kc = keymaps[layer][row][col];

            // Inactive keys → off
            if (kc == KC_TRNS || kc == KC_NO) {
                rgb_matrix_set_color(idx, C_OFF);
                continue;
            }

            // Classify active keys
            if (kc == QK_BOOT)                         rgb_matrix_set_color(idx, C_RED);
            else if (kc >= KC_LCTL && kc <= KC_RGUI)   rgb_matrix_set_color(idx, C_BLUE);
            else if (kc >= KC_F1 && kc <= KC_F24)      rgb_matrix_set_color(idx, C_DIMBLUE);
            else if (is_nav(kc))                        rgb_matrix_set_color(idx, C_GREEN);
            else if (kc >= KC_1 && kc <= KC_0)          rgb_matrix_set_color(idx, C_GREEN);
            else if (kc == KC_DOT)                      rgb_matrix_set_color(idx, C_GREEN);
            else if (is_bracket(kc))                    rgb_matrix_set_color(idx, C_PURPLE);
            else if (is_operator(kc))                   rgb_matrix_set_color(idx, C_CYAN);
            else                                        rgb_matrix_set_color(idx, C_ORANGE);
        }
    }
    return false;
}

#endif
