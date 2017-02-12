/*
 * This source file forms part of colrcv
 * colrcv is a C Library for converting Colours between different Colour Models.
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


#ifdef __cplusplus
extern "C"{
#endif

/*
 * Sample dummy test case to test my suite is configured properly.
 */
static colrcv_test_result_t test_dummy(void) {
    // initialise test result
    colrcv_test_result_t test = COLRCV_TEST;

    // set result to Success
    test.result = COLRCV_TEST_SUCCESS;

    return test;
}

int main() {
    // initialise test suite
    colrcv_test_suite_t suite = colrcv_init_test_suite();
    // add test cases
    colrcv_add_test_case(test_dummy, &suite);
    // run test suite
    colrcv_run_test_suite(&suite);
    // return test suite status
    return suite.result ? 0 : 1;
}

#ifdef __cplusplus
} // extern "C"
#endif
