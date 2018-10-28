/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the main header of the library (colrcv.h)
 *
 * Copyright (C) 2017, 2018, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <stdbool.h>

#include "../unit_test_harness/harness.h"
#include "../colrcv/colrcv.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_range_valid
 * Function should return true when given a range of values that are in order
 * from lowest to highest
 */
static colrcv_test_result_t test_colrcv_range_valid_ascending(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        -312, 43.3, 972.1
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_range_valid
 * Function should return true when given a range of values that are in order
 * from lowest to highest, but where the first and second values are equal
 */
static colrcv_test_result_t test_colrcv_range_valid_ascending_low_equal(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        -100, -100, 190
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_range_valid
 * Function should return true when given a range of values that are in order
 * from lowest to highest, but where the second and third values are equal
 */
static colrcv_test_result_t test_colrcv_range_valid_ascending_high_equal(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        -100, 312, 312
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_range_valid
 * Function should return true when given a range of values that are all equal
 */
static colrcv_test_result_t test_colrcv_range_valid_all_equal(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        0.0, 0.0, 0.0
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_range_valid
 * Function should return false when given a range of values that are in order
 * from highest to lowest
 */
static colrcv_test_result_t test_colrcv_range_valid_descending(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        9999, 2222, 1111
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_range_valid
 * Function should return false when given a range of values where the middle
 * value is lower than the minimum value
 */
static colrcv_test_result_t test_colrcv_range_valid_min_exceeded(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        -1, -16, 32
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_range_valid
 * Function should return false when given a range of values where the middle
 * value is higher than the maximum value
 */
static colrcv_test_result_t test_colrcv_range_valid_max_exceeded(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_range_valid(
        99, 267, 128
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

// test case helper for functions testing colrcv_clamp
static colrcv_test_status_t test_colrcv_clamp(
    double value, double min, double max, double expected_value
) {
    return (
        colrcv_clamp(value, min, max) == expected_value
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;
}

/*
 * Test the function colrcv_clamp
 * Functon should return the same value when the given value is within the given
 * range
 */
static colrcv_test_result_t test_colrcv_clamp_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    test.result = test_colrcv_clamp(19.7, -246.7, 1339.1, 19.7);

    return test;
}

/*
 * Test the function colrcv_clamp
 * Functon should return the minimum value when the given value is smaller than
 * the minimum value of the range
 */
static colrcv_test_result_t test_colrcv_clamp_less_than_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    test.result = test_colrcv_clamp(-3000, 0.0, 10.0, 0.0);

    return test;
}

/*
 * Test the function colrcv_clamp
 * Functon should return the maximum value when the given value is greater than
 * the minimum value of the range
 */
static colrcv_test_result_t test_colrcv_clamp_greater_than_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    test.result = test_colrcv_clamp(1000000, -100, 100, 100);

    return test;
}

int main(void) {
    // initialise test suite
    colrcv_test_suite_t suite = colrcv_init_test_suite();
    // add test cases
    colrcv_add_test_case(test_colrcv_range_valid_ascending, &suite);
    colrcv_add_test_case(test_colrcv_range_valid_ascending_low_equal, &suite);
    colrcv_add_test_case(test_colrcv_range_valid_ascending_high_equal, &suite);
    colrcv_add_test_case(test_colrcv_range_valid_all_equal, &suite);
    colrcv_add_test_case(test_colrcv_range_valid_descending, &suite);
    colrcv_add_test_case(test_colrcv_range_valid_min_exceeded, &suite);
    colrcv_add_test_case(test_colrcv_range_valid_max_exceeded, &suite);
    colrcv_add_test_case(test_colrcv_clamp_within_range, &suite);
    colrcv_add_test_case(test_colrcv_clamp_less_than_range, &suite);
    colrcv_add_test_case(test_colrcv_clamp_greater_than_range, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // free test suite
    colrcv_free_test_suite(suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
