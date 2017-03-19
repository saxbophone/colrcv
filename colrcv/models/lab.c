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
#include "rgb.h"
#include "hsv.h"
#include "hsl.h"
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

// Two-step conversion using LAB->XYZ and XYZ->RGB
colrcv_result_t colrcv_lab_to_rgb(colrcv_lab_t lab, colrcv_rgb_t* rgb) {
    // convert to XYZ first
    colrcv_xyz_t xyz;
    colrcv_lab_to_xyz(lab, &xyz);
    // now convert to RGB
    colrcv_xyz_to_rgb(xyz, rgb);
}

// Two-step conversion using LAB->RGB and RGB->HSV
colrcv_result_t colrcv_lab_to_hsv(colrcv_lab_t lab, colrcv_hsv_t* hsv) {
    // convert to RGB first
    colrcv_rgb_t rgb;
    colrcv_lab_to_rgb(lab, &rgb);
    // now convert to HSV
    colrcv_rgb_to_hsv(rgb, hsv);
}

// Two-step conversion using LAB->RGB and RGB->HSL
colrcv_result_t colrcv_lab_to_hsl(colrcv_lab_t lab, colrcv_hsl_t* hsl) {
    // convert to RGB first
    colrcv_rgb_t rgb;
    colrcv_lab_to_rgb(lab, &rgb);
    // now convert to HSL
    colrcv_rgb_to_hsl(rgb, hsl);
}

// private helper function for colrcv_lab_to_xyz
static double convert_lab_for_xyz(double c) {
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
    xyz->x = COLRCV_XYZ_X_REF_VALUE * convert_lab_for_xyz(x);
    xyz->y = COLRCV_XYZ_Y_REF_VALUE * convert_lab_for_xyz(y);
    xyz->z = COLRCV_XYZ_Z_REF_VALUE * convert_lab_for_xyz(z);
}

#ifdef __cplusplus
} // extern "C"
#endif
