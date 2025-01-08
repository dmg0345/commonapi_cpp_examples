/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.15.v202501031619.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_APP_App_PROXY_HPP_
#define V0_COMMONAPI_APP_App_PROXY_HPP_

#include <v0/commonapi/app/AppProxyBase.hpp>


#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {
namespace app {

template <typename ... _AttributeExtensions>
class AppProxy
    : virtual public App,
      virtual public AppProxyBase,
      virtual public _AttributeExtensions... {
public:
    AppProxy(std::shared_ptr<CommonAPI::Proxy> delegate);
    ~AppProxy();

    typedef ::v0::commonapi::app::App InterfaceType;


    /**
     * Returns the CommonAPI address of the remote partner this proxy communicates with.
     */
    virtual const CommonAPI::Address &getAddress() const;

    /**
     * Returns true if the remote partner for this proxy is currently known to be available.
     */
    virtual bool isAvailable() const;

    /**
     * Returns true if the remote partner for this proxy is available.
     */
    virtual bool isAvailableBlocking() const;

    /**
     * Returns the wrapper class that is used to (de-)register for notifications about
     * the availability of the remote partner of this proxy.
     */
    virtual CommonAPI::ProxyStatusEvent& getProxyStatusEvent();

    /**
     * Returns the wrapper class that is used to access version information of the remote
     * partner of this proxy.
     */
    virtual CommonAPI::InterfaceVersionAttribute& getInterfaceVersionAttribute();

    virtual std::future<void> getCompletionFuture();

    /**
     * Calls ping with synchronous semantics.
     *
     * All const parameters are input parameters to this method.
     * All non-const parameters will be filled with the returned values.
     * The CallStatus will be filled when the method returns and indicate either
     * "SUCCESS" or which type of error has occurred. In case of an error, ONLY the CallStatus
     * will be set.
     */
    virtual void ping(std::string _request, CommonAPI::CallStatus &_internalCallStatus, std::string &_response, const CommonAPI::CallInfo *_info = nullptr);
    /**
     * Calls ping with asynchronous semantics.
     *
     * The provided callback will be called when the reply to this call arrives or
     * an error occurs during the call. The CallStatus will indicate either "SUCCESS"
     * or which type of error has occurred. In case of any error, ONLY the CallStatus
     * will have a defined value.
     * The std::future returned by this method will be fulfilled at arrival of the reply.
     * It will provide the same value for CallStatus as will be handed to the callback.
     */
    virtual std::future<CommonAPI::CallStatus> pingAsync(const std::string &_request, PingAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr);



 private:
    std::shared_ptr< AppProxyBase> delegate_;
};

typedef AppProxy<> AppProxyDefault;


//
// AppProxy Implementation
//
template <typename ... _AttributeExtensions>
AppProxy<_AttributeExtensions...>::AppProxy(std::shared_ptr<CommonAPI::Proxy> delegate):
        _AttributeExtensions(*(std::dynamic_pointer_cast< AppProxyBase>(delegate)))...,
        delegate_(std::dynamic_pointer_cast< AppProxyBase>(delegate)) {
}

template <typename ... _AttributeExtensions>
AppProxy<_AttributeExtensions...>::~AppProxy() {
}

template <typename ... _AttributeExtensions>
void AppProxy<_AttributeExtensions...>::ping(std::string _request, CommonAPI::CallStatus &_internalCallStatus, std::string &_response, const CommonAPI::CallInfo *_info) {
    delegate_->ping(_request, _internalCallStatus, _response, _info);
}

template <typename ... _AttributeExtensions>
std::future<CommonAPI::CallStatus> AppProxy<_AttributeExtensions...>::pingAsync(const std::string &_request, PingAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    return delegate_->pingAsync(_request, _callback, _info);
}

template <typename ... _AttributeExtensions>
const CommonAPI::Address &AppProxy<_AttributeExtensions...>::getAddress() const {
    return delegate_->getAddress();
}

template <typename ... _AttributeExtensions>
bool AppProxy<_AttributeExtensions...>::isAvailable() const {
    return delegate_->isAvailable();
}

template <typename ... _AttributeExtensions>
bool AppProxy<_AttributeExtensions...>::isAvailableBlocking() const {
    return delegate_->isAvailableBlocking();
}

template <typename ... _AttributeExtensions>
CommonAPI::ProxyStatusEvent& AppProxy<_AttributeExtensions...>::getProxyStatusEvent() {
    return delegate_->getProxyStatusEvent();
}

template <typename ... _AttributeExtensions>
CommonAPI::InterfaceVersionAttribute& AppProxy<_AttributeExtensions...>::getInterfaceVersionAttribute() {
    return delegate_->getInterfaceVersionAttribute();
}


template <typename ... _AttributeExtensions>
std::future<void> AppProxy<_AttributeExtensions...>::getCompletionFuture() {
    return delegate_->getCompletionFuture();
}

} // namespace app
} // namespace commonapi
} // namespace v0



// Compatibility
namespace v0_1 = v0;

#endif // V0_COMMONAPI_APP_App_PROXY_HPP_
