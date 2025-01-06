/**
 ***********************************************************************************************************************
 * @file        client.cpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#include <iostream>
#include <thread>

#include "app/client/client.hpp"
#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppProxy.hpp>

using Utils::Error::Error;

Error App::Client::main(void)
{
    CommonAPI::Runtime::setProperty("LogContext", "CLT");
    CommonAPI::Runtime::setProperty("LogApplication", "CLT");
    CommonAPI::Runtime::setProperty("LibraryBase", "App");

    const std::shared_ptr<CommonAPI::Runtime> & runtime = CommonAPI::Runtime::get();

    const std::string & domain = "local";
    const std::string & instance = "commonapi.app.App";
    const std::string & connection = "client-sample";

    const std::shared_ptr<v0::commonapi::app::AppProxy<>> & myProxy =
        runtime->buildProxy<v0::commonapi::app::AppProxy>(domain, instance, connection);

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

/******************************************************************************************************END OF FILE*****/
