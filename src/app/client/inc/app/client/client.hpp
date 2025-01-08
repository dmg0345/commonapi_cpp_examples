/**
 ***********************************************************************************************************************
 * @file        client.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LAPP_CCLIENT_HPP
#define LAPP_CCLIENT_HPP

#include "utils/capi/capi.hpp"
#include "utils/error/error.hpp"

/**
 * @rst
 * The *client* component implements the client concept of the Common API C++ client/server architecture, it supports
 * both D-Bus and SOME/IP runtime bindings.
 *
 * In this project, it implements request methods and non-persistent storage to test the different functionalities of
 * the Common API C++ framework, refer to the :any:`application <::App>` for details of how it fits with the rest of the
 * architecture.
 * @endrst
 */
namespace App::Client
{

/** Implementation of an application client. */
class AppClient : public Utils::Capi::AppClientBase
{
    /** Delete default constructor copy constructor, move constructor, copy operator and move operator. @{ */
    AppClient(void) = delete;
    AppClient(const AppClient &) = delete;
    AppClient(AppClient &&) = delete;
    AppClient & operator=(const AppClient &) = delete;
    AppClient & operator=(AppClient &&) = delete;
    /** @} */

public:
    /**
     * @brief Class constructor.
     * @param[in] domain Common API C++ domain for the application client.
     * @param[in] instance Common API C++ instance for the application client.
     * @param[in] connection Common API C++ connection for the application client.
     */
    AppClient(const std::string & domain, const std::string & instance, const std::string & connection);

    /** Class destructor. */
    ~AppClient(void) override;

    /**
     * @brief Synchronous method to send a request and get the same data as a response.
     * @param[in] request Request from the client.
     * @param[out] response Response from the server.
     * @return Identifier for the error.
     */
    Utils::Error::ID ping(const std::string & request, std::string & response);
};

/**
 * @brief Main function for a client executable.
 * @return Identifier for the error.
 */
Utils::Error::ID main(void);

}

#endif /* LAPP_CCLIENT_HPP */

/******************************************************************************************************END OF FILE*****/
