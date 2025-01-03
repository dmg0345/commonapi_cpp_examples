/**
 ***********************************************************************************************************************
 * @file        client.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        03-01-2025 22:07:48 (UTC)
 * @version     0.0.2
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
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
