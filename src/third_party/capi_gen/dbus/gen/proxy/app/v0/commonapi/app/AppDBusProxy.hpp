/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.2.15.v202501011835.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_APP_App_DBUS_PROXY_HPP_
#define V0_COMMONAPI_APP_App_DBUS_PROXY_HPP_

#include <v0/commonapi/app/AppProxyBase.hpp>
#include "v0/commonapi/app/AppDBusDeployment.hpp"

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/DBus/DBusAddress.hpp>
#include <CommonAPI/DBus/DBusFactory.hpp>
#include <CommonAPI/DBus/DBusProxy.hpp>
#include <CommonAPI/DBus/DBusAddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <string>

# if defined(_MSC_VER)
#  if _MSC_VER >= 1300
/*
 * Diamond inheritance is used for the CommonAPI::Proxy base class.
 * The Microsoft compiler put warning (C4250) using a desired c++ feature: "Delegating to a sister class"
 * A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class
 * by using a common abstract base class. This is also called cross delegation.
 */
#    pragma warning( disable : 4250 )
#  endif
# endif

namespace v0 {
namespace commonapi {
namespace app {

class AppDBusProxy
    : virtual public AppProxyBase,
      virtual public CommonAPI::DBus::DBusProxy {
public:
    AppDBusProxy(
        const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection);

    virtual ~AppDBusProxy();



    virtual void sayHello(std::string _name, CommonAPI::CallStatus &_internalCallStatus, std::string &_message, const CommonAPI::CallInfo *_info);
    virtual std::future<CommonAPI::CallStatus> sayHelloAsync(const std::string &_name, SayHelloAsyncCallback _callback, const CommonAPI::CallInfo *_info);


    virtual void getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const;

    virtual std::future<void> getCompletionFuture();

private:




    std::promise<void> completed_;
};

} // namespace app
} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_APP_App_DBUS_PROXY_HPP_

