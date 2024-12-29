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

#include <CommonAPI/CommonAPI.hpp>

using Utils::Error::Error;

namespace App::Startup
{

Error main(void)
{
#if (defined(CAPICPP_CLIENT) && !defined(CAPICPP_SERVER))

#elif (!defined(CAPICPP_CLIENT) && defined(CAPICPP_SERVER))

#else
#error "Neither 'CAPICPP_CLIENT' or 'CAPICPP_SERVER' are defined, or both are defined."
#endif

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
