/**
 ***********************************************************************************************************************
 * @file        startup.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        28-12-2024 15:28:40 (UTC)
 * @version     0.0.1
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
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
