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
 * @rst
 * The *startup* component provides the initialization and ``main`` function entry point for the application.
 *
 * The compilation of the ``main`` entry point can be disabled with the ``DISABLE_MAIN`` compile time definition,
 * this allows for implementation of use cases with external main loops, such as with the test suites.
 * @endrst
 */
namespace App::Startup
{

/**
 * @brief The implementation of the main function as a function in a C++ namespace.
 * @return Identifier for the error.
 */
Utils::Error::ID main(void);

}

#if !defined(DISABLE_MAIN) || defined(DOXYGEN)
/**
 * @brief Main free function and entry point.
 * @param[in] argc The number of command line arguments.
 * @param[in] argv The command line arguments.
 * @return Identifier for the error.
 * @note Use @c DISABLE_MAIN to disable the compilation of this function, and have an external main loop instead.
 */
int main(int argc, char ** argv);
#endif

#endif /* LAPP_CSTARTUP_HPP */

/******************************************************************************************************END OF FILE*****/
