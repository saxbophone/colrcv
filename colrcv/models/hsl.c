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
#include "hsl.h"
#include "rgb.h"


#ifdef __cplusplus
extern "C"{
#endif

const double COLRCV_HSL_MIN_VALUE = 0;
const double COLRCV_HSL_H_MAX_VALUE = 360;
const double COLRCV_HSL_S_MAX_VALUE = 100;
const double COLRCV_HSL_L_MAX_VALUE = 100;

bool colrcv_hsl_h_is_valid(colrcv_hsl_t hsl) {
    return colrcv_range_valid(
        COLRCV_HSL_MIN_VALUE, hsl.h, COLRCV_HSL_H_MAX_VALUE
    );
}

bool colrcv_hsl_s_is_valid(colrcv_hsl_t hsl) {
    return colrcv_range_valid(
        COLRCV_HSL_MIN_VALUE, hsl.s, COLRCV_HSL_S_MAX_VALUE
    );
}

bool colrcv_hsl_l_is_valid(colrcv_hsl_t hsl) {
    return colrcv_range_valid(
        COLRCV_HSL_MIN_VALUE, hsl.l, COLRCV_HSL_L_MAX_VALUE
    );
}

bool colrcv_hsl_is_valid(colrcv_hsl_t hsl) {
    // check that the value of each component is in range
    return (
        colrcv_hsl_h_is_valid(hsl) &&
        colrcv_hsl_s_is_valid(hsl) &&
        colrcv_hsl_l_is_valid(hsl)
    );
}

// private helper function for colrcv_hsl_to_rgb
static double hue_to_rgb(double a, double b, double h) {
    if(h < 0) {
        h += 1;
    } else if(h > 1) {
        h -= 1;
    }
    if((6 * h) < 1) {
        return (a + (b - a) * 6 * h);
    } else if((2 * h) < 1) {
        return b;
    } else if((3 * h) < 2) {
        return (a + (b - a) * ((2.0 / 3) - h) * 6);
    } else {
        return a;
    }
}

colrcv_result_t colrcv_hsl_to_rgb(colrcv_hsl_t hsl, colrcv_rgb_t* rgb) {
    // if saturation is 0, it's an achromatic grey so return early
    if(hsl.s == 0) {
        rgb->r = hsl.l / 100 * 255;
        rgb->g = hsl.l / 100 * 255;
        rgb->b = hsl.l / 100 * 255;
    } else {
        // down-scale all channels
        double h = hsl.h / 360;
        double s = hsl.s / 100;
        double l = hsl.l / 100;
        // get temporary 'b'
        double temp_b = (l < 0.5) ? (l * (1 + s)) : ((l + s) - (s * l));
        // get temporary 'a'
        double temp_a = 2 * l - temp_b;
        // get component amounts with respect to hue and temporaries
        rgb->r = 255 * hue_to_rgb(temp_a, temp_b, h + (1.0 / 3));
        rgb->g = 255 * hue_to_rgb(temp_a, temp_b, h);
        rgb->b = 255 * hue_to_rgb(temp_a, temp_b, h - (1.0 / 3));
    }
}

#ifdef __cplusplus
} // extern "C"
#endif
