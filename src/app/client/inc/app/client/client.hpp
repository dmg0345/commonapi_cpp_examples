/**
 ***********************************************************************************************************************
 * @file        client.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        06-01-2025 03:13:42 (UTC)
 * @version     0.0.3
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
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
