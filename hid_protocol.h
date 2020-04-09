#pragma once

#include <color.h>
#include <raw_hid.h>

#define CTRL_HID_GREETING_VERSION "CTRLHID 1.0.0"

enum ctrl_hid_codes {
    // Signals end of message. Not really that useful.
    CTRL_HID_EOM = 0x00,
    CTRL_HID_OK,
    CTRL_HID_NOK,
};

extern uint8_t raw_hid_buffer[RAW_EPSIZE];

// Defined in rgb_matrix_user.inc
// It's 119 for Massdrop CTRL, 0 - 118.
extern RGB rgb_matrix_led_state[DRIVER_LED_TOTAL];

void raw_hid_perform_send(void);
