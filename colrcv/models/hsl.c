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

#ifdef __cplusplus
} // extern "C"
#endif
