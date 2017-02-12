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

#ifdef __cplusplus
} // extern "C"
#endif

// end of header file
#endif
