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
 */
struct colrcv_rgb_t {
    /** @brief The red component. Should be in range 0 -> 255 */
    double r;
    /** @brief The green component. Should be in range 0 -> 255 */
    double g;
    /** @brief The blue component. Should be in range 0 -> 255 */
    double b;
};

/** @details The minimum value that any of the components should have */
extern const double COLRCV_RGB_MIN_VALUE;

/** @details The maximum value that any of the components should have */
extern const double COLRCV_RGB_MAX_VALUE;

/**
 * @brief Checks that red component of a given `colrcv_rgb_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_rgb_r_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Checks that green component of a given `colrcv_rgb_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_rgb_g_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Checks that blue component of a given `colrcv_rgb_t` struct is valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_rgb_b_is_valid(colrcv_rgb_t rgb);

/**
 * @brief Checks that the components of a given `colrcv_rgb_t` struct are valid
 * @returns `true` if it is valid
 * @returns `false` if it is not valid
 */
bool colrcv_rgb_is_valid(colrcv_rgb_t rgb);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
