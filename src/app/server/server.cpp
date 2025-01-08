/**
 ***********************************************************************************************************************
 * @file        server.cpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#include "app/server/server.hpp"

#include <thread>
#include <chrono>

#include "utils/capi/capi.hpp"
#include "utils/error/error.hpp"

namespace Server = App::Server;
namespace Capi = Utils::Capi;
namespace Error = Utils::Error;

Server::AppService::AppService(const std::string & domain,
                               const std::string & instance,
                               const std::string & connection) :
    Capi::AppServiceBase(domain, instance, connection)
{ }

Server::AppService::~AppService(void) { }

void Server::AppService::ping(const std::shared_ptr<CommonAPI::ClientId> client, std::string request, pingReply_t reply)
{
    (void)client;
    reply(request);
}

Error::ID Server::main(void)
{
    auto error = Error::ID::UNKNOWN;

    // Create application service.
    auto app_service = Server::AppService::make<Server::AppService>("local", "commonapi.app.App", "server-sample");

    // Create client with all clients.
    auto server = Capi::Server<AppService>(app_service);

    // Start all clients.
    END_ON_ERROR(server.start());

    // Send messages every second until stopped.
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // Stop all clients.
    END_ON_ERROR(server.stop());

    // All good.
    error = Error::ID::OK;

end:

    return error;
}

/******************************************************************************************************END OF FILE*****/
