/**
 ***********************************************************************************************************************
 * @file        client.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#include "app/client/client.hpp"

#include <thread>
#include <chrono>

#include "utils/capi/capi.hpp"
#include "utils/error/error.hpp"

namespace Client = App::Client;
namespace Capi = Utils::Capi;
namespace Error = Utils::Error;

Client::AppClient::AppClient(const std::string & domain, const std::string & instance, const std::string & connection) :
    Capi::AppClientBase(domain, instance, connection)
{ }

Client::AppClient::~AppClient(void) { }

Utils::Error::ID Client::AppClient::ping(const std::string & request, std::string & response)
{
    auto error = Error::ID::UNKNOWN;
    std::string response_msg;
    CommonAPI::CallStatus call_status = CommonAPI::CallStatus::SUCCESS;
    const CommonAPI::CallInfo call_info(1000, 1234); // TODO: Double check this values.

    // Perform synchronous call.
    this->proxy->ping(request, call_status, response_msg, &call_info);
    END_ON_TRUE_WITH_ERROR(call_status != CommonAPI::CallStatus::SUCCESS, Error::ID::CAPI_CLIENT);

    // All good.
    response = std::move(response_msg);
    error = Error::ID::OK;

end:

    return error;
}

Error::ID Client::main(void)
{
    auto error = Error::ID::UNKNOWN;
    std::string response;

    // Create application client.
    auto app_client = Client::AppClient::make<Client::AppClient>("local", "commonapi.app.App", "client-sample");

    // Create client manager with all clients.
    auto client = Capi::Client<Client::AppClient>(app_client);

    // Start all clients.
    END_ON_ERROR(client.start());

    // Send messages every second until stopped.
    while (true)
    {
        END_ON_ERROR(client.app->ping("Hello Server, I am the Client!", response));
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Stop all clients.
    END_ON_ERROR(client.stop());

    // All good.
    error = Error::ID::OK;

end:

    return error;
}

/******************************************************************************************************END OF FILE*****/
