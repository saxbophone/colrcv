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
#include <inttypes.h>

#include "../unit_test_harness/harness.h"
#include "support.h"

#include "../colrcv/models/hsl.h"
#include "../colrcv/models/rgb.h"
#include "../colrcv/models/hsv.h"
#include "../colrcv/models/lab.h"
#include "../colrcv/models/xyz.h"


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
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_rgb_t result;
        colrcv_hsl_to_rgb(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.r, colours[i].output.r) &&
            almost_equal(result.g, colours[i].output.g) &&
            almost_equal(result.b, colours[i].output.b)
        );
        bool is_valid = colrcv_rgb_is_valid(result);
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.r, colours[i].output.g, colours[i].output.b,
                result.r, result.g, result.b
            );
        }
        if(!is_valid) {
            // also log error if output values are out of range
            printf("Output RGB values out of range\n");
        }
        // OR to success flag
        success = success && conversion_ok && is_valid;
    }

    test.result = success ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;
    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * HSL and output HSV colours
 */
struct hsl_to_hsv_pair_t {
    colrcv_hsl_t input;
    colrcv_hsv_t output;
};

/*
 * Test the function colrcv_hsl_to_hsv
 * Function should return a correctly calculated HSV colour for the given HSL
 * colour
 */
static colrcv_test_result_t test_colrcv_hsl_to_hsv(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsl_to_hsv_pair_t colours[4] = {
        {
            .input = { .h = 108, .s = 86, .l = 86, },
            .output = { .h = 108, .s = 24.561, .v = 98.04, },
        },
        {
            .input = { .h = 8, .s = 91, .l = 85, },
            .output = { .h = 8, .s = 27.673, .v = 98.65, },
        },
        {
            .input = { .h = 0, .s = 0, .l = 13, },
            .output = { .h = 0, .s = 0, .v = 13, },
        },
        {
            .input = { .h = 20, .s = 75, .l = 100, },
            .output = { .h = 0, .s = 0, .v = 100, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_hsv_t result;
        colrcv_hsl_to_hsv(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.h, colours[i].output.h) &&
            almost_equal(result.s, colours[i].output.s) &&
            almost_equal(result.v, colours[i].output.v)
        );
        bool is_valid = colrcv_hsv_is_valid(result);
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.h, colours[i].output.s, colours[i].output.v,
                result.h, result.s, result.v
            );
        }
        if(!is_valid) {
            // also log error if output values are out of range
            printf("Output HSV values out of range\n");
        }
        // OR to success flag
        success = success && conversion_ok && is_valid;
    }

    test.result = success ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;
    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * HSL and output LAB colours
 */
struct hsl_to_lab_pair_t {
    colrcv_hsl_t input;
    colrcv_lab_t output;
};

/*
 * Test the function colrcv_hsl_to_lab
 * Function should return a correctly calculated LAB colour for the given HSL
 * colour
 */
static colrcv_test_result_t test_colrcv_hsl_to_lab(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsl_to_lab_pair_t colours[4] = {
        {
            .input = { .h = 108, .s = 86, .l = 86, },
            .output = { .l = 93.636, .a = -26.738, .b = 24.46, },
        },
        {
            .input = { .h = 8, .s = 91, .l = 85, },
            .output = { .l = 82.565, .a = 20.364, .b = 13.08, },
        },
        {
            .input = { .h = 0, .s = 0, .l = 13, },
            .output = { .l = 12.813, .a = 0.001, .b = -0.002, },
        },
        {
            .input = { .h = 20, .s = 75, .l = 100, },
            .output = { .l = 100, .a = 0.005, .b = -0.0104, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_lab_t result;
        colrcv_hsl_to_lab(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.l, colours[i].output.l) &&
            almost_equal(result.a, colours[i].output.a) &&
            almost_equal(result.b, colours[i].output.b)
        );
        bool is_valid = colrcv_lab_is_valid(result);
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.l, colours[i].output.a, colours[i].output.b,
                result.l, result.a, result.b
            );
        }
        if(!is_valid) {
            // also log error if output values are out of range
            printf("Output LAB values out of range\n");
        }
        // OR to success flag
        success = success && conversion_ok && is_valid;
    }

    test.result = success ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;
    return test;
}

/*
 * An internal struct type used only in this test for storing pairs of input
 * HSL and output XYZ colours
 */
struct hsl_to_xyz_pair_t {
    colrcv_hsl_t input;
    colrcv_xyz_t output;
};

/*
 * Test the function colrcv_hsl_to_xyz
 * Function should return a correctly calculated XYZ colour for the given HSL
 * colour
 */
static colrcv_test_result_t test_colrcv_hsl_to_xyz(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsl_to_xyz_pair_t colours[4] = {
        {
            .input = { .h = 108, .s = 86, .l = 86, },
            .output = { .x = 67.382, .y = 84.429, .z = 60.66, },
        },
        {
            .input = { .h = 8, .s = 91, .l = 85, },
            .output = { .x = 67.102, .y = 61.347, .z = 52.529, },
        },
        {
            .input = { .h = 0, .s = 0, .l = 13, },
            .output = { .x = 1.456, .y = 1.532, .z = 1.668, },
        },
        {
            .input = { .h = 20, .s = 75, .l = 100, },
            .output = { .x = 95.05, .y = 100, .z = 108.9, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_xyz_t result;
        colrcv_hsl_to_xyz(colours[i].input, &result);
        bool conversion_ok = (
            almost_equal(result.x, colours[i].output.x) &&
            almost_equal(result.y, colours[i].output.y) &&
            almost_equal(result.z, colours[i].output.z)
        );
        bool is_valid = colrcv_xyz_is_valid(result);
        // print out result and expected output if not equal
        if(!conversion_ok) {
            printf(
                "Colour #%" PRIu8 ":\nExpected:\t(%f, %f, %f)\nGot:\t\t(%f, %f, %f)\n",
                i,
                colours[i].output.x, colours[i].output.y, colours[i].output.z,
                result.x, result.y, result.z
            );
        }
        if(!is_valid) {
            // also log error if output values are out of range
            printf("Output XYZ values out of range\n");
        }
        // OR to success flag
        success = success && conversion_ok && is_valid;
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
    colrcv_add_test_case(test_colrcv_hsl_to_hsv, &suite);
    colrcv_add_test_case(test_colrcv_hsl_to_lab, &suite);
    colrcv_add_test_case(test_colrcv_hsl_to_xyz, &suite);
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
