/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 *
 *
 * Copyright (C) 2017, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 * 
 * The Copyright holder reserves all rights of this work.
 * 
 * No copying or reproduction is permitted without the express, written consent
 * of the Copyright holder.
 */
#include "colrcv.h"


#ifdef __cplusplus
extern "C"{
#endif

// Version numbers are passed as preprocessor definitions by CMake
const colrcv_version_t COLRCV_VERSION = {
    .major = COLRCV_VERSION_MAJOR,
    .minor = COLRCV_VERSION_MINOR,
    .patch = COLRCV_VERSION_PATCH,
    .string = COLRCV_VERSION_STRING,
};

#ifdef __cplusplus
} // extern "C"
#endif
