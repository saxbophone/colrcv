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
    // This is nonsense code, add actual code later
    hsv.v = 0;
    rgb->r = hsv.h * hsv.s * hsv.v;
}

#ifdef __cplusplus
} // extern "C"
#endif
