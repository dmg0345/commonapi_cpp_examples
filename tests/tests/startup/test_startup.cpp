/**
 ***********************************************************************************************************************
 * @file        test_startup.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        28-12-2024 15:28:40 (UTC)
 * @version     0.0.1
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
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
