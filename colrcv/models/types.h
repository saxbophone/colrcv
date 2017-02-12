/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This header file forward-declares (via typedef) all the data types
 * used to represent colours in different colour models.
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

/**
 * @brief Used to represent a LAB colour
 * @details This is the CIE-L*ab colour model
 */
typedef struct colrcv_lab_t {
    /** @brief The lightness. Should be in range 0 -> 100 */
    double l;
    /** @brief The a component. Should be in range -100 -> 100 */
    double a;
    /** @brief The b component. Should be in range -100 -> 100 */
    double b;
} colrcv_lab_t;

/**
 * @brief Used to represent an XYZ colour
 * @details This is the CIE-XYZ colour model. The component ranges are based on
 * an Observer of 2 degrees and an Illuminant of D65
 */
typedef struct colrcv_xyz_t {
    /** @brief The x component. Should be in range 0 -> 95.047 */
    double x;
    /** @brief The y component. Should be in range 0 -> 100 */
    double y;
    /** @brief The z component. Should be in range 0 -> 108.883 */
    double z;
} colrcv_xyz_t;

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
