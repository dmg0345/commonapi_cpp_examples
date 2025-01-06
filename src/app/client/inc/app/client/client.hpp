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
 * @rst
 * The *client* component implements the client concept of the Common API C++ client/server architecture, it supports
 * both D-Bus and SOME/IP runtime bindings.
 *
 * In this project, it implements request methods and non-persistent storage to test the different functionalities of
 * the Common API C++ framework, refer to the :any:`application <::App>` for details of how it fits with the rest of the
 * architecture.
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
