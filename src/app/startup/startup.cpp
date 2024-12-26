/**
 ***********************************************************************************************************************
 * @file        startup.cpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#include "app/startup/startup.hpp"
#include "utils/error/error.hpp"

using Utils::Error::Error;

namespace App::Startup
{

Error main(void)
{
    return Error::OK;
}

}

#if !defined(DISABLE_MAIN)
int main(void)
{
    return static_cast<int>(App::Startup::main());
}
#endif

/******************************************************************************************************END OF FILE*****/
