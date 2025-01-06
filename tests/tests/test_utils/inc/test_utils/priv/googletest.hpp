/**
 ***********************************************************************************************************************
 * @file        googletest.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        06-01-2025 03:13:42 (UTC)
 * @version     0.0.3
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef TEST_UTILS_GOOGLETEST_HPP
#define TEST_UTILS_GOOGLETEST_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

/**
 * @brief GoogleTest test utilities namespace.
 *
 * Utilities related to GoogleTest and GoogleMock for testing.
 */
namespace Tests::Utils::GoogleTest
{

/**
 * @brief Minimal initialization for GoogleTest and GoogleMock, must be called within @c main before running tests.
 * @param[in] argc The number of command line arguments.
 * @param[in] argv The command line arguments.
 */
void init(int argc, char ** argv);

}

#endif /* TEST_UTILS_GOOGLETEST_HPP */

/******************************************************************************************************END OF FILE*****/
