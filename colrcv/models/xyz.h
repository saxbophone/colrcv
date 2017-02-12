/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This header file defines the data types for representing colours in
 * the XYZ model, and functions for manipulating it.
 *
 * @author Joshua Saxby <joshua.a.saxby+TNOPLuc8vM==@gmail.com
 * @date 2017
 *
 * @copyright Copyright (C) Joshua Saxby 2017
 *
 * @copyright
 * The Copyright holder reserves all rights of this work.
 *
 * @copyright
 * No copying or reproduction is permitted without the express, written consent
 * of the Copyright holder.
 */
#ifndef SAXBOPHONE_COLRCV_MODELS_XYZ_H
#define SAXBOPHONE_COLRCV_MODELS_XYZ_H

#include <stdbool.h>

#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent an XYZ colour
 * @details This is the CIE-XYZ colour model. The component ranges are based on
 * an Observer of 2 degrees and an Illuminant of D65
 */
struct colrcv_xyz_t {
    /** @brief The x component. Should be in range 0 -> 95.047 */
    double x;
    /** @brief The y component. Should be in range 0 -> 100 */
    double y;
    /** @brief The z component. Should be in range 0 -> 108.883 */
    double z;
};

/** @details The minimum value that any of the components should have */
extern const double COLRCV_XYZ_MIN_VALUE;

/** @details The maximum value that the x component should have */
extern const double COLRCV_XYZ_X_MAX_VALUE;

/** @details The maximum value that the y component should have */
extern const double COLRCV_XYZ_Y_MAX_VALUE;

/** @details The maximum value that the z component should have */
extern const double COLRCV_XYZ_Z_MAX_VALUE;

/**
 * @brief Checks that x component of a given `colrcv_xyz_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_xyz_x_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Checks that y component of a given `colrcv_xyz_t` struct is
 * valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_xyz_y_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Checks that z component of a given `colrcv_xyz_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_xyz_z_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Checks that the components of a given `colrcv_xyz_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_xyz_is_valid(colrcv_xyz_t xyz);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif