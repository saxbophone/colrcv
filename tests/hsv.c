/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
 * 
 * This unit tests the HSV colour model unit (models/hsv.h)
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

#include "../colrcv/models/hsv.h"
#include "../colrcv/models/rgb.h"
#include "../colrcv/models/hsl.h"
#include "../colrcv/models/lab.h"
#include "../colrcv/models/xyz.h"


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
 * Test the function colrcv_hsv_clamp
 * Function should return an identical colrcv_hsv_t struct to the one passed to
 * it when the channels of the struct are all within their valid ranges
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all chanels to average of minimum and maximum bounds
    colrcv_hsv_t input = {
        .h = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_H_MAX_VALUE) / 2.0,
        .s = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_S_MAX_VALUE) / 2.0,
        .v = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_V_MAX_VALUE) / 2.0,
    };
    // should be valid (this is an assertion because if not it's a test error)
    assert(colrcv_hsv_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp(input);

    // output should be equal to input
    test.result = (
        (output.h == input.h) && (output.s == input.s) && (output.v == input.v)
    ) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL;

    return test;
}

/*
 * Test the function colrcv_hsv_clamp
 * Function should return a clamped colrcv_hsv_t struct when the one passed to
 * it has channels which are outside their valid ranges
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set each channel to be higher or lower than its maximum or minimum value
    colrcv_hsv_t input = {
        .h = COLRCV_HSV_MIN_VALUE - 100,
        .s = COLRCV_HSV_S_MAX_VALUE + 55.57,
        .v = COLRCV_HSV_MIN_VALUE - 99.9,
    };
    // should be invalid
    assert(!colrcv_hsv_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp(input);

    // output should not be equal to input
    bool not_equal = (
        (output.h != input.h) && (output.s != input.s) && (output.v != input.v)
    );
    // output should be valid according to the validity-checking function
    bool is_valid = colrcv_hsv_is_valid(output);

    test.result = (
        (not_equal && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_hsv_clamp_h
 * Function should return an identical colrcv_hsv_t struct to the one passed to
 * it when the hue channel of the struct is within the valid range for hue
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_h_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set hue chanel to average of minimum and maximum bounds
    // set other channels to extreme values, bound to be invalid
    colrcv_hsv_t input = {
        .h = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_H_MAX_VALUE) / 2.0,
        .s = -INFINITY,
        .v = INFINITY,
    };
    // hue should be valid
    assert(colrcv_hsv_h_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp_h(input);

    // output hue channel should be equal to input
    test.result = (
        (output.h == input.h) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_hsv_clamp_h
 * Function should return a colrcv_hsv_t struct with a clamped hue channel when
 * given a struct with an invalid hue channel
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_h_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all channels to extreme values
    colrcv_hsv_t input = { .h = INFINITY, .s = -INFINITY, .v = INFINITY, };
    // hue should be invalid
    assert(!colrcv_hsv_h_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp_h(input);

    // output hue channel should not be equal to input
    // both other channels should remain unchanged
    bool hue_changed = (
        (output.h != input.h) && (output.s == input.s) && (output.v == input.v)
    );
    // output hue should be valid according to the validity-checking function
    bool is_valid = colrcv_hsv_h_is_valid(output);
    test.result = (
        (hue_changed && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_hsv_clamp_s
 * Function should return an identical colrcv_hsv_t struct to the one passed to
 * it when the saturation channel of the struct is within the valid range for
 * saturation
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_s_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set saturation chanel to average of minimum and maximum bounds
    // set other channels to extreme values, bound to be invalid
    colrcv_hsv_t input = {
        .h = -INFINITY,
        .s = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_S_MAX_VALUE) / 2.0,
        .v = INFINITY,
    };
    // saturation should be valid
    assert(colrcv_hsv_s_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp_s(input);

    // output saturation channel should be equal to input
    test.result = (
        (output.s == input.s) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_hsv_clamp_s
 * Function should return a colrcv_hsv_t struct with a clamped saturation
 * channel when given a struct with an invalid saturation channel
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_s_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all channels to extreme values
    colrcv_hsv_t input = { .h = INFINITY, .s = -INFINITY, .v = INFINITY, };
    // saturation should be invalid
    assert(!colrcv_hsv_s_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp_s(input);

    // output saturation channel should not be equal to input
    // both other channels should remain unchanged
    bool sat_changed = (
        (output.h == input.h) && (output.s != input.s) && (output.v == input.v)
    );
    /*
     * output saturation should be valid according to the validity-checking
     * function
     */
    bool is_valid = colrcv_hsv_s_is_valid(output);
    test.result = (
        (sat_changed && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_hsv_clamp_v
 * Function should return an identical colrcv_hsv_t struct to the one passed to
 * it when the value channel of the struct is within the valid range for
 * value
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_v_within_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set value chanel to average of minimum and maximum bounds
    // set other channels to extreme values, bound to be invalid
    colrcv_hsv_t input = {
        .h = -INFINITY,
        .s = INFINITY,
        .v = (COLRCV_HSV_MIN_VALUE + COLRCV_HSV_V_MAX_VALUE) / 2.0,
    };
    // value should be valid
    assert(colrcv_hsv_v_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp_v(input);

    // output value channel should be equal to input
    test.result = (
        (output.v == input.v) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

    return test;
}

/*
 * Test the function colrcv_hsv_clamp_v
 * Function should return a colrcv_hsv_t struct with a clamped value
 * channel when given a struct with an invalid value channel
 */
static colrcv_test_result_t test_colrcv_hsv_clamp_v_outside_range(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set all channels to extreme values
    colrcv_hsv_t input = { .h = INFINITY, .s = -INFINITY, .v = INFINITY, };
    // value should be invalid
    assert(!colrcv_hsv_v_is_valid(input));

    colrcv_hsv_t output = colrcv_hsv_clamp_v(input);

    // output value channel should not be equal to input
    // both other channels should remain unchanged
    bool value_changed = (
        (output.h == input.h) && (output.s == input.s) && (output.v != input.v)
    );
    /*
     * output value should be valid according to the validity-checking
     * function
     */
    bool is_valid = colrcv_hsv_v_is_valid(output);
    test.result = (
        (value_changed && is_valid) ? COLRCV_TEST_SUCCESS : COLRCV_TEST_FAIL
    );

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
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_rgb_t result = colrcv_hsv_to_rgb(colours[i].input);
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
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_hsl_t result = colrcv_hsv_to_hsl(colours[i].input);
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
 * HSV and output LAB colours
 */
struct hsv_to_lab_pair_t {
    colrcv_hsv_t input;
    colrcv_lab_t output;
};

/*
 * Test the function colrcv_hsv_to_lab
 * Function should return a correctly calculated LAB colour for the given HSV
 * colour
 */
static colrcv_test_result_t test_colrcv_hsv_to_lab(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsv_to_lab_pair_t colours[4] = {
        {
            .input = { .h = 281, .s = 100, .v = 26, },
            .output = { .l = 8.668, .a = 33.702, .b = -30.384, },
        },
        {
            .input = { .h = 62, .s = 54, .v = 47, },
            .output = { .l = 48.889, .a = -10.574, .b = 34.816, },
        },
        {
            .input = { .h = 53, .s = 78, .v = 88, },
            .output = { .l = 81.463, .a = -8.517, .b = 73.225, },
        },
        {
            .input = { .h = 189, .s = 87, .v = 35, },
            .output = { .l = 29.895, .a = -14.874, .b = -12.459, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_lab_t result = colrcv_hsv_to_lab(colours[i].input);
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

/*
 * An internal struct type used only in this test for storing pairs of input
 * HSV and output XYZ colours
 */
struct hsv_to_xyz_pair_t {
    colrcv_hsv_t input;
    colrcv_xyz_t output;
};

/*
 * Test the function colrcv_hsv_to_xyz
 * Function should return a correctly calculated XYZ colour for the given HSV
 * colour
 */
static colrcv_test_result_t test_colrcv_hsv_to_xyz(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;
    // setup test data - we want 4 sample colours to test
    struct hsv_to_xyz_pair_t colours[4] = {
        {
            .input = { .h = 281, .s = 100, .v = 26, },
            .output = { .x = 2.088, .y = 0.962, .z = 5.276, },
        },
        {
            .input = { .h = 62, .s = 54, .v = 47, },
            .output = { .x = 14.821, .y = 17.504, .z = 6.229, },
        },
        {
            .input = { .h = 53, .s = 78, .v = 88, },
            .output = { .x = 53.015, .y = 59.312, .z = 11.601, },
        },
        {
            .input = { .h = 189, .s = 87, .v = 35, },
            .output = { .x = 4.656, .y = 6.193, .z = 10.457, },
        },
    };
    // flag to keep track of result
    bool success = true;

    // convert each colour and compare with output
    for(uint8_t i = 0; i < 4; i++) {
        colrcv_xyz_t result = colrcv_hsv_to_xyz(colours[i].input);
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
    colrcv_add_test_case(test_colrcv_hsv_h_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_h_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_s_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_s_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_v_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_v_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_is_valid_true, &suite);
    colrcv_add_test_case(test_colrcv_hsv_is_valid_false, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_within_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_h_within_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_h_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_s_within_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_s_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_v_within_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_clamp_v_outside_range, &suite);
    colrcv_add_test_case(test_colrcv_hsv_to_rgb, &suite);
    colrcv_add_test_case(test_colrcv_hsv_to_hsl, &suite);
    colrcv_add_test_case(test_colrcv_hsv_to_lab, &suite);
    colrcv_add_test_case(test_colrcv_hsv_to_xyz, &suite);
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
