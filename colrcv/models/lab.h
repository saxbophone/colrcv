/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This header file defines the data types for representing colours in
 * the LAB model, and functions for manipulating it.
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
#ifndef SAXBOPHONE_COLRCV_MODELS_LAB_H
#define SAXBOPHONE_COLRCV_MODELS_LAB_H

#include <stdbool.h>

#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent a LAB colour
 * @details This is the CIE-L*ab colour model
 * @since `v0.1.0`
 */
struct colrcv_lab_t {
    /** @brief The lightness. Should be in range 0 -> 100 */
    double l;
    /** @brief The a component. Should be in range -100 -> 100 */
    double a;
    /** @brief The b component. Should be in range -100 -> 100 */
    double b;
};

/**
 * @details The minimum value that the l component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_LAB_L_MIN_VALUE;

/**
 * @details The minimum value that the a component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_LAB_A_MIN_VALUE;

/**
 * @details The minimum value that the b component should have
 * @since `v0.1.0`
 */
extern const double COLRCV_LAB_B_MIN_VALUE;

/**
 * @details The maximum value that any of the components should have
 * @since `v0.1.0`
 */
extern const double COLRCV_LAB_MAX_VALUE;

/**
 * @brief Checks that hue component of a given `colrcv_lab_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_lab_l_is_valid(colrcv_lab_t lab);

/**
 * @brief Checks that saturation component of a given `colrcv_lab_t` struct is
 * valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_lab_a_is_valid(colrcv_lab_t lab);

/**
 * @brief Checks that value component of a given `colrcv_lab_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_lab_b_is_valid(colrcv_lab_t lab);

/**
 * @brief Checks that the components of a given `colrcv_lab_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 * @since `v0.1.0`
 */
bool colrcv_lab_is_valid(colrcv_lab_t lab);

/**
 * @brief Makes all of the channels of a given `colrcv_lab_t` struct fit within
 * the 'standard' range for that channel.
 * @returns A copy of the given struct with all channels guaranteed to be within
 * range.
 * @since `v0.4.0`
 */
colrcv_lab_t colrcv_lab_clamp(colrcv_lab_t lab);

/**
 * @brief Makes the lightness channel of a given `colrcv_lab_t` struct fit
 * within the 'standard' range for that channel.
 * @returns A copy of the given struct with the lightness channel guaranteed to
 * be within range.
 * @since `v0.4.0`
 */
colrcv_lab_t colrcv_lab_clamp_l(colrcv_lab_t lab);

/**
 * @brief Makes the a component of a given `colrcv_lab_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the a component guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_lab_t colrcv_lab_clamp_a(colrcv_lab_t lab);

/**
 * @brief Makes the b component of a given `colrcv_lab_t` struct fit within the
 * 'standard' range for that channel.
 * @returns A copy of the given struct with the b component guaranteed to be
 * within range.
 * @since `v0.4.0`
 */
colrcv_lab_t colrcv_lab_clamp_b(colrcv_lab_t lab);

/**
 * @brief Converts a LAB colour to an RGB colour
 * @param lab A LAB colour to be converted
 * @returns The RGB colour that the LAB colour was converted to
 * @since `v0.1.0`
 */
colrcv_rgb_t colrcv_lab_to_rgb(colrcv_lab_t lab);

/**
 * @brief Converts a LAB colour to a HSV colour
 * @param lab A LAB colour to be converted
 * @returns The HSV colour that the LAB colour was converted to
 * @since `v0.2.0`
 */
colrcv_hsv_t colrcv_lab_to_hsv(colrcv_lab_t lab);

/**
 * @brief Converts a LAB colour to a HSL colour
 * @param lab A LAB colour to be converted
 * @returns The HSL colour that the LAB colour was converted to
 * @since `v0.2.0`
 */
colrcv_hsl_t colrcv_lab_to_hsl(colrcv_lab_t lab);

/**
 * @brief Converts a LAB colour to an XYZ colour
 * @param lab A LAB colour to be converted
 * @returns The XYZ colour that the LAB colour was converted to
 * @since `v0.1.0`
 */
colrcv_xyz_t colrcv_lab_to_xyz(colrcv_lab_t lab);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
