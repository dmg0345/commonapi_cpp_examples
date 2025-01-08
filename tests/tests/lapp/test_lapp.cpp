/**
 ***********************************************************************************************************************
 * @file        test_lapp.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#include "test_lapp.hpp"

#include <thread>
#include <string>
#include <chrono>

#include "test_utils/test_utils.hpp"

#include "app/client/client.hpp"
#include "app/server/server.hpp"
#include "utils/capi/capi.hpp"
#include "utils/error/error.hpp"

namespace Client = App::Client;
namespace Server = App::Server;
namespace Capi = Utils::Capi;
namespace Error = Utils::Error;

#if defined(TEST_LAPP_MODE_DBUS)
#define AppTestFixture AppDBusTestFixture
#else
#define AppTestFixture AppSomeIPTestFixture
#endif

// NOLINTBEGIN(cppcoreguidelines-owning-memory,cppcoreguidelines-virtual-class-destructor)

/** Test suite, instantiated for every test. */

class AppTestFixture : public testing::Test
{
public:
    /** Delete copy constructor, move constructor, copy operator and move operator. @{ */
    AppTestFixture(const AppTestFixture &) = delete;
    AppTestFixture(AppTestFixture &&) = delete;
    AppTestFixture & operator=(const AppTestFixture &) = delete;
    AppTestFixture & operator=(AppTestFixture &&) = delete;
    /** @} */

protected:
    /** Text fixture constructor, called before setup function in every test. */
    AppTestFixture() : client(nullptr), server(nullptr) { }

    /** Test fixture destructor, called after teardown function in every test. */
    ~AppTestFixture() override { }

    /** Setup function, called after the constructor in every test. */
    void SetUp() override
    {
        // Create clients and services.
        auto app_service = Server::AppService::make<Server::AppService>("local", "commonapi.app.App", "server-sample");
        auto app_client = Client::AppClient::make<Client::AppClient>("local", "commonapi.app.App", "client-sample");

        // Create client and server.
        this->server = std::make_shared<Capi::Server<Server::AppService>>(app_service);
        this->client = std::make_shared<Capi::Client<Client::AppClient>>(app_client);

        // Start server, and afterwards the client.
        ASSERT_EQ(this->server->start(), Error::ID::OK);
        ASSERT_EQ(this->client->start(), Error::ID::OK);
    }

    /** Teardown function, called before the destructor in every test. */
    void TearDown() override
    {
        // Terminate client and afterwards the server.
        ASSERT_EQ(this->client->stop(), Error::ID::OK);
        ASSERT_EQ(this->server->stop(), Error::ID::OK);
    }

    std::shared_ptr<Capi::Client<Client::AppClient>> client; /**< Client. */
    std::shared_ptr<Capi::Server<Server::AppService>> server; /**< Server. */
};

/** Sends some data synchronously from the client to the server and evaluates the same data is received back. */
TEST_F(AppTestFixture, SyncPing)
{
    const std::string & request = "ping pong, ping pong...";
    std::string response;

    ASSERT_EQ(this->client->app->ping(request, response), Error::ID::OK);
    ASSERT_EQ(request, response);
}

// NOLINTEND(cppcoreguidelines-owning-memory,cppcoreguidelines-virtual-class-destructor)

#if !defined(DOXYGEN)
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
#endif

/******************************************************************************************************END OF FILE*****/
