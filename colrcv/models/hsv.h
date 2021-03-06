/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This header file defines the data types for representing colours in
 * the HSV model, and functions for manipulating it.
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
#ifndef SAXBOPHONE_COLRCV_MODELS_HSV_H
#define SAXBOPHONE_COLRCV_MODELS_HSV_H

#include <stdbool.h>

#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent a HSV colour
 * @details This is the Hue/Saturation/Value colour model
 * @since `v0.1.0`
 */
struct colrcv_hsv_t {
    /** @brief The hue. Should be in range 0 -> 360 */
    double h;
    /** @brief The saturation. Should be in range 0 -> 100 */
    double s;
    /** @brief The value. Should be in range 0 -> 100 */
    double v;
};

/**
 * @details The minimum value that any of the components should have
 * @since `v0.1.0`
 */
extern const double COLRCV_HSV_MIN_VALUE;

/**
 * @details The maximum value that the h component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_HSV_H_MAX_VALUE;

/**
 * @details The maximum value that the s component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_HSV_S_MAX_VALUE;

/**
 * @details The maximum value that the v component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_HSV_V_MAX_VALUE;

/**
 * @brief Checks that hue component of a given `colrcv_hsv_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_hsv_h_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Checks that saturation component of a given `colrcv_hsv_t` struct is
 * valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_hsv_s_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Checks that value component of a given `colrcv_hsv_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_hsv_v_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Checks that the components of a given `colrcv_hsv_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_hsv_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Makes all of the channels of a given `colrcv_hsv_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with all channels guaranteed to be within
 * range.
 * @since `v0.4.0`
 */
colrcv_hsv_t colrcv_hsv_clamp(colrcv_hsv_t hsv);

/**
 * @brief Makes the hue channel of a given `colrcv_hsv_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the hue channel guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_hsv_t colrcv_hsv_clamp_h(colrcv_hsv_t hsv);

/**
 * @brief Makes the saturation channel of a given `colrcv_hsv_t` struct fit
 * within the 'standard' range for that channel.
 * @returns A copy of the given struct with the saturation channel guaranteed to
 * be within range.
 * @since `v0.4.0`
 */
colrcv_hsv_t colrcv_hsv_clamp_s(colrcv_hsv_t hsv);

/**
 * @brief Makes the value channel of a given `colrcv_hsv_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with the value channel guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_hsv_t colrcv_hsv_clamp_v(colrcv_hsv_t hsv);

/**
 * @brief Converts a HSV colour to an RGB colour
 * @param hsv A HSV colour to be converted
 * @returns The RGB colour that the HSV colour was converted to
 * @since `v0.1.0`
 */
colrcv_rgb_t colrcv_hsv_to_rgb(colrcv_hsv_t hsv);

/**
 * @brief Converts a HSV colour to a HSL colour
 * @param hsv A HSV colour to be converted
 * @returns The HSL colour that the HSV colour was converted to
 * @since `v0.1.0`
 */
colrcv_hsl_t colrcv_hsv_to_hsl(colrcv_hsv_t hsv);

/**
 * @brief Converts a HSV colour to a LAB colour
 * @param hsv A HSV colour to be converted
 * @returns The LAB colour that the HSV colour was converted to
 * @since `v0.1.0`
 */
colrcv_lab_t colrcv_hsv_to_lab(colrcv_hsv_t hsv);

/**
 * @brief Converts a HSV colour to an XYZ colour
 * @param hsv A HSV colour to be converted
 * @returns The XYZ colour that the HSV colour was converted to
 * @since `v0.1.0`
 */
colrcv_xyz_t colrcv_hsv_to_xyz(colrcv_hsv_t hsv);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
