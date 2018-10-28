/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This header file forward-declares (via typedef) all the data types
 * used to represent colours in different colour models.
 * @details This is necessary to avoid circular references between header files.
 * @remarks There is no need to include this header file directly, and doing so
 * does not reap any benefits. Use the colour-model specific header files to get
 * the respective colour models types and functions declared within them.
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
#ifndef SAXBOPHONE_COLRCV_MODELS_TYPES_H
#define SAXBOPHONE_COLRCV_MODELS_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif

// RGB
typedef struct colrcv_rgb_t colrcv_rgb_t;

// HSV
typedef struct colrcv_hsv_t colrcv_hsv_t;

// HSL
typedef struct colrcv_hsl_t colrcv_hsl_t;

// LAB
typedef struct colrcv_lab_t colrcv_lab_t;

// XYZ
typedef struct colrcv_xyz_t colrcv_xyz_t;

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
