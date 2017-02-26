/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the XYZ colour model unit (models/xyz.h)
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

#include "../colrcv/models/xyz.h"
#include "../colrcv/models/rgb.h"
#include "../colrcv/models/lab.h"


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Test the function colrcv_xyz_x_is_valid
 * Function should return true when given a colrcv_xyz_t struct with a valid
 * x component amount
 */
static colrcv_test_result_t test_colrcv_xyz_x_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_x_is_valid(
        (colrcv_xyz_t){
            .x = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_X_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_xyz_x_is_valid
 * Function should return false when given a colrcv_xyz_t struct with an invalid
 * x component amount
 */
static colrcv_test_result_t test_colrcv_xyz_x_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_x_is_valid(
        (colrcv_xyz_t){ .x = (COLRCV_XYZ_X_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_xyz_y_is_valid
 * Function should return true when given a colrcv_xyz_t struct with a valid
 * y component amount
 */
static colrcv_test_result_t test_colrcv_xyz_y_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_y_is_valid(
        (colrcv_xyz_t){
            .y = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Y_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_xyz_y_is_valid
 * Function should return false when given a colrcv_xyz_t struct with an invalid
 * y component amount
 */
static colrcv_test_result_t test_colrcv_xyz_y_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_y_is_valid(
        (colrcv_xyz_t){ .y = (COLRCV_XYZ_Y_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_xyz_z_is_valid
 * Function should return true when given a colrcv_xyz_t struct with a valid
 * z component amount
 */
static colrcv_test_result_t test_colrcv_xyz_z_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_z_is_valid(
        (colrcv_xyz_t){
            .z = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Z_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_xyz_z_is_valid
 * Function should return false when given a colrcv_xyz_t struct with an invalid
 * z component amount
 */
static colrcv_test_result_t test_colrcv_xyz_z_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_z_is_valid(
        (colrcv_xyz_t){ .z = (COLRCV_XYZ_Z_MAX_VALUE * 2), }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * Test the function colrcv_xyz_is_valid
 * Function should return true when given a colrcv_xyz_t struct with valid
 * amounts
 */
static colrcv_test_result_t test_colrcv_xyz_is_valid_true(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_is_valid(
        (colrcv_xyz_t){
            .x = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_X_MAX_VALUE) / 2,
            .y = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Y_MAX_VALUE) / 2,
            .z = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Z_MAX_VALUE) / 2,
        }
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_xyz_is_valid
 * Function should return false when given a colrcv_xyz_t struct with any
 * invalid amounts
 */
static colrcv_test_result_t test_colrcv_xyz_is_valid_false(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result based on boolean return amount
    test.result = colrcv_xyz_z_is_valid(
        (colrcv_xyz_t){
            .x = (COLRCV_XYZ_X_MAX_VALUE * 2),
            .y = (COLRCV_XYZ_Y_MAX_VALUE * 2),
            .z = (COLRCV_XYZ_Z_MAX_VALUE * 2),
        }
    ) ? COLRCV_TEST_FAIL : COLRCV_TEST_SUCCESS;

    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * XYZ and output RGB colours
 */
struct xyz_to_rgb_pair_t {
    colrcv_xyz_t input;
    colrcv_rgb_t output;
};

/*
 * Test the function colrcv_xyz_to_rgb
 * Function should return a correctly calculated RGB colour for the given XYZ
 * colour
 */
static colrcv_test_result_t test_colrcv_xyz_to_rgb(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct xyz_to_rgb_pair_t colours[4] = {
        {
            .input = { .x = 50, .y = 25, .z = 65, },
            .output = { .r = 244.859, .g = 27.792, .b = 212.788, },
        },
        {
            .input = { .x = 87, .y = 100, .z = 0, },
            .output = { .r = 255, .g = 255, .b = 0, },
        },
        {
            .input = { .x = 1, .y = 2, .z = 1, },
            .output = { .r = 0, .g = 46.835, .b = 20.104, },
        },
        {
            .input = { .x = 33, .y = 77, .z = 63, },
            .output = { .r = 0, .g = 255, .b = 192.015, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_rgb_t result;
        colrcv_xyz_to_rgb(colours[i].input, &result);
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
 * XYZ and output LAB colours
 */
struct xyz_to_lab_pair_t {
    colrcv_xyz_t input;
    colrcv_lab_t output;
};

/*
 * Test the function colrcv_xyz_to_lab
 * Function should return a correctly calculated LAB colour for the given XYZ
 * colour
 */
static colrcv_test_result_t test_colrcv_xyz_to_lab(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct xyz_to_lab_pair_t colours[4] = {
        {
            .input = { .x = 8.242, .y = 5.838, .z = 11.586, },
            .output = { .l = 29, .a = 27.344, .b = -17.187, },
        },
        {
            .input = { .x = 22.563, .y = 25.961, .z = 6.95, },
            .output = { .l = 58, .a = -9.373, .b = 47.657, },
        },
        {
            .input = { .x = 10.121, .y = 7.537, .z = 2.753, },
            .output = { .l = 32.999, .a = 25.786, .b = 25.780, },
        },
        {
            .input = { .x = 67.402, .y = 64.066, .z = 5.168, },
            .output = { .l = 84, .a = 14.841, .b = 100, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(size_t i = 0; i < 4; i++) {
        colrcv_lab_t result;
        colrcv_xyz_to_lab(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.l, colours[i].output.l) &&
            almost_equal(result.a, colours[i].output.a) &&
            almost_equal(result.b, colours[i].output.b)
        );
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.l, colours[i].output.a, colours[i].output.b,
                result.l, result.a, result.b
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
    colrcv_add_test_case(test_colrcv_xyz_x_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_xyz_x_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_xyz_y_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_xyz_y_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_xyz_z_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_xyz_z_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_xyz_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_xyz_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_xyz_to_rgb, &suite);
    colrcv_add_test_case(test_colrcv_xyz_to_lab, &suite);
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
