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
#include "xyz.h"
#include "lab.h"


#ifdef __cplusplus
extern "C"{
#endif

const double COLRCV_XYZ_MIN_VALUE = 0;

const double COLRCV_XYZ_X_MAX_VALUE = 112;
const double COLRCV_XYZ_Y_MAX_VALUE = 100;
const double COLRCV_XYZ_Z_MAX_VALUE = 123;

const double COLRCV_XYZ_X_REF_VALUE = 95.047;
const double COLRCV_XYZ_Y_REF_VALUE = 100.0;
const double COLRCV_XYZ_Z_REF_VALUE = 108.883;

bool colrcv_xyz_x_is_valid(colrcv_xyz_t xyz) {
    return colrcv_range_valid(
        COLRCV_XYZ_MIN_VALUE, xyz.x, COLRCV_XYZ_X_MAX_VALUE
    );
}

bool colrcv_xyz_y_is_valid(colrcv_xyz_t xyz) {
    return colrcv_range_valid(
        COLRCV_XYZ_MIN_VALUE, xyz.y, COLRCV_XYZ_Y_MAX_VALUE
    );
}

bool colrcv_xyz_z_is_valid(colrcv_xyz_t xyz) {
    return colrcv_range_valid(
        COLRCV_XYZ_MIN_VALUE, xyz.z, COLRCV_XYZ_Z_MAX_VALUE
    );
}

bool colrcv_xyz_is_valid(colrcv_xyz_t xyz) {
    // check that the value of each component is in range
    return (
        colrcv_xyz_x_is_valid(xyz) &&
        colrcv_xyz_y_is_valid(xyz) &&
        colrcv_xyz_z_is_valid(xyz)
    );
}

// private helper function for colrcv_xyz_to_lab
static double convert_xyz_for_lab(double c) {
    // converted component needs the cube root of input if over a given size
    return (c > 0.008856) ? pow(c, (1.0 / 3)) : (7.787 * c) + (16 / 116);
}

// Algorithm: http://www.easyrgb.com/index.php?X=MATH&H=07#text7
colrcv_result_t colrcv_xyz_to_lab(colrcv_xyz_t xyz, colrcv_lab_t* lab) {
    // skew and convert input values
    const double x = convert_xyz_for_lab(xyz.x / COLRCV_XYZ_X_REF_VALUE);
    const double y = convert_xyz_for_lab(xyz.y / COLRCV_XYZ_Y_REF_VALUE);
    const double z = convert_xyz_for_lab(xyz.z / COLRCV_XYZ_Z_REF_VALUE);
    // convert to LAB ranges
    lab->l = (116 * y) - 16;
    lab->a = 500 * (x - y);
    lab->b = 200 * (y - z);
}

#ifdef __cplusplus
} // extern "C"
#endif
