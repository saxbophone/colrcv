# This source file forms part of colrcv
#
# colrcv is a C Library for converting Colours between different Colour Models.
#
# This is the CMake build file for colrcv.
# It requires CMake v3.0 or greater.
#
#
#
# Copyright (C) 2017, Joshua Saxby joshua.a.saxby+TNOPLuc8vM==@gmail.com
#
# The Copyright holder reserves all rights of this work.
#
# No copying or reproduction is permitted without the express, written consent
# of the Copyright holder.

# begin basic metadata
cmake_minimum_required(VERSION 3.0)

set(CMAKE_INSTALL_PREFIX "/home/joshua/Dev_Build/osxcross/target/SDK/MacOSX10.11.sdk/usr")

set(CMAKE_SYSTEM_NAME Darwin)
set(TOOLCHAIN_PREFIX x86_64-apple-darwin15)

# cross compilers to use for C and C++
set(CMAKE_C_COMPILER ${TOOLCHAIN_PREFIX}-clang)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-clang++)

# target environment on the build host system
#   set 1st to dir with the cross compiler's C/C++ headers/libs
set(CMAKE_FIND_ROOT_PATH "/home/joshua/Dev_Build/osxcross/target/SDK/MacOSX10.11.sdk/usr/include/")

# modify default behavior of FIND_XXX() commands to
# search for headers/libs in the target environment and
# search for programs in the build host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)

set(CMAKE_FIND_ROOT_PATH "/home/joshua/Dev_Build/osxcross/target/macports/pkgs/opt/local/")

set(CMAKE_OSX_SYSROOT "/home/joshua/Dev_Build/osxcross/target/SDK/MacOSX10.11.sdk/")

set(CMAKE_INSTALL_FRAMEWORK_PREFIX "/home/joshua/Dev_Build/osxcross/target/SDK/MacOSX10.11.sdk/System/Library/Frameworks")

set(SFML_OS_MACOSX BOOL TRUE)

set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG "-Wl,-rpath,")
set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG_SEP ":")

set(CMAKE_INSTALL_NAME_DIR "@rpath")
set(CMAKE_INSTALL_RPATH ...)


project(colrcv VERSION 0.1.0 LANGUAGES C)

# set default C standard to use (C99) if not already set
if(NOT DEFINED COLRCV_C_STANDARD)
    set(COLRCV_C_STANDARD "99")
endif()
# if env variable COLRCV_C_STANDARD is set and valid, override version
if(DEFINED ENV{COLRCV_C_STANDARD})
    # not a very robust regex but ok for most purposes
    if("$ENV{COLRCV_C_STANDARD}" MATCHES "(99|11)")
        set(COLRCV_C_STANDARD "$ENV{COLRCV_C_STANDARD}")
    endif()
endif()
message(STATUS "[colrcv] C Standard set to C${COLRCV_C_STANDARD}")
set(CMAKE_C_STANDARD ${COLRCV_C_STANDARD})
set(CMAKE_C_STANDARD_REQUIRED ON)

set(
    COLRCV_VERSION_STRING
    "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
)
set(COLRCV_ESCAPED_VERSION_STRING "\"${COLRCV_VERSION_STRING}\"")
# end basic metadata

# pass in version of library as preprocessor definitions
add_definitions(-DCOLRCV_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
add_definitions(-DCOLRCV_VERSION_MINOR=${PROJECT_VERSION_MINOR})
add_definitions(-DCOLRCV_VERSION_PATCH=${PROJECT_VERSION_PATCH})
add_definitions(-DCOLRCV_VERSION_STRING=${COLRCV_ESCAPED_VERSION_STRING})

# used for enabling additional compiler options if supported
include(CheckCCompilerFlag)

function(enable_c_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_C_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_c_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
    endif()
endfunction()

# enable extra flags (warnings) if we're not in release mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug" OR CMAKE_BUILD_TYPE STREQUAL "")
    message(STATUS "[colrcv] Warnings Enabled")
    # enable all warnings about 'questionable constructs'
    enable_c_compiler_flag_if_supported("-Wall")
    # issue 'pedantic' warnings for strict ISO compliance
    enable_c_compiler_flag_if_supported("-pedantic")
    # enable 'extra' strict warnings
    enable_c_compiler_flag_if_supported("-Wextra")
    # enable warnings on missing prototypes of global functions
    enable_c_compiler_flag_if_supported("-Wmissing-prototypes")
    # convert all warnings into errors
    enable_c_compiler_flag_if_supported("-Werror")
endif()

# C source files
file(GLOB COLRCV_SOURCES "colrcv/*.c" "colrcv/models/*.c")
# Header files
file(GLOB COLRCV_HEADERS "colrcv/*.h")
# Header files for models subdirectory
file(GLOB COLRCV_MODELS_HEADERS "colrcv/models/*.h")

# Test Suite Harness Source Files
file(GLOB UNIT_TEST_HARNESS_SOURCES "unit_test_harness/*.c")
# Test Suite Harness Header Files
file(GLOB UNIT_TEST_HARNESS_HEADERS "unit_test_harness/*.h")

# Unit test C Source files
file(GLOB TEST_COLRCV_SOURCES "tests/*.c")

add_library(colrcv ${COLRCV_SOURCES})
# set up version for library objects
set_target_properties(
    colrcv PROPERTIES VERSION ${COLRCV_VERSION_STRING}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# link libcolrcv with C math library
target_link_libraries(colrcv m)

# test harness library
add_library(unit_test_harness ${UNIT_TEST_HARNESS_SOURCES})

enable_testing()
# unit test executables
foreach(test_source_file ${TEST_COLRCV_SOURCES})
    # remove '.c' extension and parent directories
    get_filename_component(test_name ${test_source_file} NAME_WE)
    # append "test_" to test_name
    set(test_name "test_${test_name}")
    # create executable for test
    add_executable(${test_name} ${test_source_file})
    # link test with library and test harness library
    target_link_libraries(${test_name} colrcv unit_test_harness)
    # add test
    add_test(${test_name} ${test_name})
endforeach()

install(
    TARGETS colrcv
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# The "rough" install location is pinned to the current major version
# The "precise" install location is pinned to the current major and minor versions

# Generate rough (nearest major) version-dependent header installation folder
set(COLRCV_ROUGH_HEADER_DESTINATION "colrcv-${PROJECT_VERSION_MAJOR}")
# Generate precise (major and minor) version-dependent header installation folder
set(
    COLRCV_PRECISE_HEADER_DESTINATION
    "colrcv-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
)

# Install library header files, both to rough and precise install locations
install(
    FILES ${COLRCV_HEADERS}
    DESTINATION "include/${COLRCV_ROUGH_HEADER_DESTINATION}"
)
install(
    FILES ${COLRCV_MODELS_HEADERS}
    DESTINATION "include/${COLRCV_ROUGH_HEADER_DESTINATION}/models"
)

install(
    FILES ${COLRCV_HEADERS}
    DESTINATION "include/${COLRCV_PRECISE_HEADER_DESTINATION}"
)
install(
    FILES ${COLRCV_MODELS_HEADERS}
    DESTINATION "include/${COLRCV_PRECISE_HEADER_DESTINATION}/models"
)
