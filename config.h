#pragma once

// --- Tap-Hold Tuning ---

// Time (ms) a dual-role key must be held before it registers as "hold".
// 175 ms is fast enough for fluid typing, forgiving enough to avoid misfires.
#define TAPPING_TERM 175

// Pressing another key while a tap-hold key is down always triggers "hold",
// even if released before TAPPING_TERM. Eliminates the lag on Ctrl/Esc combos.
#define PERMISSIVE_HOLD

// If a tap-hold key is pressed and released on its own (no other key pressed),
// always register the "tap" even if held longer than TAPPING_TERM.
// Makes CTL_ESC feel snappy: slow tap still gives Escape.
#define RETRO_TAPPING
