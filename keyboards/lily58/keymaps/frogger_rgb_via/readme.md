# Lily58 Frogger RGB VIA Keymap

A feature-rich lily58 keyboard firmware that combines per-key RGB Matrix lighting, OLED display support, VIA real-time configuration, and 5 customizable layers. Optimized for RP2040 controllers with left-half-only usage (29 keys).

## Features

- **RGB Matrix Support**: Per-key RGB lighting with 15 curated animation effects
- **OLED Display**: Shows layer status, RGB mode/HSV values, and key logging
- **VIA Compatibility**: Real-time keymap editing with RGB control via VIA interface
- **5 Layers**: Customizable layer configuration (_QWERTY, _SECOND, _CMD, _SYM, _LAYER4)
- **RP2040 Optimized**: Single-half operation (left side only, 29 LEDs)
- **Memory Optimized**: ~115KB firmware size (5.6% of RP2040 flash)

## Hardware Configuration

- Lily58 left half only (~29 RGB LEDs)
- OLED 128x32 display
- RP2040-based controller (Elite-C v4, etc.)
- WS2812 RGB LEDs

## RGB Effects

15 carefully selected effects for balanced performance and memory usage:
- BREATHING, CYCLE_ALL, CYCLE_LEFT_RIGHT, CYCLE_UP_DOWN
- RAINBOW_MOVING_CHEVRON, CYCLE_OUT_IN, CYCLE_PINWHEEL
- RAINBOW_BEACON, TYPING_HEATMAP, DIGITAL_RAIN
- SOLID_REACTIVE_SIMPLE, SOLID_REACTIVE_MULTIWIDE
- SPLASH, SOLID_SPLASH, STARLIGHT

## RGB Controls

### Hardware Controls (CMD Layer)
Located on the right side of the CMD layer:
- **RM_TOGG**: Toggle RGB on/off
- **RM_NEXT**: Cycle through RGB modes
- **HUE +/-**: Adjust hue (RM_HUEU/RM_HUED)
- **SAT +/-**: Adjust saturation (RM_SATU/RM_SATD)  
- **VAL +/-**: Adjust brightness (RM_VALU/RM_VALD)
- **SPD +/-**: Adjust animation speed (RM_SPDU/RM_SPDD)

### VIA GUI Controls
**NEW**: With `VIA_QMK_RGB_MATRIX_ENABLE` flag, VIA should now show a **"LIGHTING"** tab with:
- RGB Matrix effect selection dropdown
- Brightness slider
- Color picker
- Animation speed control
- Real-time preview