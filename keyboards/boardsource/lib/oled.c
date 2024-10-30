// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "oled.h"

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_raw_P(layer0_img, sizeof(layer0_img));
            break;
        case 1:
            oled_write_raw_P(layer1_img, sizeof(layer1_img));
            break;
        case 2:
            oled_write_raw_P(layer2_img, sizeof(layer2_img));
            break;
        case 3:
            oled_write_raw_P(layer3_img, sizeof(layer3_img));
            break;
    }
}

void another_layer_state(void) {
    oled_set_cursor(0, 1);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P("MAIN \n", true);
            oled_write_P("LOWER\n", false);
            oled_write_P("UPPER\n", false);
            oled_write_P("ADJST\n", false);
			oled_write_P("MODS \n", false);
            break;
        case _LOWER:
            oled_write_P("MAIN \n", false);
            oled_write_P("LOWER\n", true);
            oled_write_P("UPPER\n", false);
            oled_write_P("ADJST\n", false);
			oled_write_P("MODS \n", false);
            break;
        case _RAISE:
            oled_write_P("MAIN \n", false);
            oled_write_P("LOWER\n", false);
            oled_write_P("UPPER\n", true);
            oled_write_P("ADJST\n", false);
			oled_write_P("MODS \n", false);
            break;
        case _ADJUST:
            oled_write_P("MAIN \n", false);
            oled_write_P("LOWER\n", false);
            oled_write_P("UPPER\n", false);
            oled_write_P("ADJST\n", true);
			oled_write_P("MODS \n", false);
            break;
		case _ADJUST:
            oled_write_P("MAIN \n", false);
            oled_write_P("LOWER\n", false);
            oled_write_P("UPPER\n", false);
            oled_write_P("ADJST\n", false);
			oled_write_P("MODS \n", true);
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void caps_indicator(void) {
    oled_set_cursor(0, 1);

	// Caps lock status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);
}