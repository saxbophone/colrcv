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
#include "xyz.h"
#include "lab.h"


#ifdef __cplusplus
extern "C"{
#endif

const double COLRCV_XYZ_MIN_VALUE = 0;
const double COLRCV_XYZ_X_MAX_VALUE = 95.047;
const double COLRCV_XYZ_Y_MAX_VALUE = 100;
const double COLRCV_XYZ_Z_MAX_VALUE = 108.883;

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

colrcv_result_t colrcv_xyz_to_lab(colrcv_xyz_t xyz, colrcv_lab_t* lab) {
    // NOTE: Dummy implementation for now
    lab->l = xyz.x;
}

#ifdef __cplusplus
} // extern "C"
#endif
