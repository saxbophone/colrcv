/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 *
 * Copyright (C) 2017, 2018, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <stdbool.h>
#include <math.h>

#include "../colrcv.h"
#include "rgb.h"
#include "hsv.h"
#include "hsl.h"
#include "lab.h"
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

colrcv_rgb_t colrcv_rgb_clamp(colrcv_rgb_t rgb) {
    // run all clamping functions on the value
    return colrcv_rgb_clamp_b(colrcv_rgb_clamp_g(colrcv_rgb_clamp_r(rgb)));
}

colrcv_rgb_t colrcv_rgb_clamp_r(colrcv_rgb_t rgb) {
    // clamp red channel
    rgb.r = colrcv_clamp(rgb.r, COLRCV_RGB_MIN_VALUE, COLRCV_RGB_MAX_VALUE);
    return rgb;
}

colrcv_rgb_t colrcv_rgb_clamp_g(colrcv_rgb_t rgb) {
    // clamp green channel
    rgb.g = colrcv_clamp(rgb.g, COLRCV_RGB_MIN_VALUE, COLRCV_RGB_MAX_VALUE);
    return rgb;
}

colrcv_rgb_t colrcv_rgb_clamp_b(colrcv_rgb_t rgb) {
    // clamp blue channel
    rgb.b = colrcv_clamp(rgb.b, COLRCV_RGB_MIN_VALUE, COLRCV_RGB_MAX_VALUE);
    return rgb;
}

/* BEGIN private support functions */

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

/* END private support functions */

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=20#text20
colrcv_hsv_t colrcv_rgb_to_hsv(colrcv_rgb_t rgb) {
    double r, g, b, min_channel, max_channel, delta_channel;
    // scale down each RGB channel
    scale_down_rgb(rgb, &r, &g, &b);
    // get min and max of these channels and the delta of min and max
    get_min_max_delta(r, g, b, &min_channel, &max_channel, &delta_channel);
    // output variable
    colrcv_hsv_t hsv;
    // the value component is set to max_channel (upscaled to 0-100 range)
    hsv.v = max_channel * 100;
    // if delta is 0, this is an achromatic grey
    if(delta_channel == 0) {
        hsv.h = 0;
        hsv.s = 0;
    } else {
        // set saturation and upscale to the 0-100 range
        hsv.s = (delta_channel / max_channel) * 100;
        // finally, set the hue
        hsv.h = get_hue_amount(r, g, b, max_channel, delta_channel);
    }
    return hsv;
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=18#text18
colrcv_hsl_t colrcv_rgb_to_hsl(colrcv_rgb_t rgb) {
    double r, g, b, min_channel, max_channel, delta_channel;
    // scale down each RGB channel
    scale_down_rgb(rgb, &r, &g, &b);
    // get min and max of these channels and the delta of min and max
    get_min_max_delta(r, g, b, &min_channel, &max_channel, &delta_channel);
    // output variable
    colrcv_hsl_t hsl;
    // the lightness component is set to the average of max and min of channels
    hsl.l = (max_channel + min_channel) / 2 * 100;
    // if delta is 0, this is an achromatic grey
    if(delta_channel == 0) {
        hsl.h = 0;
        hsl.s = 0;
    } else {
        /*
         * saturation is set differently depending on if lightness amount is
         * less than or greater than half
         */
        if(hsl.l < 50) {
            hsl.s = delta_channel / (max_channel + min_channel) * 100;
        } else {
            hsl.s = delta_channel / (2 - max_channel - min_channel) * 100;
        }
        // finally, set the hue
        hsl.h = get_hue_amount(r, g, b, max_channel, delta_channel);
    }
    return hsl;
}

colrcv_lab_t colrcv_rgb_to_lab(colrcv_rgb_t rgb) {
    // Two-step conversion using RGB->XYZ and XYZ->LAB
    return colrcv_xyz_to_lab(colrcv_rgb_to_xyz(rgb));
}

/*
 * private function for translating an rgb component into the range needed for
 * converting to XYZ
 */
static double convert_rgb_for_xyz(double c) {
    return (c > 0.04045) ? pow((c + 0.055) / 1.055, 2.4) : (c / 12.92);
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=02#text2
colrcv_xyz_t colrcv_rgb_to_xyz(colrcv_rgb_t rgb) {
    double r, g, b;
    // scale down each RGB channel
    scale_down_rgb(rgb, &r, &g, &b);
    // translate each channel
    r = convert_rgb_for_xyz(r) * 100;
    g = convert_rgb_for_xyz(g) * 100;
    b = convert_rgb_for_xyz(b) * 100;
    // apply matrix transforms
    return (colrcv_xyz_t){
        .x = r * 0.4124 + g * 0.3576 + b * 0.1805,
        .y = r * 0.2126 + g * 0.7152 + b * 0.0722,
        .z = r * 0.0193 + g * 0.1192 + b * 0.9505,
    };
}

#ifdef __cplusplus
} // extern "C"
#endif
