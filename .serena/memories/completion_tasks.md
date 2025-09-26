# Task Completion Guidelines

## When Task is Completed

1. **Compile and Test**
   - Run: `qmk compile -km frogger_rgb_via -kb lily58 -e CONVERT_TO=rp2040_ce -t uf2`
   - Verify: Clean compilation, firmware size < 80% flash
   
2. **Memory Usage Validation**
   - Check compilation output for flash usage
   - Ensure RGB effects load without memory errors
   
3. **Feature Validation**
   - Flash firmware and test in VIA
   - Verify all 5 layers accessible and editable
   - Test RGB controls functional in Lighting tab
   - Confirm OLED displays layer and RGB status
   - Check RGB effects cycle correctly

## QMK Code Style
- Use QMK standard naming conventions
- Follow existing keymap patterns
- Include proper headers and comments
- Use LAYOUT() macro for keymap definitions
- Maintain enum naming consistency