/**
 ***********************************************************************************************************************
 * @file        googletest.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef TEST_UTILS_GOOGLETEST_HPP
#define TEST_UTILS_GOOGLETEST_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>

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
