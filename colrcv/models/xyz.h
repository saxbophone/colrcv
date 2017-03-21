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
 * @author Joshua Saxby `<joshua.a.saxby+TNOPLuc8vM==@gmail.com>`
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
 *
 * @since `v0.1.0`
 */
#ifndef SAXBOPHONE_COLRCV_MODELS_XYZ_H
#define SAXBOPHONE_COLRCV_MODELS_XYZ_H

#include <stdbool.h>

#include "../colrcv.h"
#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent an XYZ colour
 * @details This is the CIE-XYZ colour model. For now, this is assumed to be
 * based on an Observer of 2 degrees and an Illuminant of D65.
 * @since `v0.1.0`
 */
struct colrcv_xyz_t {
    /** @brief The x component. Should be in range 0 -> 112 */
    double x;
    /** @brief The y component. Should be in range 0 -> 100 */
    double y;
    /** @brief The z component. Should be in range 0 -> 123 */
    double z;
};

/**
 * @details The minimum value that any of the components should have
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_MIN_VALUE;

/**
 * @details The maximum value that the x component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_X_MAX_VALUE;
/**
 * @details The maximum value that the y component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_Y_MAX_VALUE;
/**
 * @details The maximum value that the z component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_Z_MAX_VALUE;

/**
 * @details Reference X value for an Observer of 2° and an Illuminant of D65
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_X_REF_VALUE;
/**
 * @details Reference Y value for an Observer of 2° and an Illuminant of D65
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_Y_REF_VALUE;
/**
 * @details Reference Z value for an Observer of 2° and an Illuminant of D65
 * @since `v0.1.0`
 */
extern const double COLRCV_XYZ_Z_REF_VALUE;

/**
 * @brief Checks that x component of a given `colrcv_xyz_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_xyz_x_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Checks that y component of a given `colrcv_xyz_t` struct is
 * valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_xyz_y_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Checks that z component of a given `colrcv_xyz_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_xyz_z_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Checks that the components of a given `colrcv_xyz_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_xyz_is_valid(colrcv_xyz_t xyz);

/**
 * @brief Makes all of the channels of a given `colrcv_xyz_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with all channels guaranteed to be within
 * range.
 * @since `v0.4.0`
 */
colrcv_xyz_t colrcv_xyz_clamp(colrcv_xyz_t xyz);

/**
 * @brief Makes the x component of a given `colrcv_xyz_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the x component guaranteed to
 * be within range.
 * @since `v0.4.0`
 */
colrcv_xyz_t colrcv_xyz_clamp_x(colrcv_xyz_t xyz);

/**
 * @brief Makes the y component of a given `colrcv_xyz_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the y component guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_xyz_t colrcv_xyz_clamp_y(colrcv_xyz_t xyz);

/**
 * @brief Makes the z component of a given `colrcv_xyz_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the z component guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_xyz_t colrcv_xyz_clamp_z(colrcv_xyz_t xyz);

/**
 * @brief Converts an XYZ colour to an RGB colour
 * @param xyz An XYZ colour to be converted
 * @returns The RGB colour that the XYZ colour was converted to
 * @since `v0.1.0`
 */
colrcv_rgb_t colrcv_xyz_to_rgb(colrcv_xyz_t xyz);

/**
 * @brief Converts an XYZ colour to a HSV colour
 * @param xyz An XYZ colour to be converted
 * @returns The HSV colour that the XYZ colour was converted to
 * @since `v0.2.0`
 */
colrcv_hsv_t colrcv_xyz_to_hsv(colrcv_xyz_t xyz);

/**
 * @brief Converts an XYZ colour to a HSL colour
 * @param xyz An XYZ colour to be converted
 * @returns The HSL colour that the XYZ colour was converted to
 * @since `v0.2.0`
 */
colrcv_hsl_t colrcv_xyz_to_hsl(colrcv_xyz_t xyz);

/**
 * @brief Converts an XYZ colour to a LAB colour
 * @param xyz An XYZ colour to be converted
 * @returns The LAB colour that the XYZ colour was converted to
 * @since `v0.1.0`
 */
colrcv_lab_t colrcv_xyz_to_lab(colrcv_xyz_t xyz);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
