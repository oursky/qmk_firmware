#include "quantum.h"
#include "keyconfig.h"

// This file is not meant to be compiled directly, but included in keymap.c
// LAYER_COUNT, keymaps etc are defined in config.c

bool is_connected = false;

uint8_t get_layer_count() {
    return LAYER_COUNT;
}

uint8_t get_layer_type(uint8_t index) {
    return layers[index];
}

uint8_t get_key_size_and_ordinal(uint8_t layer, uint8_t x, uint8_t y) {
    return key_size_and_ordinals[layer][y][x];
}

uint8_t get_key_action_type(uint8_t layer, uint8_t x, uint8_t y) {
    return pgm_read_byte(&keymaps[layer][y][x]) - CH_CUSTOM;
}

uint32_t get_key_icon(uint8_t layer, uint8_t x, uint8_t y) {
    // TODO: Confirm with client.
    return 0;
}

bool isWindows(uint8_t layer) {
    return layer % 2 == 0;
}

uint8_t get_current_layer(void) {
    uint16_t current_layer = 0;
    for (uint16_t i = 0; i < LAYER_COUNT; ++i) {
        if (IS_LAYER_ON(i)) {
            current_layer = i;
            break;
        }
    }
    return current_layer;
}

void switch_layer(void) {
    uint8_t current_layer = get_current_layer();
    layer_clear();
    uint16_t next_layer = current_layer + 1;
    if (next_layer >= LAYER_COUNT) {
        next_layer = 0;
    }
    layer_on(next_layer);
}

void virtser_recv(uint8_t c) {
    process_protocol(c);
}

void send_protocol(uint8_t c) {
    virtser_send(c);
}

void on_connected() {
    is_connected = true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_either_pressed = false;
    uint8_t x = record->event.key.col;
    uint8_t y = MATRIX_ROWS - 1 - record->event.key.row;
    if (x == 0 && y <= 1) {
        if (record->event.pressed) {   
            if (is_either_pressed) {
                switch_layer();
                return false;
            }
        }
        is_either_pressed = record->event.pressed;
    }
    if (record->event.pressed) {
        if (is_connected) {
            key_down(get_current_layer(), x, y);
        } else {
            uint16_t keyConfigIndex = keycode - CH_CUSTOM;
            uint16_t const* keyMacros = windowsConfigs[keyConfigIndex];
            for (uint32_t i = 0; i < KEY_MACROS_MAX_COUNT; ++i) {
                uint16_t code = keyMacros[i];
                if (code == KC_NO) continue;
                register_code(code);
            }
            for (int32_t i = KEY_MACROS_MAX_COUNT - 1; i >= 0; --i) {
                uint16_t code = keyMacros[i];
                if (code == KC_NO) continue;
                unregister_code(code);
            }
        }
    }
    return false;
}
