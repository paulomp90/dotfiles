VIA_ENABLE = no
VIAL_ENABLE = no
QMK_SETTINGS = no

REPEAT_KEY_ENABLE = yes
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no
AUDIO_ENABLE = no           # Audio output

OLED_ENABLE = yes
EXTRAKEY_ENABLE = yes
TRI_LAYER_ENABLE = yes
CAPS_WORD_ENABLE = yes
LTO_ENABLE = yes

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
# AUTO_SHIFT_ENABLE = yes

SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c