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

#ifdef __cplusplus
} // extern "C"
#endif
