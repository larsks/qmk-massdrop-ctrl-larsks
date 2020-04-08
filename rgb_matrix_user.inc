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
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb_esc;
    RGB rgb_alpha;
    RGB rgb_mod;

    rgb_esc.r = 255;
    rgb_esc.g = 0;
    rgb_esc.b = 0;

    rgb_alpha.r = 255;
    rgb_alpha.g = 255;
    rgb_alpha.b = 255;

    rgb_mod.r = 0;
    rgb_mod.g = 252;
    rgb_mod.b = 255;

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (i == 0) {
            rgb_matrix_set_color(i, rgb_esc.r, rgb_esc.g, rgb_esc.b);
        } else if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
            rgb_matrix_set_color(i, rgb_mod.r, rgb_mod.g, rgb_mod.b);
        } else {
            rgb_matrix_set_color(i, rgb_alpha.r, rgb_alpha.g, rgb_alpha.b);
        }
    }
    return led_max < DRIVER_LED_TOTAL;
}

#    endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif      // DISABLE_RGB_MATRIX_ALPHAS_MODS
