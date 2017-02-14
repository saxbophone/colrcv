/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the HSL colour model unit (models/hsl.h)
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
#include "../colrcv/models/hsl.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_hsl_h_is_valid
 * Function should return true when given a colrcv_hsl_t struct with a valid
 * hue amount
 */
static colrcv_test_result_t test_colrcv_hsl_h_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_h_is_valid(
        (colrcv_hsl_t){
            .h = (COLRCV_HSL_MIN_VALUE + COLRCV_HSL_H_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsl_h_is_valid
 * Function should return false when given a colrcv_hsl_t struct with an invalid
 * hue amount
 */
static colrcv_test_result_t test_colrcv_hsl_h_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_h_is_valid(
        (colrcv_hsl_t){ .h = (COLRCV_HSL_H_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_hsl_s_is_valid
 * Function should return true when given a colrcv_hsl_t struct with a valid
 * saturation amount
 */
static colrcv_test_result_t test_colrcv_hsl_s_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_s_is_valid(
        (colrcv_hsl_t){
            .s = (COLRCV_HSL_MIN_VALUE + COLRCV_HSL_S_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsl_s_is_valid
 * Function should return false when given a colrcv_hsl_t struct with an invalid
 * saturation amount
 */
static colrcv_test_result_t test_colrcv_hsl_s_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_s_is_valid(
        (colrcv_hsl_t){ .s = (COLRCV_HSL_S_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_hsl_l_is_valid
 * Function should return true when given a colrcv_hsl_t struct with a valid
 * lightness amount
 */
static colrcv_test_result_t test_colrcv_hsl_l_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_l_is_valid(
        (colrcv_hsl_t){
            .l = (COLRCV_HSL_MIN_VALUE + COLRCV_HSL_L_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsl_l_is_valid
 * Function should return false when given a colrcv_hsl_t struct with an invalid
 * lightness amount
 */
static colrcv_test_result_t test_colrcv_hsl_l_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_l_is_valid(
        (colrcv_hsl_t){ .l = (COLRCV_HSL_L_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_hsl_is_valid
 * Function should return true when given a colrcv_hsl_t struct with valid
 * amounts
 */
static colrcv_test_result_t test_colrcv_hsl_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_is_valid(
        (colrcv_hsl_t){
            .h = (COLRCV_HSL_MIN_VALUE + COLRCV_HSL_H_MAX_VALUE) / 2,
            .s = (COLRCV_HSL_MIN_VALUE + COLRCV_HSL_S_MAX_VALUE) / 2,
            .l = (COLRCV_HSL_MIN_VALUE + COLRCV_HSL_L_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsl_is_valid
 * Function should return false when given a colrcv_hsl_t struct with any
 * invalid amounts
 */
static colrcv_test_result_t test_colrcv_hsl_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_hsl_l_is_valid(
        (colrcv_hsl_t){
            .h = (COLRCV_HSL_H_MAX_VALUE * 2),
            .s = (COLRCV_HSL_S_MAX_VALUE * 2),
            .l = (COLRCV_HSL_L_MAX_VALUE * 2),
        }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

int main(void) {
    // initialise test suite
    colrcv_test_suite_t suite = colrcv_init_test_suite();
    // add test cases
    colrcv_add_test_case(test_colrcv_hsl_h_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsl_h_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsl_s_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsl_s_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsl_l_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsl_l_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsl_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsl_is_valid_false, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
