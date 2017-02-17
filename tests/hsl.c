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
#include <stdio.h>

#include "../unit_test_harness/harness.h"
#include "support.h"

#include "../colrcv/models/hsl.h"
#include "../colrcv/models/rgb.h"


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

/*
 * An internal struct type used only in this test for storing pairs of input
 * HSL and output RGB colours
 */
struct hsl_to_rgb_pair_t {
    colrcv_hsl_t input;
    colrcv_rgb_t output;
};

/*
 * Test the function colrcv_hsl_to_rgb
 * Function should return a correctly calculated RGB colour for the given HSL
 * colour
 */
static colrcv_test_result_t test_colrcv_hsl_to_rgb(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsl_to_rgb_pair_t colours[4] = {
        {
            .input = { .h = 108, .s = 86, .l = 86, },
            .output = { .r = 200.878, .g = 250.002, .b = 188.598, },
        },
        {
            .input = { .h = 8, .s = 91, .l = 85, },
            .output = { .r = 251.557, .g = 191.224, .b = 181.942, },
        },
        {
            .input = { .h = 0, .s = 0, .l = 13, },
            .output = { .r = 33.15, .g = 33.15, .b = 33.15, },
        },
        {
            .input = { .h = 20, .s = 75, .l = 100, },
            .output = { .r = 255, .g = 255, .b = 255, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_rgb_t result;
        colrcv_hsl_to_rgb(colours[i].input, &result);
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
    colrcv_add_test_case(test_colrcv_hsl_to_rgb, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
