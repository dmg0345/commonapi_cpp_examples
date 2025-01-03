/**
 ***********************************************************************************************************************
 * @file        client.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#include <iostream>
#include <thread>

#include "app/client/client.hpp"
#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppProxy.hpp>

using Utils::Error::Error;
using namespace v0::commonapi::app;

namespace App::Client
{

Error main(void)
{
    CommonAPI::Runtime::setProperty("LogContext", "CLT");
    CommonAPI::Runtime::setProperty("LogApplication", "CLT");
    CommonAPI::Runtime::setProperty("LibraryBase", "App");

    const std::shared_ptr<CommonAPI::Runtime> & runtime = CommonAPI::Runtime::get();

    const std::string & domain = "local";
    const std::string & instance = "commonapi.app.App";
    const std::string & connection = "client-sample";

    const std::shared_ptr<AppProxy<>> & myProxy = runtime->buildProxy<AppProxy>(domain, instance, connection);

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
    {
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
    std::cout << "Available..." << std::endl;

    const std::string name = "World";
    CommonAPI::CallStatus callStatus = CommonAPI::CallStatus::SUCCESS;
    std::string returnMessage;

    CommonAPI::CallInfo info(1000);
    info.sender_ = 1234;

    while (true)
    {
        myProxy->sayHello(name, callStatus, returnMessage, &info);
        if (callStatus != CommonAPI::CallStatus::SUCCESS)
        {
            std::cerr << "Remote call failed!" << std::endl;
            return Error::UNKNOWN;
        }
        info.timeout_ = info.timeout_ + 1000;

        std::cout << "Got message: '" << returnMessage << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return Error::OK;
}

}

/******************************************************************************************************END OF FILE*****/
