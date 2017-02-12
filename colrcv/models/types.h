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
