/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.2.15.v202501031634.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/

#ifndef V0_COMMONAPI_APP_App_DBUS_DEPLOYMENT_HPP_
#define V0_COMMONAPI_APP_App_DBUS_DEPLOYMENT_HPP_



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif
#include <CommonAPI/DBus/DBusDeployment.hpp>
#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {
namespace app {
namespace App_ {

// Interface-specific deployment types
typedef CommonAPI::EmptyDeployment BaseStructDeployment_t;

typedef CommonAPI::DBus::StructDeployment<
    CommonAPI::EmptyDeployment,
    CommonAPI::EmptyDeployment
> Derived1Deployment_t;

typedef CommonAPI::DBus::StructDeployment<
    CommonAPI::EmptyDeployment,
    CommonAPI::DBus::StringDeployment
> Derived2Deployment_t;


// Type-specific deployments

// Attribute-specific deployments

// Argument-specific deployments

// Broadcast-specific deployments


} // namespace App_
} // namespace app
} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_APP_App_DBUS_DEPLOYMENT_HPP_
