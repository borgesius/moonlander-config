# Moonlander Keymap

Programmer QWERTY layout for the [ZSA Moonlander](https://www.zsa.io/moonlander). Built with [QMK](https://docs.qmk.fm/).

## Layout

### Base — QWERTY

Standard QWERTY with a few ergonomic tweaks:

- **Caps Lock → Ctrl / Esc** — hold for Ctrl, tap for Escape
- **Inner columns** — direct `[ ]` and `{ }` without Shift
- **Thumb cluster** — Space, Enter, Backspace, Shift, Delete, Esc, Tab

```
`~   1!   2@   3#   4$   5%   =+       -_   6^   7&   8*   9(   0)   Bksp
Tab  Q    W    E    R    T    [        ]    Y    U    I    O    P    \|
C/E  A    S    D    F    G    {        }    H    J    K    L    ;:   '"
Shft Z    X    C    V    B                  N    M    ,<   .>   /?   Shft
Ctrl Alt  GUI  NUM  SYM      Spc      Ent       NAV  NUM  GUI  Alt  Ctrl
                     Bksp Shft Del     Esc  Shft Tab
```

### SYM — Symbols

Hold **SYM** to bring all programming symbols to the home block:

- Left hand: bracket pairs `() [] {} <>`
- Right hand: operators `_ + | \ : "` and arithmetic
- Top row: F1–F12

### NAV — Navigation

Hold **NAV** for vim-style arrows on HJKL:

- Right home row: ← ↓ ↑ →
- Right upper row: Home, PgDn, PgUp, End
- Left home row: GUI, Alt, Ctrl, Shift (combine with arrows for selection)

### NUM — Numpad

Hold **NUM** for a right-hand numpad:

- Standard numpad layout (789 / 456 / 123 / 0.)
- F-keys on the top row
- Left home row mods for Ctrl+number shortcuts
- **QK_BOOT** on top-left to enter bootloader

## Setup

### Prerequisites

```bash
brew install qmk/qmk/qmk
qmk setup zsa/qmk_firmware -b firmware24
```

Download [Keymapp](https://www.zsa.io/flash) for flashing.

### Build & Flash

```bash
make compile   # compile firmware
make flash     # compile + flash (enter bootloader first)
```

To enter bootloader: hold **NUM** and press top-left key (`QK_BOOT`), or use the physical reset button on the Moonlander.
