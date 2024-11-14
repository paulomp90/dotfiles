VIA_ENABLE = no
VIAL_ENABLE = no
QMK_SETTINGS = no

AUDIO_ENABLE = no           # Audio output
BOOTMAGIC_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
GRAVE_ESC_ENABLE = no
LTO_ENABLE = yes
MAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
OLED_ENABLE = yes
REPEAT_KEY_ENABLE = yes
TAP_DANCE_ENABLE = no
TRI_LAYER_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.

SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c