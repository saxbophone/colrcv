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
#include "lab.h"


#ifdef __cplusplus
extern "C"{
#endif

const double COLRCV_LAB_L_MIN_VALUE = 0;
const double COLRCV_LAB_A_MIN_VALUE = -100;
const double COLRCV_LAB_B_MIN_VALUE = -100;
const double COLRCV_LAB_MAX_VALUE = 100;

bool colrcv_lab_l_is_valid(colrcv_lab_t lab) {
    return colrcv_range_valid(
        COLRCV_LAB_L_MIN_VALUE, lab.l, COLRCV_LAB_MAX_VALUE
    );
}

bool colrcv_lab_a_is_valid(colrcv_lab_t lab) {
    return colrcv_range_valid(
        COLRCV_LAB_A_MIN_VALUE, lab.a, COLRCV_LAB_MAX_VALUE
    );
}

bool colrcv_lab_b_is_valid(colrcv_lab_t lab) {
    return colrcv_range_valid(
        COLRCV_LAB_B_MIN_VALUE, lab.b, COLRCV_LAB_MAX_VALUE
    );
}

bool colrcv_lab_is_valid(colrcv_lab_t lab) {
    // check that the value of each component is in range
    return (
        colrcv_lab_l_is_valid(lab) &&
        colrcv_lab_a_is_valid(lab) &&
        colrcv_lab_b_is_valid(lab)
    );
}

#ifdef __cplusplus
} // extern "C"
#endif
