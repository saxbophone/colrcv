/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This header file provides miscellaneous extra support functions for use in
 * unit tests.
 * 
 * It is not designed to be used outside of the unit tests for colrcv.
 *
 * Copyright (C) 2017, 2018, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <stdbool.h>


#ifdef __cplusplus
extern "C"{
#endif

// the tolerance which `almost_equal` compares to - 3d.p. is good enough
const double ALMOST = 0.001;

/*
 * compares two fractional numbers for 'almost equality' - defined as `value`
 * being within the range +/-`ALMOST` either side of `check`.
 */
bool almost_equal(double value, double check);

bool almost_equal(double value, double check) {
    return (((check - ALMOST) <= value) && (value <= (check + ALMOST)));
}

#ifdef __cplusplus
} // extern "C"
#endif
