/**
 ***********************************************************************************************************************
 * @file        startup.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LAPP_CSTARTUP_HPP
#define LAPP_CSTARTUP_HPP

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

#endif /* LAPP_CSTARTUP_HPP */

/******************************************************************************************************END OF FILE*****/
