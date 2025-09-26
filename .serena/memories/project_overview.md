# QMK Keyboards Project Overview

## Purpose
This is a QMK (Quantum Mechanical Keyboard) firmware repository with custom lily58 keyboard configurations. The repository contains the full QMK firmware source with custom keymaps for lily58 split keyboards, including both standard QMK and VIA-compatible versions.

## Tech Stack
- **Primary Language**: C
- **Framework**: QMK Firmware (based on AVR/ARM microcontrollers)
- **Build System**: Make + QMK CLI
- **Target Hardware**: 
  - Lily58 split keyboards
  - AVR controllers (Pro Micro/Elite-C)
  - RP2040 controllers
- **Features**: OLED displays, RGB lighting, VIA compatibility

## Architecture
- **Keyboard Definitions**: `keyboards/lily58/` contains hardware configs
- **Custom Keymaps**: `keyboards/lily58/keymaps/` contains user layouts
- **Libraries**: `keyboards/lily58/lib/` contains OLED and RGB functions
- **Build System**: Root Makefile with QMK CLI integration

## Controller Support
- **AVR (default)**: Pro Micro/Elite-C using hex files
- **RP2040**: Using `CONVERT_TO=rp2040_ce` flag, outputs UF2 files for drag-and-drop flashing