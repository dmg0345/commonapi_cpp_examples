/**
 ***********************************************************************************************************************
 * @file        server.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LAPP_CSERVER_HPP
#define LAPP_CSERVER_HPP

#include "utils/error/error.hpp"
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppStubDefault.hpp>

/**
 * @brief Server component.
 * @rst
 * Handles the server concept of the client / server architecture in CommonAPI C++.
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
