/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 */

/**
 * @file
 *
 * @brief This is the main header file.
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
#ifndef SAXBOPHONE_COLRCV_COLRCV_H
#define SAXBOPHONE_COLRCV_COLRCV_H

#include <stdbool.h>
#include <stdint.h>


#ifdef __cplusplus
extern "C"{
#endif

/**
 * @brief Used to represent a version of colrcv
 * @details Versions are of the format <MAJOR.MINOR.patch>
 */
typedef struct colrcv_version_t {
    /** @brief The major version number of the version */
    uint16_t major;
    /** @brief The minor version number of the version */
    uint16_t minor;
    /** @brief The patch version number of the version */
    uint16_t patch;
    /** @brief String form of the version (vX.Y.Z) */
    const char* string;
} colrcv_version_t;

/** @brief Stores the current version of colrcv */
extern const colrcv_version_t COLRCV_VERSION;

/**
 * @brief Used to store success/error information returned from a colrcv
 * function
 * @remark This is currently unused and simply typedef'ed to `void`, however it
 * will be used in the future
 */
typedef void colrcv_result_t;

/**
 * @brief A utility function for checking that a given value is in a given range
 * @details Checks that the condition `min <= val <= max` is true
 * @returns `true` if the condition is satisfied
 * @returns `false` if the condition is not satisfied
 */
bool colrcv_range_valid(long double min, long double val, long double max);

/**
 * @brief Get the smallest of two given values
 * @returns The smallest value
 */
long double colrcv_min(long double a, long double b);

/**
 * @brief Get the largest of two given values
 * @returns The largest value
 */
long double colrcv_max(long double a, long double b);

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
