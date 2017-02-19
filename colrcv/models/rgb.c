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
#include "hsl.h"
#include "xyz.h"


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

/* BEGIN HSL/HSV private support functions */

// Scales down RGB amounts from 0->255 to 0->1
static void scale_down_rgb(
    colrcv_rgb_t rgb, double* restrict r, double* restrict g, double* restrict b
) {
    *r = rgb.r / 255;
    *g = rgb.g / 255;
    *b = rgb.b / 255;
}

// sets the minimum, maximum and delta for a given set of rgb amounts
static void get_min_max_delta(
    double r, double g, double b,
    double* restrict min, double* restrict max, double* restrict delta
) {
    *min = colrcv_min(r, colrcv_min(g, b));
    *max = colrcv_max(r, colrcv_max(g, b));
    *delta = *max - *min;
}

// returns the hue amount of HSV/HSL for given r, g, b, max and delta
static double get_hue_amount(
    double r, double g, double b, double max, double delta
) {
    // set the hue based on delta and which channel had the highest value
    // (http://wiki.secondlife.com/wiki/Color_conversion_scripts)
    double hue;
    if(r == max) {
        hue = (g - b) / delta;
    } else if(g == max) {
        hue = 2 + (b - r) / delta;
    } else { // b == max
        hue = 4 + (r - g) / delta;
    }
    // adjust hue to be in the 0-360 range
    hue *= 60;
    // wrap-around the output value of hue if needed
    if(hue < 0) {
        hue += 360;
    } else if(hue > 360) {
        hue -= 360;
    }
    return hue;
}

/* END HSL/HSV private support functions */

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=20#text20
colrcv_result_t colrcv_rgb_to_hsv(colrcv_rgb_t rgb, colrcv_hsv_t* hsv) {
    double r, g, b, min_channel, max_channel, delta_channel;
    // scale down each RGB channel
    scale_down_rgb(rgb, &r, &g, &b);
    // get min and max of these channels and the delta of min and max
    get_min_max_delta(r, g, b, &min_channel, &max_channel, &delta_channel);
    // the value component is set to max_channel (upscaled to 0-100 range)
    hsv->v = max_channel * 100;
    // if delta is 0, this is an achromatic grey
    if(delta_channel == 0) {
        hsv->h = 0;
        hsv->s = 0;
    } else {
        // set saturation and upscale to the 0-100 range
        hsv->s = (delta_channel / max_channel) * 100;
        // finally, set the hue
        hsv->h = get_hue_amount(r, g, b, max_channel, delta_channel);
    }
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=18#text18
colrcv_result_t colrcv_rgb_to_hsl(colrcv_rgb_t rgb, colrcv_hsl_t* hsl) {
    double r, g, b, min_channel, max_channel, delta_channel;
    // scale down each RGB channel
    scale_down_rgb(rgb, &r, &g, &b);
    // get min and max of these channels and the delta of min and max
    get_min_max_delta(r, g, b, &min_channel, &max_channel, &delta_channel);
    // the lightness component is set to the average of max and min of channels
    hsl->l = (max_channel + min_channel) / 2 * 100;
    // if delta is 0, this is an achromatic grey
    if(delta_channel == 0) {
        hsl->h = 0;
        hsl->s = 0;
    } else {
        /*
         * saturation is set differently depending on if lightness amount is
         * less than or greater than half
         */
        if(hsl->l < 50) {
            hsl->s = delta_channel / (max_channel + min_channel) * 100;
        } else {
            hsl->s = delta_channel / (2 - max_channel - min_channel) * 100;
        }
        // finally, set the hue
        hsl->h = get_hue_amount(r, g, b, max_channel, delta_channel);
    }
}

colrcv_result_t colrcv_rgb_to_xyz(colrcv_rgb_t rgb, colrcv_xyz_t* xyz) {
    // NOTE: Dummy implementation for now
    xyz->x = rgb.r;
}

#ifdef __cplusplus
} // extern "C"
#endif
