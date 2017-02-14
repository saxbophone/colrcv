/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 *
 *
 * Copyright (C) 2017, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * The Copyright holder reserves all rights of this work.
 *
 * No copying or reproduction is permitted without the express, written consent
 * of the Copyright holder.
 */
#include <stdbool.h>

#include "../colrcv.h"
#include "rgb.h"
#include "hsv.h"


#ifdef __cplusplus
extern "C"{
#endif

const double COLRCV_RGB_MIN_VALUE = 0;
const double COLRCV_RGB_MAX_VALUE = 255;

bool colrcv_rgb_r_is_valid(colrcv_rgb_t rgb) {
    return colrcv_range_valid(
        COLRCV_RGB_MIN_VALUE, rgb.r, COLRCV_RGB_MAX_VALUE
    );
}

bool colrcv_rgb_g_is_valid(colrcv_rgb_t rgb) {
    return colrcv_range_valid(
        COLRCV_RGB_MIN_VALUE, rgb.g, COLRCV_RGB_MAX_VALUE
    );
}

bool colrcv_rgb_b_is_valid(colrcv_rgb_t rgb) {
    return colrcv_range_valid(
        COLRCV_RGB_MIN_VALUE, rgb.b, COLRCV_RGB_MAX_VALUE
    );
}

bool colrcv_rgb_is_valid(colrcv_rgb_t rgb) {
    // check that the value of each component is in range
    return (
        colrcv_rgb_r_is_valid(rgb) &&
        colrcv_rgb_g_is_valid(rgb) &&
        colrcv_rgb_b_is_valid(rgb)
    );
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=20#text20
colrcv_result_t colrcv_rgb_to_hsv(colrcv_rgb_t rgb, colrcv_hsv_t* hsv) {
    // scale down each RGB channel to be in the range 0-1
    double r = rgb.r / 255;
    double g = rgb.g / 255;
    double b = rgb.b / 255;
    // get the minimum and maximum channel amount
    double min_r_g = (r < g) ? r : g;
    double max_r_g = (r > g) ? r : g;
    double min_channel = (min_r_g < b) ? min_r_g : b;
    double max_channel = (max_r_g > b) ? max_r_g : b;
    // get the difference (delta) between max and min
    double delta_channel = max_channel - min_channel;
    // the value component is set to max_channel (upscaled to 0-100 range)
    hsv->v = max_channel * 100;
    // if delta is 0, this is an achromatic grey
    if(delta_channel == 0) {
        hsv->h = 0;
        hsv->s = 0;
    } else {
        // set saturation and upscale to the 0-100 range
        hsv->s = (delta_channel / max_channel) * 100;
        // get each per-channel delta
        double delta_r = (
            (((max_channel - r) / 6 ) + (delta_channel / 2)) / delta_channel
        );
        double delta_g = (
            (((max_channel - g) / 6 ) + (delta_channel / 2)) / delta_channel
        );
        double delta_b = (
            (((max_channel - b) / 6 ) + (delta_channel / 2)) / delta_channel
        );
        // set the hue based on deltas and which channel had the highest value
        if(r == max_channel) {
            hsv->h = (delta_b - delta_g);
        } else if(g == max_channel) {
            hsv->h = ((1 / 3) + delta_r - delta_b);
        } else { // b == max_channel
            hsv->h = ((2 / 3) + delta_g - delta_r);
        }
        // wrap-around the output value of h if needed
        if(hsv->h < 0) {
            hsv->h += 1;
        } else if(hsv->h > 1) {
            hsv->h -= 1;
        }
        // finally, adjust h to be in the 0-360 range
        hsv->h *= 360;
    }
    return;
}

#ifdef __cplusplus
} // extern "C"
#endif
