#ifndef DISABLE_RGB_MATRIX_LARSKS_ALPHAS_MODS
RGB_MATRIX_EFFECT(LARSKS_ALPHAS_MODS)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#ifndef LARSKS_RGB_ALPHA
#define LARSKS_RGB_ALPHA 0
#endif

#ifndef LARSKS_RGB_MOD
#define LARSKS_RGB_MOD 0
#endif

// alphas = color1, mods = color2
bool LARSKS_ALPHAS_MODS(effect_params_t* params) {
    HSV hsv_esc     = { 0,   255, rgb_matrix_config.hsv.v}; // #FF0000
    HSV hsv_mod     = { 128, 255, rgb_matrix_config.hsv.v}; // #00FCFF
    HSV hsv_alpha   = { 0,   0,   rgb_matrix_config.hsv.v}; // #FFFFFF

    RGB rgb;

    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (i == 0) {
            rgb = hsv_to_rgb(hsv_esc);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb = hsv_to_rgb(hsv_mod);
        } else {
            rgb = hsv_to_rgb(hsv_alpha);
        }
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_ALPHAS_MODS
