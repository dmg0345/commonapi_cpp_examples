/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.15.v202501031619.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_APP_App_STUB_HPP_
#define V0_COMMONAPI_APP_App_STUB_HPP_

#include <functional>
#include <sstream>




#include <v0/commonapi/app/App.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <vector>


#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {
namespace app {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service App. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class AppStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual App {
 public:


    virtual void deactivateManagedInstances() = 0;


protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for App.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class AppStubRemoteEvent
{
public:
    virtual ~AppStubRemoteEvent() { }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service App to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class AppStub
    : public virtual CommonAPI::Stub<AppStubAdapter, AppStubRemoteEvent>
{
public:
    typedef std::function<void (std::string _response)> pingReply_t;

    virtual ~AppStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 1);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// This is the method that will be called on remote calls on the method ping.
    virtual void ping(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _request, pingReply_t _reply) = 0;


    using CommonAPI::Stub<AppStubAdapter, AppStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<AppStubAdapter, AppStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<AppStubAdapter, AppStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef AppStubRemoteEvent RemoteEventType;
    typedef ::v0::commonapi::app::App StubInterface;
};

} // namespace app
} // namespace commonapi
} // namespace v0


// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_APP_App_STUB_HPP_
