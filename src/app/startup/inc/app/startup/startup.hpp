/**
 ***********************************************************************************************************************
 * @file        startup.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
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
