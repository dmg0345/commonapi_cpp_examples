/**
 ***********************************************************************************************************************
 * @file        app.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LAPP_HPP
#define LAPP_HPP

/**
 * @rst
 * The application layer implements a client/server architecture using the COVESA / GENIVI Common API C++ Framework. It
 * supports both D-Bus and SOME/IP bindings. The application layer is split into the following components.
 *
 * - :doc:`client`
 * - :doc:`server`
 * - :doc:`startup`
 *
 * Build or Installation Folder Structure
 * --------------------------------------
 *
 * A full build or an installation generates by default the following folder structure in *.cmake_build/.out* and
 * *dist* folders respectively.
 *
 * .. code-block::
 *
 *     <parent_folder>
 *     └── bin
 *         ├── capicpp_client.elf
 *         ├── capicpp_server.elf
 *         ├── core
 *         │   └── libcapicpp_core_common.so
 *         ├── dbus
 *         │   ├── commonapi-dbus.ini
 *         │   ├── commonapi.ini
 *         │   ├── libcapicpp_dbus_common.so
 *         │   ├── libcapicpp_dbus_proxy.so
 *         │   └── libcapicpp_dbus_stub.so
 *         └── someip
 *             ├── commonapi-someip.ini
 *             ├── commonapi.ini
 *             ├── libcapicpp_someip_common.so
 *             ├── libcapicpp_someip_proxy.so
 *             ├── libcapicpp_someip_stub.so
 *             └── vsomeip.json
 *
 * The **capicpp_client.elf** and **capicpp_server.elf** are the client and server executables respectively.
 *
 * The **libcapicpp_core_common.so** file is the shared library compiled from the source code generated by the
 * Common API C++ Core generator from the ``.fidl`` files.
 *
 * The **dbus/libcapicpp_dbus_common.so**, **dbus/libcapicpp_dbus_proxy.so** and **dbus/libcapicpp_dbus_stub.so**
 * files are the shared libraries compiled from the source code generated by the Common API C++ D-Bus generator
 * from the ``.fidl`` and ``.dbus.fdepl`` files.
 *
 * The **someip/libcapicpp_someip_common.so**, **someip/libcapicpp_someip_proxy.so** and
 * **someip/libcapicpp_someip_stub.so** files are the shared libraries compiled from the source code generated
 * by the Common API C++ SOME/IP generator from the ``.fidl`` and ``.someip.fdepl`` files.
 *
 * Shared libraries with the *proxy* keyword are linked to the client executable. Shared libraries with the *stub*
 * keyword are linked to the server executable. Shared libraries with the *common* keyword are linked to both client
 * and server executables.
 *
 * The other files are the respective configuration files for the D-Bus and SOME/IP bindings, refer to
 * :any:`Common API C++ Abstraction <Utils::Capi>` for details or inspect the files in the repository.
 *
 * To execute the client and server with D-Bus runtime binding, proceed as in the snippet below:
 *
 * .. code-block:: powershell
 *
 *     # Start Common API C++ resources.
 *     ./manage.ps1 commonapi-up;
 *     
 *     # Set the necessary environment variables for Common API C++ framework.
 *     $ENV:COMMONAPI_CONFIG = "./dbus/commonapi.ini";
 *     $ENV:COMMONAPI_DBUS_CONFIG = "./dbus/commonapi-dbus.ini";
 *     $ENV:DBUS_SESSION_BUS_ADDRESS = "unix:path=/tmp/dbus-commonapi";
 *     
 *     # Move to the directory where the executables are located.
 *     cd '<parent_folder>/bin';
 *     ./capicpp_server.elf; # Start the server in terminal #1 or fork it.
 *     ./capicpp_client.elf; # Start the client in terminal #2 or fork it.
 *     cd -;
 *     
 *     # When finished, stop Common API C++ resources.
 *     ./manage.ps1 commonapi-down;
 *
 * To execute the client and server with SOME/IP runtime binding, proceed as in the snippet below:
 *
 * .. code-block:: powershell
 *
 *     # Start Common API C++ resources.
 *     ./manage.ps1 commonapi-up;
 *     
 *     # Set the necessary environment variables for Common API C++ framework.
 *     $ENV:COMMONAPI_CONFIG = "./someip/commonapi.ini";
 *     $ENV:COMMONAPI_SOMEIP_CONFIG = "./someip/commonapi-someip.ini";
 *     $ENV:VSOMEIP_CONFIGURATION = "./someip/vsomeip.json";
 *     
 *     # Move to the directory where the executables are located.
 *     cd '<parent_folder>/bin';
 *     ./capicpp_server.elf; # Start the server in terminal #1 or fork it.
 *     ./capicpp_client.elf; # Start the client in terminal #2 or fork it.
 *     cd -;
 *     
 *     # When finished, stop Common API C++ resources.
 *     ./manage.ps1 commonapi-down;
 * 
 * @endrst
 */
namespace App
{ }

#endif /* LAPP_HPP */

/******************************************************************************************************END OF FILE*****/
