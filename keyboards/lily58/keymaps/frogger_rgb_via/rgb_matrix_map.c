#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"

// LED position mapping for left half lily58 (29 LEDs)
led_config_t g_led_config = { {
    // Key Matrix to LED Index (left half only)
    { 0,  1,  2,  3,  4,  5},   // Row 0
    { 6,  7,  8,  9, 10, 11},   // Row 1
    {12, 13, 14, 15, 16, 17},   // Row 2
    {18, 19, 20, 21, 22, 23},   // Row 3
    {NO_LED, 24, 25, 26, 27, 28} // Row 4 (thumb keys)
}, {
    // LED Index to Physical Position (x: 0-112, y: 0-64 for left half)
    {0,4},   {14,2},  {29,0},  {43,2},  {58,4},  {72,7},   // Row 0
    {0,18},  {14,16}, {29,15}, {43,16}, {58,20}, {72,22},  // Row 1
    {0,33},  {14,31}, {29,29}, {43,31}, {58,35}, {72,37},  // Row 2
    {0,48},  {14,46}, {29,44}, {43,46}, {58,49}, {72,51},  // Row 3
             {22,64}, {36,62}, {51,61}, {65,60}, {87,62}   // Row 4 (thumbs)
}, {
    // LED Index to Flag (4=key, 2=underglow/modifier)
    4,4,4,4,4,4,  // Row 0 - all keys
    4,4,4,4,4,4,  // Row 1 - all keys
    4,4,4,4,4,4,  // Row 2 - all keys
    4,4,4,4,4,4,  // Row 3 - all keys
    4,4,4,4,4     // Row 4 - thumb keys
} };

#endif