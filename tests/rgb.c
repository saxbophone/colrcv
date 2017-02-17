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
#include <stdio.h>

#include "../unit_test_harness/harness.h"
#include "support.h"

#include "../colrcv/models/rgb.h"
#include "../colrcv/models/hsv.h"
#include "../colrcv/models/hsl.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_rgb_r_is_valid
 * Function should return true when given a colrcv_rgb_t struct with a valid
 * red amount
 */
static colrcv_test_result_t test_colrcv_rgb_r_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_r_is_valid(
        (colrcv_rgb_t){
            .r = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_r_is_valid
 * Function should return false when given a colrcv_rgb_t struct with an invalid
 * red amount
 */
static colrcv_test_result_t test_colrcv_rgb_r_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_r_is_valid(
        (colrcv_rgb_t){ .r = (COLRCV_RGB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_rgb_g_is_valid
 * Function should return true when given a colrcv_rgb_t struct with a valid
 * green amount
 */
static colrcv_test_result_t test_colrcv_rgb_g_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_g_is_valid(
        (colrcv_rgb_t){
            .g = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_g_is_valid
 * Function should return false when given a colrcv_rgb_t struct with an invalid
 * green amount
 */
static colrcv_test_result_t test_colrcv_rgb_g_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_g_is_valid(
        (colrcv_rgb_t){ .g = (COLRCV_RGB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_rgb_b_is_valid
 * Function should return true when given a colrcv_rgb_t struct with a valid
 * blue amount
 */
static colrcv_test_result_t test_colrcv_rgb_b_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_b_is_valid(
        (colrcv_rgb_t){
            .b = (COLRCV_RGB_MIN_VALUE + COLRCV_RGB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_rgb_b_is_valid
 * Function should return false when given a colrcv_rgb_t struct with an invalid
 * blue amount
 */
static colrcv_test_result_t test_colrcv_rgb_b_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_b_is_valid(
        (colrcv_rgb_t){ .b = (COLRCV_RGB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_rgb_is_valid
 * Function should return true when given a colrcv_rgb_t struct with valid
 * amounts
 */
static colrcv_test_result_t test_colrcv_rgb_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
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
 * invalid amounts
 */
static colrcv_test_result_t test_colrcv_rgb_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_rgb_b_is_valid(
        (colrcv_rgb_t){
            .r = (COLRCV_RGB_MAX_VALUE * 2),
            .g = (COLRCV_RGB_MAX_VALUE * 2),
            .b = (COLRCV_RGB_MAX_VALUE * 2),
        }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * RGB and output HSV colours
 */
struct rgb_to_hsv_pair_t {
    colrcv_rgb_t input;
    colrcv_hsv_t output;
};

/*
 * Test the function colrcv_rgb_to_hsv
 * Function should return a correctly calculated HSV colour for the given RGB
 * colour
 */
static colrcv_test_result_t test_colrcv_rgb_to_hsv(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct rgb_to_hsv_pair_t colours[4] = {
        {
            .input = { .r = 69, .g = 219, .b = 31, },
            .output = { .h = 107.872, .s = 85.844, .v = 85.882, },
        },
        {
            .input = { .r = 217, .g = 45, .b = 19, },
            .output = { .h = 7.878, .s = 91.244, .v = 85.098, },
        },
        {
            .input = { .r = 33, .g = 33, .b = 33, },
            .output = { .h = 0, .s = 0, .v = 12.941, },
        },
        {
            .input = { .r = 255, .g = 127, .b = 63, },
            .output = { .h = 20, .s = 75.294, .v = 100, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_hsv_t result;
        colrcv_rgb_to_hsv(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.h, colours[i].output.h) &&
            almost_equal(result.s, colours[i].output.s) &&
            almost_equal(result.v, colours[i].output.v)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%zu:\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.h, colours[i].output.s, colours[i].output.v,
                result.h, result.s, result.v
            );
        }
        // OR to success flag
        success = success && conversion_ok;
    }

    test.result = success ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;
    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * RGB and output HSL colours
 */
struct rgb_to_hsl_pair_t {
    colrcv_rgb_t input;
    colrcv_hsl_t output;
};

/*
 * Test the function colrcv_rgb_to_hsl
 * Function should return a correctly calculated HSL colour for the given RGB
 * colour
 */
static colrcv_test_result_t test_colrcv_rgb_to_hsl(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct rgb_to_hsl_pair_t colours[4] = {
        {
            .input = { .r = 69, .g = 219, .b = 31, },
            .output = { .h = 107.872, .s = 75.2, .l = 49.02, },
        },
        {
            .input = { .r = 217, .g = 45, .b = 19, },
            .output = { .h = 7.878, .s = 83.9, .l = 46.27, },
        },
        {
            .input = { .r = 33, .g = 33, .b = 33, },
            .output = { .h = 0, .s = 0, .l = 12.941, },
        },
        {
            .input = { .r = 255, .g = 127, .b = 63, },
            .output = { .h = 20, .s = 100, .l = 62.35, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_hsl_t result;
        colrcv_rgb_to_hsl(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.h, colours[i].output.h) &&
            almost_equal(result.s, colours[i].output.s) &&
            almost_equal(result.l, colours[i].output.l)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%zu:\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.h, colours[i].output.s, colours[i].output.l,
                result.h, result.s, result.l
            );
        }
        // OR to success flag
        success = success && conversion_ok;
    }

    test.result = success ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;
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
    colrcv_add_test_case(test_colrcv_rgb_to_hsv, &suite);
    colrcv_add_test_case(test_colrcv_rgb_to_hsl, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
