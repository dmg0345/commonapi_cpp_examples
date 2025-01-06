/**
 ***********************************************************************************************************************
 * @file        server.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        06-01-2025 03:13:42 (UTC)
 * @version     0.0.3
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LAPP_CSERVER_HPP
#define LAPP_CSERVER_HPP

#include "utils/error/error.hpp"
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppStubDefault.hpp>

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

class AppStubImpl : public v0_1::commonapi::app::AppStubDefault
{
public:
    AppStubImpl();
    ~AppStubImpl() override;

    AppStubImpl(AppStubImpl &) = delete;
    AppStubImpl & operator=(AppStubImpl &) = delete;
    AppStubImpl(AppStubImpl &&) = delete;
    AppStubImpl & operator=(AppStubImpl &&) = delete;

    void sayHello(const std::shared_ptr<CommonAPI::ClientId> client, std::string name, sayHelloReply_t reply) override;
};

/**
 * @brief Main function for a server executable.
 * @return Error code.
 */
Utils::Error::Error main(void);

}

#endif /* LAPP_CSERVER_HPP */

/******************************************************************************************************END OF FILE*****/
