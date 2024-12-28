/**
 ***********************************************************************************************************************
 * @file        startup.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        28-12-2024 15:28:40 (UTC)
 * @version     0.0.1
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef APP_STARTUP_HPP
#define APP_STARTUP_HPP

#include "utils/error/error.hpp"

/**
 * @brief Startup component.
 * @rst
 * Provides the initialization for the application and the sole include header for third-party and library headers.
 *
 * The compilation of main can be disabled with the @c DISABLE_MAIN definition.
 * @endrst
 */
namespace App::Startup
{

/**
 * @brief The implementation of the main function.
 * @return Error code.
 */
Utils::Error::Error main(void);

}

#if !defined(DISABLE_MAIN)
/**
 * @brief Main function.
 * @return Error code.
 */
int main(void);
#endif

#endif /* APP_STARTUP_HPP */

/******************************************************************************************************END OF FILE*****/
