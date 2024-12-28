/**
 ***********************************************************************************************************************
 * @file        googletest.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        28-12-2024 15:28:40 (UTC)
 * @version     0.0.1
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
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
