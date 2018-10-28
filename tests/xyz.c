/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the XYZ colour model unit (models/xyz.h)
 *
 * Copyright (C) 2017, 2018, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../unit_test_harness/harness.h"
#include "support.h"

#include "../colrcv/models/xyz.h"
#include "../colrcv/models/rgb.h"
#include "../colrcv/models/hsv.h"
#include "../colrcv/models/hsl.h"
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
 * Test the function colrcv_xyz_clamp
 * Function should return an identical colrcv_xyz_t struct to the one passed to
 * it when the channels of the struct are all within their valid ranges
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all chanels to average of minimum and maximum bounds
    colrcv_xyz_t input = {
        .x = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_X_MAX_VALUE) / 2.0,
        .y = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Y_MAX_VALUE) / 2.0,
        .z = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Z_MAX_VALUE) / 2.0,
    };
    // should be valid (this is an assertion because if not it's a test error)
    assert(colrcv_xyz_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp(input);

    // output should be equal to input
    test.result = (
        (output.x == input.x) && (output.y == input.y) && (output.z == input.z)
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_xyz_clamp
 * Function should return a clamped colrcv_xyz_t struct when the one passed to
 * it has channels which are outside their valid ranges
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set each channel to be higher or lower than its maximum or minimum value
    colrcv_xyz_t input = {
        .x = COLRCV_XYZ_MIN_VALUE - 100,
        .y = COLRCV_XYZ_Y_MAX_VALUE + 55.57,
        .z = COLRCV_XYZ_MIN_VALUE - 99.9,
    };
    // should be invalid
    assert(!colrcv_xyz_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp(input);

    // output should not be equal to input
    bool not_equal = (
        (output.x != input.x) && (output.y != input.y) && (output.z != input.z)
    );
    // output should be valid according to the validity-checking function
    bool is_valid = colrcv_xyz_is_valid(output);

    test.result = (
        (not_equal && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_xyz_clamp_x
 * Function should return an identical colrcv_xyz_t struct to the one passed to
 * it when the x channel of the struct is within the valid range for x
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_x_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set x chanel to average of minimum and maximum bounds
    // set other channels to extreme values, bound to be invalid
    colrcv_xyz_t input = {
        .x = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_X_MAX_VALUE) / 2.0,
        .y = -INFINITY,
        .z = INFINITY,
    };
    // x should be valid
    assert(colrcv_xyz_x_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp_x(input);

    // output x channel should be equal to input
    test.result = (
        (output.x == input.x) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_xyz_clamp_x
 * Function should return a colrcv_xyz_t struct with a clamped x channel when
 * given a struct with an invalid x channel
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_x_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all channels to extreme values
    colrcv_xyz_t input = { .x = INFINITY, .y = -INFINITY, .z = INFINITY, };
    // x should be invalid
    assert(!colrcv_xyz_x_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp_x(input);

    // output x channel should not be equal to input
    // both other channels should remain unchanged
    bool x_changed = (
        (output.x != input.x) && (output.y == input.y) && (output.z == input.z)
    );
    // output x should be valid according to the validity-checking function
    bool is_valid = colrcv_xyz_x_is_valid(output);
    test.result = (
        (x_changed && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_xyz_clamp_y
 * Function should return an identical colrcv_xyz_t struct to the one passed to
 * it when the y channel of the struct is within the valid range for y
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_y_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set y chanel to average of minimum and maximum bounds
    // set other channels to extreme values, bound to be invalid
    colrcv_xyz_t input = {
        .x = -INFINITY,
        .y = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Y_MAX_VALUE) / 2.0,
        .z = INFINITY,
    };
    // y should be valid
    assert(colrcv_xyz_y_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp_y(input);

    // output y channel should be equal to input
    test.result = (
        (output.y == input.y) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_xyz_clamp_y
 * Function should return a colrcv_xyz_t struct with a clamped y channel when
 * given a struct with an invalid y channel
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_y_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all channels to extreme values
    colrcv_xyz_t input = { .x = INFINITY, .y = -INFINITY, .z = INFINITY, };
    // y should be invalid
    assert(!colrcv_xyz_y_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp_y(input);

    // output y channel should not be equal to input
    // both other channels should remain unchanged
    bool y_changed = (
        (output.x == input.x) && (output.y != input.y) && (output.z == input.z)
    );
    /*
     * output y should be valid according to the validity-checking
     * function
     */
    bool is_valid = colrcv_xyz_y_is_valid(output);
    test.result = (
        (y_changed && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_xyz_clamp_z
 * Function should return an identical colrcv_xyz_t struct to the one passed to
 * it when the z channel of the struct is within the valid range for z
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_z_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set z chanel to average of minimum and maximum bounds
    // set other channels to extreme values, bound to be invalid
    colrcv_xyz_t input = {
        .x = -INFINITY,
        .y = INFINITY,
        .z = (COLRCV_XYZ_MIN_VALUE + COLRCV_XYZ_Z_MAX_VALUE) / 2.0,
    };
    // z should be valid
    assert(colrcv_xyz_z_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp_z(input);

    // output z channel should be equal to input
    test.result = (
        (output.z == input.z) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_xyz_clamp_z
 * Function should return a colrcv_xyz_t struct with a clamped z channel when
 * given a struct with an invalid z channel
 */
static colrcv_test_result_t test_colrcv_xyz_clamp_z_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all channels to extreme values
    colrcv_xyz_t input = { .x = INFINITY, .y = -INFINITY, .z = INFINITY, };
    // z should be invalid
    assert(!colrcv_xyz_z_is_valid(input));

    colrcv_xyz_t output = colrcv_xyz_clamp_z(input);

    // output z channel should not be equal to input
    // both other channels should remain unchanged
    bool z_changed = (
        (output.x == input.x) && (output.y == input.y) && (output.z != input.z)
    );
    /*
     * output z should be valid according to the validity-checking
     * function
     */
    bool is_valid = colrcv_xyz_z_is_valid(output);
    test.result = (
        (z_changed && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

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
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_rgb_t result = colrcv_xyz_to_rgb(colours[i].input);
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
 * XYZ and output HSV colours
 */
struct xyz_to_hsv_pair_t {
    colrcv_xyz_t input;
    colrcv_hsv_t output;
};

/*
 * Test the function colrcv_xyz_to_hsv
 * Function should return a correctly calculated HSV colour for the given XYZ
 * colour
 */
static colrcv_test_result_t test_colrcv_xyz_to_hsv(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct xyz_to_hsv_pair_t colours[4] = {
        {
            .input = { .x = 100, .y = 100, .z = 100, },
            .output = { .h = 26.502, .s = 4.125, .v = 100, },
        },
        {
            .input = { .x = 45, .y = 26, .z = 3, },
            .output = { .h = 13.066, .s = 95.226, .v = 100, },
        },
        {
            .input = { .x = 47, .y = 52, .z = 83, },
            .output = { .h = 205.895, .s = 34.529, .v = 90.503, },
        },
        {
            .input = { .x = 13, .y = 19, .z = 0, },
            .output = { .h = 74.219, .s = 100, .v = 51.734, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_hsv_t result = colrcv_xyz_to_hsv(colours[i].input);
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
 * XYZ and output HSL colours
 */
struct xyz_to_hsl_pair_t {
    colrcv_xyz_t input;
    colrcv_hsl_t output;
};

/*
 * Test the function colrcv_xyz_to_hsl
 * Function should return a correctly calculated HSL colour for the given XYZ
 * colour
 */
static colrcv_test_result_t test_colrcv_xyz_to_hsl(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct xyz_to_hsl_pair_t colours[4] = {
        {
            .input = { .x = 100, .y = 100, .z = 100, },
            .output = { .h = 26.502, .s = 100, .l = 97.937, },
        },
        {
            .input = { .x = 45, .y = 26, .z = 3, },
            .output = { .h = 13.066, .s = 100, .l = 52.386, },
        },
        {
            .input = { .x = 47, .y = 52, .z = 83, },
            .output = { .h = 205.895, .s = 62.197, .l = 74.878, },
        },
        {
            .input = { .x = 13, .y = 19, .z = 0, },
            .output = { .h = 74.219, .s = 100, .l = 25.867, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_hsl_t result = colrcv_xyz_to_hsl(colours[i].input);
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
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_lab_t result = colrcv_xyz_to_lab(colours[i].input);
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
    colrcv_add_test_case(test_colrcv_xyz_clamp_within_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_x_within_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_x_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_y_within_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_y_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_z_within_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_clamp_z_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_xyz_to_rgb, &suite);
    colrcv_add_test_case(test_colrcv_xyz_to_hsv, &suite);
    colrcv_add_test_case(test_colrcv_xyz_to_hsl, &suite);
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
