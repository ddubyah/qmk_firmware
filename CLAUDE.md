# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a QMK (Quantum Mechanical Keyboard) firmware repository with custom lily58 keyboard configurations. The repository contains the full QMK firmware source with custom keymaps for lily58 split keyboards, including both standard QMK and VIA-compatible versions.

## Key Commands

### Compilation Commands
- **Compile standard keymap**: `qmk compile -km [keymap] -kb lily58`
- **Compile for RP2040 controllers**: `qmk compile -km [keymap] -kb lily58 -e CONVERT_TO=rp2040_ce`
- **Generate UF2 for drag-and-drop flashing**: `qmk compile -km [keymap] -kb lily58 -e CONVERT_TO=rp2040_ce -t uf2`
- **Flash firmware directly**: `qmk flash -km [keymap] -kb lily58 -e CONVERT_TO=rp2040_ce`

### Keymap Operations
- **Convert C keymap to JSON**: `qmk c2json --no-cpp -km [keymap] -kb lily58 -o [output.json] [keymap.c]`
- **List available keymaps**: `qmk list-keymaps -kb lily58`

### Build Targets
- **Standard AVR compilation**: Targets Pro Micro/Elite-C controllers
- **RP2040 compilation**: Use `CONVERT_TO=rp2040_ce` for RP2040-based controllers
- **UF2 output**: Add `-t uf2` for drag-and-drop flashing to RP2040 boards

## Architecture and Structure

### Custom Lily58 Keymaps Location
- **Primary keymaps**: `keyboards/lily58/keymaps/`
  - `frogger/`: Full-featured keymap with OLED support and 5 layers
  - `frogger_via/`: VIA-compatible version with 5 layers, OLED disabled
  - `default/`: Standard QMK default keymap

### Keymap Architecture
- **Layer structure**: Uses enum-based layer definitions (`_QWERTY`, `_SECOND`, `_CMD`, `_SYM`, `_LAYER4`)
- **VIA compatibility**: Requires `VIA_ENABLE = yes` in rules.mk and `DYNAMIC_KEYMAP_LAYER_COUNT` config
- **OLED integration**: Custom OLED functions in frogger keymap for layer state display and key logging

### Configuration Files Per Keymap
- **keymap.c**: Layer definitions and key mappings
- **rules.mk**: Build options and feature enables
- **config.h**: Hardware-specific settings and layer counts

### Hardware Controller Support
- **AVR controllers**: Default compilation targets Pro Micro/Elite-C
- **RP2040 controllers**: Require `CONVERT_TO=rp2040_ce` compilation flag
- **Bootloader differences**: AVR uses hex files, RP2040 uses UF2 for drag-and-drop flashing

### VIA Configuration Requirements
- Set `DYNAMIC_KEYMAP_LAYER_COUNT` to match actual layer count in keymap
- Disable memory-intensive features (OLED, console debug) to fit VIA overhead
- Enable `LTO_ENABLE = yes` for size optimization

### OLED and RGB Support
- **OLED libraries**: `keyboards/lily58/lib/` contains display functions
- **Layer state reader**: Shows current active layer on OLED
- **Key logging**: Displays recent keystrokes on OLED
- **RGB support**: Available but typically disabled in VIA builds for memory

## Firmware Output Locations
- **Compiled firmware**: `.build/` directory
- **Deployment files**: Root directory (lily58_rev1_[keymap]_[target].hex/uf2)

## Important Build Considerations
- **Memory constraints**: VIA builds require careful feature management due to EEPROM/flash limitations
- **Layer limits**: VIA standard supports 4 layers by default, custom builds can extend to 5+
- **Controller detection**: RP2040 boards show as "RPI-RP2" drive when in bootloader mode
- **Split keyboard**: Both halves need flashing for RP2040 builds, only master for AVR builds