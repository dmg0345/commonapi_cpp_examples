/**
 ***********************************************************************************************************************
 * @file        test_lapp.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef TEST_LAPP_HPP
#define TEST_LAPP_HPP

/**
 * @rst
 * Test suite for the application layer, tests for this test suite have `AppDBusTestFixture` and `AppSomeIPTestFixture`
 * identifiers in the relevant test reports. The test suite is located at *tests/tests/lapp* folder in the repopsitory.
 *
 * This test fixture start a client (Common API C++ proxy) and a server (Common API C++ Stub) in the same executable,
 * and the tests perform interactions such as writing and reading data of different types.
 *
 * For convenience two different *CMake* executable targets are created and therefore two executable files are
 * generated, one named `test_lapp_dbus` intended to be used with the DBus runtime bindings, and another executable
 * of name `test_lapp_someip` is generated intended to be used with the SOME/IP runtime bindings.
 * 
 * Test Folder Structure
 * ---------------------
 *
 * The required folder structure in the development container for this test suite is similar to the one required
 * for the :any:`application <::App>`, and it is described in the piece of code below.
 *
 * .. code-block::
 *
 *     <parent_folder>
 *     ├── core
 *     │   └── libcapicpp_core_common.so
 *     ├── dbus
 *     │   ├── commonapi-dbus.ini
 *     │   ├── commonapi.ini
 *     │   ├── libcapicpp_dbus_common.so
 *     │   ├── libcapicpp_dbus_proxy.so
 *     │   └── libcapicpp_dbus_stub.so
 *     ├── someip
 *     │   ├── commonapi-someip.ini
 *     │   ├── commonapi.ini
 *     │   ├── libcapicpp_someip_common.so
 *     │   ├── libcapicpp_someip_proxy.so
 *     │   ├── libcapicpp_someip_stub.so
 *     │   └── vsomeip.json
 *     ├── test_lapp_dbus.elf
 *     └── test_lapp_someip.elf
 * 
 * Executing the Test Suite
 * ------------------------
 *
 * To run the test suite with D-Bus runtime binding and identifiers, follow the snippet below:
 *
 * .. code-block:: powershell
 *
 *     # Ensure that there is a D-Bus session in the background on '/tmp-commonapi'.
 *     # Alternatively, run './manage.ps1 commonapi-up'.
 *     $dPid = 'dbus-daemon' --session --print-pid --address 'unix:path=/tmp/dbus-commonapi' --fork;
 *
 *     # Set the necessary environment variables for Common API C++ framework.
 *     $ENV:COMMONAPI_CONFIG = "./dbus/commonapi.ini";
 *     $ENV:COMMONAPI_DBUS_CONFIG = "./dbus/commonapi-dbus.ini";
 *     $ENV:DBUS_SESSION_BUS_ADDRESS = "unix:path=/tmp/dbus-commonapi";
 *
 *     # Move to the directory where the test executables located and start the test suite.
 *     cd '<parent_folder>';
 *     ./test_lapp_dbus.elf
 *     cd -;
 *
 *     # Terminate the D-Bus session previously started.
 *     # Alternatively, run './manage.ps1 commonapi-down'.
 *     & 'kill' -SIGTERM "$dPid";
 *
 * To run the test suite with SOME/IP runtime bindings and test identifiers, follow the snippet below:
 *
 * .. code-block:: powershell
 *
 *     # Set the necessary environment variables for Common API C++ framework.
 *     $ENV:COMMONAPI_CONFIG = "./someip/commonapi.ini";
 *     $ENV:COMMONAPI_SOMEIP_CONFIG = "./someip/commonapi-someip.ini";
 *     $ENV:VSOMEIP_CONFIGURATION = "./someip/vsomeip.json";
 *
 *     # Move to the directory where the test executables located and start the test suite.
 *     cd '<parent_folder>';
 *     ./test_lapp_someip.elf
 *     cd -;
 *
 * The contents of the configuration files and the libraries are the same ones as the ones compiled for the
 * :any:`application <::App>`, refer to that link for more details. In this project, when running the tests
 * through supported tooling such as *ctest* the details just described have already been handled by *cmake* during
 * the configuration and compilation stages.
 * @endrst
 */
namespace Tests::Suites::App
{ }

#endif /* TEST_LAPP_HPP */

/******************************************************************************************************END OF FILE*****/
