/**
 ***********************************************************************************************************************
 * @file        test_lapp.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#include <thread>
#include <string>
#include <chrono>

#include "test_utils/test_utils.hpp"
#include "test_lapp.hpp"

#include "app/client/client.hpp"
#include "app/server/server.hpp"
#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppProxy.hpp>
#include <v0/commonapi/app/AppStubDefault.hpp>

using namespace App::Client;
using namespace App::Server;
using namespace Utils::Error;
using namespace v0::commonapi::app;

// NOLINTBEGIN(cppcoreguidelines-owning-memory)

namespace Tests::App
{

/**
 * @brief Test suite, instantiated for every test.
 */
class AppTestFixture : public testing::Test
{
protected:
    /**
     * @brief Setup function, called after the constructor in every test.
     */
    void SetUp() override
    {
        // Get Common API runtime.
        runtime = CommonAPI::Runtime::get();

        // Create server and register it.
        server = std::make_shared<AppStubImpl>();
        while (!runtime->registerService(server_domain, server_instance, server, server_connection))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        // Create client and make it available.
        client = runtime->buildProxy<AppProxy>(client_domain, client_instance, client_connection);
        while (!client->isAvailable())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    /**
     * @brief Teardown function, called before the destructor in every test.
     */
    void TearDown() override
    {
        // Unregister server.
        const auto & serverAddress = server->getStubAdapter()->getAddress();
        while (!runtime->unregisterService(serverAddress.getDomain(),
                                           serverAddress.getInterface(),
                                           serverAddress.getInstance()))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    std::shared_ptr<CommonAPI::Runtime> runtime; /**< Shared pointer to runtime. */
    std::shared_ptr<AppStubImpl> server; /**< Server stub implementation. */
    const std::string server_domain = "local"; /**< Server Common API C++ domain. */
    const std::string server_instance = "commonapi.app.App"; /**< Server Common API C++ instance. */
    const std::string server_connection = "server-sample"; /**< Server Common API C++ connection. */

    std::shared_ptr<AppProxy<>> client; /**< Client proxy implementation. */
    const std::string client_domain = "local"; /**< Client Common API C++ domain. */
    const std::string client_instance = "commonapi.app.App"; /**< Client Common API C++ instance. */
    const std::string client_connection = "client-sample"; /**< Client Common API C++ connection. */
};

/**
 * @brief TODO: Run an example test.
 */
TEST_F(AppTestFixture, First)
{
    ASSERT_EQ(::Error::OK, ::Error::OK);
}

/**
 * @brief TODO: Run an example test.
 */
TEST_F(AppTestFixture, Second)
{
    ASSERT_EQ(::Error::OK, ::Error::OK);
}

/**
 * @brief TODO: Run an example test.
 */
TEST_F(AppTestFixture, Third)
{
    ASSERT_EQ(::Error::OK, ::Error::OK);
}

/**
 * @brief TODO: Run an example test.
 */
TEST_F(AppTestFixture, Fourth)
{
    ASSERT_EQ(::Error::OK, ::Error::OK);
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
