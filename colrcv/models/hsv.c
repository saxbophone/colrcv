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
#include "hsv.h"
#include "rgb.h"


#ifdef __cplusplus
extern "C"{
#endif

const double COLRCV_HSV_MIN_VALUE = 0;
const double COLRCV_HSV_H_MAX_VALUE = 360;
const double COLRCV_HSV_S_MAX_VALUE = 100;
const double COLRCV_HSV_V_MAX_VALUE = 100;

bool colrcv_hsv_h_is_valid(colrcv_hsv_t hsv) {
    return colrcv_range_valid(
        COLRCV_HSV_MIN_VALUE, hsv.h, COLRCV_HSV_H_MAX_VALUE
    );
}

bool colrcv_hsv_s_is_valid(colrcv_hsv_t hsv) {
    return colrcv_range_valid(
        COLRCV_HSV_MIN_VALUE, hsv.s, COLRCV_HSV_S_MAX_VALUE
    );
}

bool colrcv_hsv_v_is_valid(colrcv_hsv_t hsv) {
    return colrcv_range_valid(
        COLRCV_HSV_MIN_VALUE, hsv.v, COLRCV_HSV_V_MAX_VALUE
    );
}

bool colrcv_hsv_is_valid(colrcv_hsv_t hsv) {
    // check that the value of each component is in range
    return (
        colrcv_hsv_h_is_valid(hsv) &&
        colrcv_hsv_s_is_valid(hsv) &&
        colrcv_hsv_v_is_valid(hsv)
    );
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=21#text21
colrcv_result_t colrcv_hsv_to_rgb(colrcv_hsv_t hsv, colrcv_rgb_t* rgb) {
    // down-scale s and v input values first
    const double s = hsv.s / 100;
    const double v = hsv.v / 100;
    // if saturation is 0, then we can return early
    if(s == 0) {
        rgb->r = v * 255;
        rgb->g = v * 255;
        rgb->b = v * 255;
        return;
    } else {
        // scale down H to be in range 0 -> 6
        double scaled_h = hsv.h / 60;
        // h value must be snapped to range 0.0 -> 6.0
        if(scaled_h >= 6.0) {
            scaled_h -= 6.0;
        }
        // floor convert to int
        const uint16_t integer_h = (uint16_t)scaled_h;
        // this further lot of temporaries are used in the channel multiplex
        const double temp_a = v * (1.0 - s);
        const double temp_b = v * (1.0 - s * (scaled_h - integer_h));
        const double temp_c = v * (1.0 - s * (1.0 - (scaled_h - integer_h)));
        // choose one of many different multiplexes based on value of integer_h
        switch(integer_h % 6) {
            case 0:
                rgb->r = v;
                rgb->g = temp_c;
                rgb->b = temp_a;
                break;
            case 1:
                rgb->r = temp_b;
                rgb->g = v;
                rgb->b = temp_a;
                break;
            case 2:
                rgb->r = temp_a;
                rgb->g = v;
                rgb->b = temp_c;
                break;
            case 3:
                rgb->r = temp_a;
                rgb->g = temp_b;
                rgb->b = v;
                break;
            case 4:
                rgb->r = temp_c;
                rgb->g = temp_a;
                rgb->b = v;
                break;
            case 5:
                rgb->r = v;
                rgb->g = temp_a;
                rgb->b = temp_b;
                break;
        }
        // up-scale output values to be in 0-255 range
        rgb->r *= 255;
        rgb->g *= 255;
        rgb->b *= 255;
    }
}

// Two-step conversion using HSV->RGB and RGB->HSL
colrcv_result_t colrcv_hsv_to_hsl(colrcv_hsv_t hsv, colrcv_hsl_t* hsl) {
    // convert to RGB first
    colrcv_rgb_t rgb;
    colrcv_hsv_to_rgb(hsv, &rgb);
    // now convert to HSL
    colrcv_rgb_to_hsl(rgb, hsl);
}

// Two-step conversion using HSV->RGB and RGB->LAB
colrcv_result_t colrcv_hsv_to_lab(colrcv_hsv_t hsv, colrcv_lab_t* lab) {
    // convert to rgb
    colrcv_rgb_t rgb;
    colrcv_hsv_to_rgb(hsv, &rgb);
    // convert to LAB
    colrcv_rgb_to_lab(rgb, lab);
}

// Two-step conversion using HSV->RGB and RGB->XYZ
colrcv_result_t colrcv_hsv_to_xyz(colrcv_hsv_t hsv, colrcv_xyz_t* xyz) {
    // convert to rgb
    colrcv_rgb_t rgb;
    colrcv_hsv_to_rgb(hsv, &rgb);
    // convert to XYZ
    colrcv_rgb_to_xyz(rgb, xyz);
}

#ifdef __cplusplus
} // extern "C"
#endif
