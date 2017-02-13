/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the RGB colour model unit (models/rgb.h)
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
#include "../colrcv/models/rgb.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_rgb_r_is_valid
 * Function should return true when given a colrcv_rgb_t struct with a valid
 * red value
 */
static colrcv_test_result_t test_colrcv_rgb_r_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_r_is_valid(
        (colrcv_rgb_t){ .r = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2, }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_r_is_valid
 * Function should return false when given a colrcv_rgb_t struct with an invalid
 * red value
 */
static colrcv_test_result_t test_colrcv_rgb_r_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_r_is_valid(
        (colrcv_rgb_t){ .r = (COLRCV_RGB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_rgb_g_is_valid
 * Function should return true when given a colrcv_rgb_t struct with a valid
 * green value
 */
static colrcv_test_result_t test_colrcv_rgb_g_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_g_is_valid(
        (colrcv_rgb_t){ .g = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2, }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_g_is_valid
 * Function should return false when given a colrcv_rgb_t struct with an invalid
 * green value
 */
static colrcv_test_result_t test_colrcv_rgb_g_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_g_is_valid(
        (colrcv_rgb_t){ .g = (COLRCV_RGB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_rgb_b_is_valid
 * Function should return true when given a colrcv_rgb_t struct with a valid
 * blue value
 */
static colrcv_test_result_t test_colrcv_rgb_b_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_b_is_valid(
        (colrcv_rgb_t){ .b = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2, }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_b_is_valid
 * Function should return false when given a colrcv_rgb_t struct with an invalid
 * blue value
 */
static colrcv_test_result_t test_colrcv_rgb_b_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_b_is_valid(
        (colrcv_rgb_t){ .b = (COLRCV_RGB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_rgb_is_valid
 * Function should return true when given a colrcv_rgb_t struct with valid
 * values
 */
static colrcv_test_result_t test_colrcv_rgb_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_is_valid(
        (colrcv_rgb_t){
            .r = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2,
            .g = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2,
            .b = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_is_valid
 * Function should return false when given a colrcv_rgb_t struct with any
 * invalid values
 */
static colrcv_test_result_t test_colrcv_rgb_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return value
    test.result = colrcv_rgb_b_is_valid(
        (colrcv_rgb_t){
            .r = (COLRCV_RGB_MAX_VALUE * 2),
            .g = (COLRCV_RGB_MAX_VALUE * 2),
            .b = (COLRCV_RGB_MAX_VALUE * 2),
        }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

int main(void) {
    // initialise test suite
    colrcv_test_suite_t suite = colrcv_init_test_suite();
    // add test cases
    colrcv_add_test_case(test_colrcv_rgb_r_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_rgb_r_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_rgb_g_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_rgb_g_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_rgb_b_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_rgb_b_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_rgb_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_rgb_is_valid_false, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
