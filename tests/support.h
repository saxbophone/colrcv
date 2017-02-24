/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This header file provides miscellaneous extra support functions for use in
 * unit tests.
 * 
 * It is not designed to be used outside of the unit tests for colrcv.
 *
 *
 * Copyright (C) 2017, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * The Copyright holder reserves all rights of this work.
 *
 * No copying or reproduction is permitted without the express, written consent
 * of the Copyright holder.
 */
#include <stdbool.h>


#ifdef __cplusplus
extern "C"{
#endif

// the tolerance which `almost_equal` compares to - 3d.p. is good enough
const long double ALMOST = 0.001;

/*
 * compares two fractional numbers for 'almost equality' - defined as `value`
 * being within the range +/-`ALMOST` either side of `check`.
 */
bool almost_equal(long double value, long double check);

bool almost_equal(long double value, long double check) {
    return (((check - ALMOST) <= value) && (value <= (check + ALMOST)));
}

#ifdef __cplusplus
} // extern "C"
#endif
