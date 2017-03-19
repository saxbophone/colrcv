/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the LAB colour model unit (models/lab.h)
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
#include <inttypes.h>

#include "../unit_test_harness/harness.h"
#include "support.h"

#include "../colrcv/models/lab.h"
#include "../colrcv/models/rgb.h"
#include "../colrcv/models/hsv.h"
#include "../colrcv/models/hsl.h"
#include "../colrcv/models/xyz.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_lab_l_is_valid
 * Function should return true when given a colrcv_lab_t struct with a valid
 * lightness amount
 */
static colrcv_test_result_t test_colrcv_lab_l_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_l_is_valid(
        (colrcv_lab_t){
            .l = (COLRCV_LAB_L_MIN_VALUE + COLRCV_LAB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_lab_l_is_valid
 * Function should return false when given a colrcv_lab_t struct with an invalid
 * lightness amount
 */
static colrcv_test_result_t test_colrcv_lab_l_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_l_is_valid(
        (colrcv_lab_t){ .l = (COLRCV_LAB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_lab_a_is_valid
 * Function should return true when given a colrcv_lab_t struct with a valid
 * a component amount
 */
static colrcv_test_result_t test_colrcv_lab_a_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_a_is_valid(
        (colrcv_lab_t){
            .a = (COLRCV_LAB_A_MIN_VALUE + COLRCV_LAB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_lab_a_is_valid
 * Function should return false when given a colrcv_lab_t struct with an invalid
 * a component amount
 */
static colrcv_test_result_t test_colrcv_lab_a_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_a_is_valid(
        (colrcv_lab_t){ .a = (COLRCV_LAB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_lab_b_is_valid
 * Function should return true when given a colrcv_lab_t struct with a valid
 * b component amount
 */
static colrcv_test_result_t test_colrcv_lab_b_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_b_is_valid(
        (colrcv_lab_t){
            .b = (COLRCV_LAB_B_MIN_VALUE + COLRCV_LAB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_lab_b_is_valid
 * Function should return false when given a colrcv_lab_t struct with an invalid
 * b component amount
 */
static colrcv_test_result_t test_colrcv_lab_b_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_b_is_valid(
        (colrcv_lab_t){ .b = (COLRCV_LAB_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_lab_is_valid
 * Function should return true when given a colrcv_lab_t struct with valid
 * amounts
 */
static colrcv_test_result_t test_colrcv_lab_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_is_valid(
        (colrcv_lab_t){
            .l = (COLRCV_LAB_L_MIN_VALUE + COLRCV_LAB_MAX_VALUE) / 2,
            .a = (COLRCV_LAB_A_MIN_VALUE + COLRCV_LAB_MAX_VALUE) / 2,
            .b = (COLRCV_LAB_B_MIN_VALUE + COLRCV_LAB_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_lab_is_valid
 * Function should return false when given a colrcv_lab_t struct with any
 * invalid amounts
 */
static colrcv_test_result_t test_colrcv_lab_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_lab_b_is_valid(
        (colrcv_lab_t){
            .l = (COLRCV_LAB_MAX_VALUE * 2),
            .a = (COLRCV_LAB_MAX_VALUE * 2),
            .b = (COLRCV_LAB_MAX_VALUE * 2),
        }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * LAB and output RGB colours
 */
struct lab_to_rgb_pair_t {
    colrcv_lab_t input;
    colrcv_rgb_t output;
};

/*
 * Test the function colrcv_lab_to_rgb
 * Function should return a correctly calculated RGB colour for the given LAB
 * colour
 */
static colrcv_test_result_t test_colrcv_lab_to_rgb(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct lab_to_rgb_pair_t colours[4] = {
        {
            .input = { .l = 29, .a = 27.343, .b = -17.187, },
            .output = { .r = 97.014, .g = 52.097, .b = 95.28, },
        },
        {
            .input = { .l = 58, .a = -9.375, .b = 47.656, },
            .output = { .r = 148.296, .g = 142.18, .b = 50.972, },
        },
        {
            .input = { .l = 33, .a = 25.781, .b = 25.781, },
            .output = { .r = 123.089, .g = 59.507, .b = 37.976, },
        },
        {
            .input = { .l = 84, .a = 14.843, .b = 100, },
            .output = { .r = 255, .g = 195.812, .b = 0, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_rgb_t result;
        colrcv_lab_to_rgb(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.r, colours[i].output.r) &&
            almost_equal(result.g, colours[i].output.g) &&
            almost_equal(result.b, colours[i].output.b)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
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
 * LAB and output HSV colours
 */
struct lab_to_hsv_pair_t {
    colrcv_lab_t input;
    colrcv_hsv_t output;
};

/*
 * Test the function colrcv_lab_to_hsv
 * Function should return a correctly calculated HSV colour for the given LAB
 * colour
 */
static colrcv_test_result_t test_colrcv_lab_to_hsv(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct lab_to_hsv_pair_t colours[4] = {
        {
            .input = { .l = 26, .a = -20, .b = 126, },
            .output = { .h = 58.786, .s = 100, .v = 26.765, },
        },
        {
            .input = { .l = 100, .a = -71, .b = 47, },
            .output = { .h = 139.25, .s = 55.674, .v = 100, },
        },
        {
            .input = { .l = 0, .a = 0, .b = 0, },
            .output = { .h = 0, .s = 0, .v = 0, },
        },
        {
            .input = { .l = 16, .a = 72, .b = -73, },
            .output = { .h = 266.082, .s = 100, .v = 58.609, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_hsv_t result;
        colrcv_lab_to_hsv(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.h, colours[i].output.h) &&
            almost_equal(result.s, colours[i].output.s) &&
            almost_equal(result.v, colours[i].output.v)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
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
 * LAB and output HSL colours
 */
struct lab_to_hsl_pair_t {
    colrcv_lab_t input;
    colrcv_hsl_t output;
};

/*
 * Test the function colrcv_lab_to_hsl
 * Function should return a correctly calculated HSL colour for the given LAB
 * colour
 */
static colrcv_test_result_t test_colrcv_lab_to_hsl(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct lab_to_hsl_pair_t colours[4] = {
        {
            .input = { .l = 16, .a = -89, .b = -92, },
            .output = { .h = 216.445, .s = 100, .l = 35.211, },
        },
        {
            .input = { .l = 59, .a = 53, .b = 61, },
            .output = { .h = 18.652, .s = 87.882, .l = 53.125, },
        },
        {
            .input = { .l = 0, .a = 0, .b = 0, },
            .output = { .h = 0, .s = 0, .l = 0, },
        },
        {
            .input = { .l = 75, .a = 45, .b = -76, },
            .output = { .h = 252.085, .s = 100, .l = 81.756, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_hsl_t result;
        colrcv_lab_to_hsl(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.h, colours[i].output.h) &&
            almost_equal(result.s, colours[i].output.s) &&
            almost_equal(result.l, colours[i].output.l)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
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

/*
 * An internal struct type used only in this test for storing pairs of input
 * LAB and output XYZ colours
 */
struct lab_to_xyz_pair_t {
    colrcv_lab_t input;
    colrcv_xyz_t output;
};

/*
 * Test the function colrcv_lab_to_xyz
 * Function should return a correctly calculated XYZ colour for the given LAB
 * colour
 */
static colrcv_test_result_t test_colrcv_lab_to_xyz(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct lab_to_xyz_pair_t colours[4] = {
        {
            .input = { .l = 29, .a = 27.343, .b = -17.187, },
            .output = { .x = 8.242, .y = 5.838, .z = 11.586, },
        },
        {
            .input = { .l = 58, .a = -9.375, .b = 47.656, },
            .output = { .x = 22.563, .y = 25.961, .z = 6.95, },
        },
        {
            .input = { .l = 33, .a = 25.781, .b = 25.781, },
            .output = { .x = 10.121, .y = 7.537, .z = 2.753, },
        },
        {
            .input = { .l = 84, .a = 14.843, .b = 100, },
            .output = { .x = 67.402, .y = 64.066, .z = 5.168, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_xyz_t result;
        colrcv_lab_to_xyz(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.x, colours[i].output.x) &&
            almost_equal(result.y, colours[i].output.y) &&
            almost_equal(result.z, colours[i].output.z)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.x, colours[i].output.y, colours[i].output.z,
                result.x, result.y, result.z
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
    colrcv_add_test_case(test_colrcv_lab_l_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_lab_l_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_lab_a_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_lab_a_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_lab_b_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_lab_b_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_lab_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_lab_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_lab_to_rgb, &suite);
    colrcv_add_test_case(test_colrcv_lab_to_hsv, &suite);
    colrcv_add_test_case(test_colrcv_lab_to_hsl, &suite);
    colrcv_add_test_case(test_colrcv_lab_to_xyz, &suite);
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
