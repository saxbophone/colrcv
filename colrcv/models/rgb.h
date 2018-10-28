/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This header file defines the data types for representing colours in
 * the RGB model, and functions for manipulating it.
 *
 * @author Joshua Saxby `<joshua.a.saxby+TNOPLuc8vM==@gmail.com>`
 * @date 2018
 *
 * @copyright Copyright (C) Joshua Saxby 2017, 2018
 *
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @since `v0.1.0`
 */
#ifndef SAXBOPHONE_COLRCV_MODELS_RGB_H
#define SAXBOPHONE_COLRCV_MODELS_RGB_H

#include <stdbool.h>

#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent an RGB colour
 * @details This is the ubquitous RGB Red/Green/Blue) video display colour
 * model
 * @since `v0.1.0`
 */
struct colrcv_rgb_t {
    /** @brief The red component. Should be in range 0 -> 255 */
    double r;
    /** @brief The green component. Should be in range 0 -> 255 */
    double g;
    /** @brief The blue component. Should be in range 0 -> 255 */
    double b;
};

/**
 * @details The minimum value that any of the components should have
 * @since `v0.1.0`
 */
extern const double COLRCV_RGB_MIN_VALUE;

/**
 * @details The maximum value that any of the components should have
 * @since `v0.1.0`
 */
extern const double COLRCV_RGB_MAX_VALUE;

/**
 * @brief Checks that red component of a given `colrcv_rgb_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_rgb_r_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Checks that green component of a given `colrcv_rgb_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_rgb_g_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Checks that blue component of a given `colrcv_rgb_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_rgb_b_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Checks that the components of a given `colrcv_rgb_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_rgb_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Makes all of the channels of a given `colrcv_rgb_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with all channels guaranteed to be within
 * range.
 * @since `v0.4.0`
 */
colrcv_rgb_t colrcv_rgb_clamp(colrcv_rgb_t rgb);

/**
 * @brief Makes the red channel of a given `colrcv_rgb_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the red channel guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_rgb_t colrcv_rgb_clamp_r(colrcv_rgb_t rgb);

/**
 * @brief Makes the green channel of a given `colrcv_rgb_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with the green channel guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_rgb_t colrcv_rgb_clamp_g(colrcv_rgb_t rgb);

/**
 * @brief Makes the blue channel of a given `colrcv_rgb_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with the blue channel guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_rgb_t colrcv_rgb_clamp_b(colrcv_rgb_t rgb);

/**
 * @brief Converts an RGB colour to a HSV colour
 * @param rgb An RGB colour to be converted
 * @returns The HSV colour that the RGB colour was converted to
 * @since `v0.1.0`
 */
colrcv_hsv_t colrcv_rgb_to_hsv(colrcv_rgb_t rgb);

/**
 * @brief Converts an RGB colour to a HSL colour
 * @param rgb An RGB colour to be converted
 * @returns The HSL colour that the RGB colour was converted to
 * @since `v0.1.0`
 */
colrcv_hsl_t colrcv_rgb_to_hsl(colrcv_rgb_t rgb);

/**
 * @brief Converts an RGB colour to a LAB colour
 * @param rgb An RGB colour to be converted
 * @returns The LAB colour that the RGB colour was converted to
 * @since `v0.1.0`
 */
colrcv_lab_t colrcv_rgb_to_lab(colrcv_rgb_t rgb);

/**
 * @brief Converts an RGB colour to an XYZ colour
 * @param rgb An RGB colour to be converted
 * @returns The XYZ colour that the RGB colour was converted to
 * @since `v0.1.0`
 */
colrcv_xyz_t colrcv_rgb_to_xyz(colrcv_rgb_t rgb);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
