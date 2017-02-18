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
#include <math.h>

#include "../colrcv.h"
#include "lab.h"
#include "xyz.h"


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

// private helper function for colrcv_lab_to_xyz
// // NOTE: This is the inverse of the function of the same name in xyz.c
static double convert_xyz_component(double c) {
    // get c cubed
    const double c_cubed = pow(c, 3.0);
    // converted component depends on size of cubed component
    return (c_cubed > 0.008856) ? c_cubed : ((c - 16.0 / 116.0) / 7.787);
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=08#text8
colrcv_result_t colrcv_lab_to_xyz(colrcv_lab_t lab, colrcv_xyz_t* xyz) {
    // skew input values
    const double y = (lab.l + 16.0) / 116.0;
    const double x = lab.a / 500.0 + y;
    const double z = y - lab.b / 200.0;
    // normalise components and adjust for observer calibration
    xyz->x = COLRCV_XYZ_X_REF_VALUE * convert_xyz_component(x);
    xyz->y = COLRCV_XYZ_Y_REF_VALUE * convert_xyz_component(y);
    xyz->z = COLRCV_XYZ_Z_REF_VALUE * convert_xyz_component(z);
}

#ifdef __cplusplus
} // extern "C"
#endif
