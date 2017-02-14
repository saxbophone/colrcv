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

#include "../unit_test_harness/harness.h"
#include "../colrcv/models/lab.h"


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
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
