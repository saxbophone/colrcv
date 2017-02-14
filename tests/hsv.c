/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the HSV colour model unit (models/hsv.h)
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

#include "../unit_test_harness/harness.h"
#include "../colrcv/models/hsv.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_hsv_h_is_valid
 * Function should return true when given a colrcv_hsv_t struct with a valid
 * hue amount
 */
static colrcv_test_result_t test_colrcv_hsv_h_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_h_is_valid(
        (colrcv_hsv_t){
            .h = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_H_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsv_h_is_valid
 * Function should return false when given a colrcv_hsv_t struct with an invalid
 * hue amount
 */
static colrcv_test_result_t test_colrcv_hsv_h_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_h_is_valid(
        (colrcv_hsv_t){ .h = (COLRCV_HSV_H_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_hsv_s_is_valid
 * Function should return true when given a colrcv_hsv_t struct with a valid
 * saturation amount
 */
static colrcv_test_result_t test_colrcv_hsv_s_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_s_is_valid(
        (colrcv_hsv_t){
            .s = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_S_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsv_s_is_valid
 * Function should return false when given a colrcv_hsv_t struct with an invalid
 * saturation amount
 */
static colrcv_test_result_t test_colrcv_hsv_s_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_s_is_valid(
        (colrcv_hsv_t){ .s = (COLRCV_HSV_S_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_hsv_v_is_valid
 * Function should return true when given a colrcv_hsv_t struct with a valid
 * value amount
 */
static colrcv_test_result_t test_colrcv_hsv_v_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_v_is_valid(
        (colrcv_hsv_t){
            .v = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_V_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsv_v_is_valid
 * Function should return false when given a colrcv_hsv_t struct with an invalid
 * value amount
 */
static colrcv_test_result_t test_colrcv_hsv_v_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_v_is_valid(
        (colrcv_hsv_t){ .v = (COLRCV_HSV_V_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_hsv_is_valid
 * Function should return true when given a colrcv_hsv_t struct with valid
 * amounts
 */
static colrcv_test_result_t test_colrcv_hsv_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_is_valid(
        (colrcv_hsv_t){
            .h = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_H_MAX_VALUE) / 2,
            .s = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_S_MAX_VALUE) / 2,
            .v = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_V_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsv_is_valid
 * Function should return false when given a colrcv_hsv_t struct with any
 * invalid amounts
 */
static colrcv_test_result_t test_colrcv_hsv_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsv_v_is_valid(
        (colrcv_hsv_t){
            .h = (COLRCV_HSV_H_MAX_VALUE * 2),
            .s = (COLRCV_HSV_S_MAX_VALUE * 2),
            .v = (COLRCV_HSV_V_MAX_VALUE * 2),
        }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

int main(void) {
    // initialise test suite
    colrcv_test_suite_t suite = colrcv_init_test_suite();
    // add test cases
    colrcv_add_test_case(test_colrcv_hsv_h_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_h_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_s_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_s_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_v_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_v_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_is_valid_false, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
