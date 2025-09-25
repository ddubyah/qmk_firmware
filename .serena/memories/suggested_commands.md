# Suggested Commands for QMK Development

## Core QMK Commands
- **Compile standard keymap**: `qmk compile -km [keymap] -kb lily58`
- **Compile for RP2040 controllers**: `qmk compile -km [keymap] -kb lily58 -e CONVERT_TO=rp2040_ce`
- **Generate UF2 for drag-and-drop flashing**: `qmk compile -km [keymap] -kb lily58 -e CONVERT_TO=rp2040_ce -t uf2`
- **Flash firmware directly**: `qmk flash -km [keymap] -kb lily58 -e CONVERT_TO=rp2040_ce`

## Keymap Operations
- **Convert C keymap to JSON**: `qmk c2json --no-cpp -km [keymap] -kb lily58 -o [output.json] [keymap.c]`
- **List available keymaps**: `qmk list-keymaps -kb lily58`

## Validation Commands
- **Check compilation**: Run compile command and verify firmware size < 80% flash
- **Test VIA compatibility**: Flash firmware and test with VIA application
- **Memory usage check**: Review compilation output for flash/RAM usage

## Development Tools
- **git**: Version control
- **make**: Alternative to qmk compile using root Makefile
- **find**: Locate files in project structure
- **ls**: Navigate directory structure