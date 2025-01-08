/**
 ***********************************************************************************************************************
 * @file        server.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LAPP_CSERVER_HPP
#define LAPP_CSERVER_HPP

#include "utils/capi/capi.hpp"
#include "utils/error/error.hpp"

/**
 * @rst
 * The *server* component implements the server concept of the Common API C++ client/server architecture, it supports
 * both D-Bus and SOME/IP runtime bindings.
 *
 * In this project, it implements a stub and a non-persistent storage to test the different functionalities of the
 * Common API C++ framework, refer to the :any:`application <::App>` for details of how it fits with the rest of the
 * architecture.
 * @endrst
 */
namespace App::Server
{

/** Implementation of the application service. */
class AppService : public Utils::Capi::AppServiceBase
{
    /** Delete copy constructor, move constructor, copy operator and move operator. @{ */
    AppService(void) = delete;
    AppService(const AppService &) = delete;
    AppService(AppService &&) = delete;
    AppService & operator=(const AppService &) = delete;
    AppService & operator=(AppService &&) = delete;
    /** @} */

public:
    /**
     * @brief Class constructor.
     * @param[in] domain Common API C++ domain for the application service.
     * @param[in] instance Common API C++ instance for the application service.
     * @param[in] connection Common API C++ connection for the application service.
     */
    AppService(const std::string & domain, const std::string & instance, const std::string & connection);

    /** Class Destructor. */
    ~AppService(void) override;

    /**
     * @brief Implementation of 'ping' in the server.
     * @param client An identifier for the client performing the request.
     * @param request The message for the request.
     * @param reply The function to use to reply back to the client.
     */
    void ping(const std::shared_ptr<CommonAPI::ClientId> client, std::string request, pingReply_t reply) override;
};

/**
 * @brief Main function for a server executable.
 * @return Identifier for the error.
 */
Utils::Error::ID main(void);

}

#endif /* LAPP_CSERVER_HPP */

/******************************************************************************************************END OF FILE*****/
