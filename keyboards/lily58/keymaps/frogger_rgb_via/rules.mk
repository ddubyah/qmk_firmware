# Core Features
VIA_ENABLE = yes
VIA_KEYMAP_JSON_FILE = keyboards/lily58/keymaps/frogger_rgb_via/via_keymap.json
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

# Build Optimizations
LTO_ENABLE = yes
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no  # Disable to avoid conflicts
AUDIO_ENABLE = no
SPLIT_KEYBOARD = yes

# OLED Library Integration
SRC += keyboards/lily58/lib/layer_state_reader.c \
       keyboards/lily58/lib/keylogger.c \
       keyboards/lily58/lib/logo_reader.c \
       keyboards/lily58/lib/rgb_state_reader.c \
       keyboards/lily58/keymaps/frogger_rgb_via/rgb_matrix_map.c