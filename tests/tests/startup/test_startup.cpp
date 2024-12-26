/**
 ***********************************************************************************************************************
 * @file        test_startup.cpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#include "test_utils/test_utils.hpp"

// NOLINTBEGIN(cppcoreguidelines-owning-memory)

/**
 * @brief Namespace for the tests of 'startup' component.
 */
namespace Tests::Example
{

/**
 * @brief Test suite, instantiated for every test.
 */
class StartupTestFixture : public testing::Test
{
protected:
    /**
     * @brief Setup function, called after the constructor in every test.
     */
    void SetUp() override { }

    /**
     * @brief Teardown function, called before the destructor in every test.
     */
    void TearDown() override { }
};

/**
 * @brief Runs an example test.
 */
TEST_F(StartupTestFixture, First)
{
    ASSERT_TRUE(true);
}

}

// NOLINTEND(cppcoreguidelines-owning-memory)

/**
 * @brief Test runner for this suite of tests.
 * @return The result of the test runner.
 */
int main(int argc, char ** argv)
{
    // Initialize GoogleTest and GoogleMock.
    Tests::Utils::GoogleTest::init(argc, argv);

    // Execute the test runner.
    return RUN_ALL_TESTS();
}

/******************************************************************************************************END OF FILE*****/
