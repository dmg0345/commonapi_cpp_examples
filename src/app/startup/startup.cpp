/**
 ***********************************************************************************************************************
 * @file        startup.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
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

namespace App::Startup
{

Error main(void)
{
#if defined(CAPICPP_CLIENT)
    return App::Client::main();
#elif defined(CAPICPP_SERVER)
    return App::Server::main();
#endif
}

}

#if !defined(DISABLE_MAIN)
int main(void)
{
    return static_cast<int>(App::Startup::main());
}
#endif

/******************************************************************************************************END OF FILE*****/
