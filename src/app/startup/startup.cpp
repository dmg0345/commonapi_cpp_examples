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
#if (defined(CAPICPP_CLIENT) && !defined(CAPICPP_SERVER))
#include "app/client/client.hpp"
#elif (!defined(CAPICPP_CLIENT) && defined(CAPICPP_SERVER))
#include "app/server/server.hpp"
#else
#error "Neither 'CAPICPP_CLIENT' or 'CAPICPP_SERVER' are defined, or both are defined."
#endif

using Utils::Error::Error;

Error App::Startup::main(void)
{
#if defined(CAPICPP_CLIENT)
    return App::Client::main();
#elif defined(CAPICPP_SERVER)
    return App::Server::main();
#endif
}

#if !defined(DISABLE_MAIN) || defined(DOXYGEN)
int main(int argc, char ** argv)
{
    (void)argc;
    (void)argv;

    return static_cast<int>(App::Startup::main());
}
#endif

/******************************************************************************************************END OF FILE*****/
