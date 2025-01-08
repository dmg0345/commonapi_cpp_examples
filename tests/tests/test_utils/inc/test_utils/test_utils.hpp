/**
 ***********************************************************************************************************************
 * @file        test_utils.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include "priv/googletest.hpp"

/**
 * @rst
 * Root namespace with all the tests utilities and test suites for the project.
 *
 * For more information about the tests, refer to the *tests* folder in the repository.
 * @endrst
 */
namespace Tests
{ }

/**
 * @rst
 * Test utils not specific to a test or test suite and which can be used accross the different tests.
 *
 * For more information about the test utilities, refer to the *tests/test_utils* folder in the repository.
 * @endrst
 */
namespace Tests::Utils
{ }

/**
 * @rst
 * The tests are part of test suites, and test suites are all are part of this namespace.
 *
 * The implementation of the test suites can be found in the *tests/tests* folder in the repository.
 * @endrst
 */
namespace Tests::Suites
{ }

#endif /* TEST_UTILS_HPP */

/******************************************************************************************************END OF FILE*****/
