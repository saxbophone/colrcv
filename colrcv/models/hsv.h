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
#ifndef SAXBOPHONE_COLRCV_MODELS_HSV_H
#define SAXBOPHONE_COLRCV_MODELS_HSV_H

#include <stdbool.h>

#include "../colrcv.h"
#include "types.h"


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent a HSV colour
 * @details This is the Hue/Saturation/Value colour model
 */
struct colrcv_hsv_t {
    /** @brief The hue. Should be in range 0 -> 360 */
    double h;
    /** @brief The saturation. Should be in range 0 -> 100 */
    double s;
    /** @brief The value. Should be in range 0 -> 100 */
    double v;
};

/** @details The minimum value that any of the components should have */
extern const double COLRCV_HSV_MIN_VALUE;

/** @details The maximum value that the h component should have */
extern const double COLRCV_HSV_H_MAX_VALUE;

/** @details The maximum value that the s component should have */
extern const double COLRCV_HSV_S_MAX_VALUE;

/** @details The maximum value that the v component should have */
extern const double COLRCV_HSV_V_MAX_VALUE;

/**
 * @brief Checks that hue component of a given `colrcv_hsv_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_hsv_h_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Checks that saturation component of a given `colrcv_hsv_t` struct is
 * valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_hsv_s_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Checks that value component of a given `colrcv_hsv_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_hsv_v_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Checks that the components of a given `colrcv_hsv_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_hsv_is_valid(colrcv_hsv_t hsv);

/**
 * @brief Converts a HSV colour to an RGB colour
 * @param hsv A HSV colour to be converted
 * @param[out] rgb The RGB colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 */
colrcv_result_t colrcv_hsv_to_rgb(colrcv_hsv_t hsv, colrcv_rgb_t* rgb);

/**
 * @brief Converts a HSV colour to a HSL colour
 * @param hsv A HSV colour to be converted
 * @param[out] hsl The HSL colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 */
colrcv_result_t colrcv_hsv_to_hsl(colrcv_hsv_t hsv, colrcv_hsl_t* hsl);

/**
 * @brief Converts a HSV colour to a LAB colour
 * @param hsv A HSV colour to be converted
 * @param[out] lab The LAB colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 * @private @warning Not Implemented
 */
colrcv_result_t colrcv_hsv_to_lab(colrcv_hsv_t hsv, colrcv_lab_t* lab);

/**
 * @brief Converts a HSV colour to an XYZ colour
 * @param hsv A HSV colour to be converted
 * @param[out] xyz The XYZ colour to store the result in
 * @returns Error/success information in a `colrcv_result_t` struct
 * @private @warning Not Implemented
 */
colrcv_result_t colrcv_hsv_to_xyz(colrcv_hsv_t hsv, colrcv_xyz_t* xyz);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
