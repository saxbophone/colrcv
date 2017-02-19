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
#include <stdio.h>

#include "../unit_test_harness/harness.h"
#include "support.h"

#include "../colrcv/models/hsv.h"
#include "../colrcv/models/rgb.h"
#include "../colrcv/models/hsl.h"


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

/*
 * An internal struct type used only in this test for storing pairs of input
 * HSV and output RGB colours
 */
struct hsv_to_rgb_pair_t {
    colrcv_hsv_t input;
    colrcv_rgb_t output;
};

/*
 * Test the function colrcv_hsv_to_rgb
 * Function should return a correctly calculated RGB colour for the given HSV
 * colour
 */
static colrcv_test_result_t test_colrcv_hsv_to_rgb(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsv_to_rgb_pair_t colours[4] = {
        {
            .input = { .h = 108, .s = 86, .v = 86, },
            .output = { .r = 68.421, .g = 219.3, .b = 30.702, },
        },
        {
            .input = { .h = 8, .s = 91, .v = 85, },
            .output = { .r = 216.75, .g = 45.806, .b = 19.507, },
        },
        {
            .input = { .h = 0, .s = 0, .v = 13, },
            .output = { .r = 33.15, .g = 33.15, .b = 33.15, },
        },
        {
            .input = { .h = 20, .s = 75, .v = 100, },
            .output = { .r = 255, .g = 127.5, .b = 63.75, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_rgb_t result;
        colrcv_hsv_to_rgb(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.r, colours[i].output.r) &&
            almost_equal(result.g, colours[i].output.g) &&
            almost_equal(result.b, colours[i].output.b)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%zu:\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.r, colours[i].output.g, colours[i].output.b,
                result.r, result.g, result.b
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
 * HSV and output HSL colours
 */
struct hsv_to_hsl_pair_t {
    colrcv_hsv_t input;
    colrcv_hsl_t output;
};

/*
 * Test the function colrcv_hsv_to_hsl
 * Function should return a correctly calculated HSL colour for the given HSV
 * colour
 */
static colrcv_test_result_t test_colrcv_hsv_to_hsl(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsv_to_hsl_pair_t colours[4] = {
        {
            .input = { .h = 281, .s = 100, .v = 26, },
            .output = { .h = 281, .s = 100, .l = 13, },
        },
        {
            .input = { .h = 62, .s = 54, .v = 47, },
            .output = { .h = 62, .s = 36.986, .l = 34.31, },
        },
        {
            .input = { .h = 53, .s = 78, .v = 88, },
            .output = { .h = 53, .s = 74.093, .l = 53.68, },
        },
        {
            .input = { .h = 189, .s = 87, .v = 35, },
            .output = { .h = 189, .s = 76.991, .l = 19.775, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_hsl_t result;
        colrcv_hsv_to_hsl(colours[i].input, &result);
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
    colrcv_add_test_case(test_colrcv_hsv_h_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_h_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_s_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_s_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_v_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_v_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_to_rgb, &suite);
    colrcv_add_test_case(test_colrcv_hsv_to_hsl, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
