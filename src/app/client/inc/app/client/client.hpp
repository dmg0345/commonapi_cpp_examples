/**
 ***********************************************************************************************************************
 * @file        client.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef LAPP_CCLIENT_HPP
#define LAPP_CCLIENT_HPP

#include "utils/error/error.hpp"

/**
 * @brief Client component.
 * @rst
 * Handles the client concept of the client / server architecture in CommonAPI C++.
 * @endrst
 */
namespace App::Client
{

/**
 * @brief Main function for a client executable.
 * @return Error code.
 */
Utils::Error::Error main(void);

}

#endif /* LAPP_CCLIENT_HPP */

/******************************************************************************************************END OF FILE*****/
