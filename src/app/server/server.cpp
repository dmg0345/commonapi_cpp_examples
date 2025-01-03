/**
 ***********************************************************************************************************************
 * @file        server.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#include <iostream>
#include <thread>

#include "app/server/server.hpp"
#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>

using Utils::Error::Error;

namespace App::Server
{

AppStubImpl::AppStubImpl() { }

AppStubImpl::~AppStubImpl() { }

void AppStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> client, std::string name, sayHelloReply_t reply)
{
    (void)client;

    std::stringstream messageStream;

    messageStream << "Hello " << name << "!";
    std::cout << "sayHello('" << name << "'): '" << messageStream.str() << "'\n";

    reply(messageStream.str());
};

Error main(void)
{
    CommonAPI::Runtime::setProperty("LogContext", "SRV");
    CommonAPI::Runtime::setProperty("LogApplication", "SRV");
    CommonAPI::Runtime::setProperty("LibraryBase", "App");

    const std::shared_ptr<CommonAPI::Runtime> & runtime = CommonAPI::Runtime::get();

    const std::string & domain = "local";
    const std::string & instance = "commonapi.app.App";
    const std::string & connection = "server-sample";

    const std::shared_ptr<AppStubImpl> & myService = std::make_shared<AppStubImpl>();
    bool successfullyRegistered = runtime->registerService(domain, instance, myService, connection);

    while (!successfullyRegistered)
    {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtime->registerService(domain, instance, myService, connection);
    }

    std::cout << "Successfully Registered Service!" << std::endl;

    while (true)
    {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }

    return Error::OK;
}

}

/******************************************************************************************************END OF FILE*****/
