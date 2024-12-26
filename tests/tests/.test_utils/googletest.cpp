/**
 ***********************************************************************************************************************
 * @file        googletest.cpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#include "test_utils/test_utils.hpp"

namespace Tests::Utils::GoogleTest
{

void init(int argc, char ** argv)
{
#if defined(GOOGLETEST_JUNIT_XML_OUTPUT)
    ::testing::GTEST_FLAG(output) = "xml:" GOOGLETEST_JUNIT_XML_OUTPUT;
#endif
    // Initialize GoogleTest.
    ::testing::InitGoogleTest(&argc, argv);
    // Initialize GoogleMock.
    ::testing::InitGoogleMock(&argc, argv);
}

}

/******************************************************************************************************END OF FILE*****/
