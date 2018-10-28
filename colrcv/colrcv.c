/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 *
 * Copyright (C) 2017, 2018, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <stdbool.h>

#include "colrcv.h"


#ifdef __cplusplus
extern "C"{
#endif

// Version numbers are passed as preprocessor definitions by CMake
const colrcv_version_t COLRCV_VERSION = {
    .major = COLRCV_VERSION_MAJOR,
    .minor = COLRCV_VERSION_MINOR,
    .patch = COLRCV_VERSION_PATCH,
    .string = COLRCV_VERSION_STRING,
};

bool colrcv_range_valid(double min, double val, double max) {
    return ((min <= val) && (val <= max));
}

double colrcv_min(double a, double b) {
    return (a < b) ? a : b;
}

double colrcv_max(double a, double b) {
    return (a > b) ? a : b;
}

double colrcv_clamp(double value, double min, double max) {
    // returning the minimum of the maximum is an easy way to clamp
    return colrcv_min(max, colrcv_max(min, value));
}

#ifdef __cplusplus
} // extern "C"
#endif
