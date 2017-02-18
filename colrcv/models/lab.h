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
#ifndef SAXBOPHONE_COLRCV_MODELS_LAB_H
#define SAXBOPHONE_COLRCV_MODELS_LAB_H

#include <stdbool.h>

#include "../colrcv.h"
#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent a LAB colour
 * @details This is the CIE-L*ab colour model
 */
struct colrcv_lab_t {
    /** @brief The lightness. Should be in range 0 -> 100 */
    double l;
    /** @brief The a component. Should be in range -100 -> 100 */
    double a;
    /** @brief The b component. Should be in range -100 -> 100 */
    double b;
};

/** @details The minimum value that the l component should have */
extern const double COLRCV_LAB_L_MIN_VALUE;

/** @details The minimum value that the a component should have */
extern const double COLRCV_LAB_A_MIN_VALUE;

/** @details The minimum value that the b component should have */
extern const double COLRCV_LAB_B_MIN_VALUE;

/** @details The maximum value that any of the components should have */
extern const double COLRCV_LAB_MAX_VALUE;

/**
 * @brief Checks that hue component of a given `colrcv_lab_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_lab_l_is_valid(colrcv_lab_t lab);

/**
 * @brief Checks that saturation component of a given `colrcv_lab_t` struct is
 * valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_lab_a_is_valid(colrcv_lab_t lab);

/**
 * @brief Checks that value component of a given `colrcv_lab_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_lab_b_is_valid(colrcv_lab_t lab);

/**
 * @brief Checks that the components of a given `colrcv_lab_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_lab_is_valid(colrcv_lab_t lab);

/**
 * @brief Converts a LAB colour to an RGB colour
 * @param lab A LAB colour to be converted
 * @param[out] rgb The RGB colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 * @private @warning Not Implemented
 */
colrcv_result_t colrcv_lab_to_rgb(colrcv_lab_t lab, colrcv_rgb_t* rgb);

/**
 * @brief Converts a LAB colour to a HSV colour
 * @param lab A LAB colour to be converted
 * @param[out] hsv The HSV colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 * @private @warning Not Implemented
 */
colrcv_result_t colrcv_lab_to_hsv(colrcv_lab_t lab, colrcv_hsv_t* hsv);

/**
 * @brief Converts a LAB colour to a HSL colour
 * @param lab A LAB colour to be converted
 * @param[out] hsl The HSL colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 * @private @warning Not Implemented
 */
colrcv_result_t colrcv_lab_to_hsl(colrcv_lab_t lab, colrcv_hsl_t* hsl);

/**
 * @brief Converts a LAB colour to an XYZ colour
 * @param lab A LAB colour to be converted
 * @param[out] xyz The XYZ colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 */
colrcv_result_t colrcv_lab_to_xyz(colrcv_lab_t lab, colrcv_xyz_t* xyz);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
