/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.15.v202501031642.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V0_COMMONAPI_APP_APP_SOMEIP_STUB_ADAPTER_HPP_
#define V0_COMMONAPI_APP_APP_SOMEIP_STUB_ADAPTER_HPP_

#include <v0/commonapi/app/AppStub.hpp>
#include <v0/commonapi/app/AppSomeIPDeployment.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {
namespace app {

template <typename _Stub = ::v0::commonapi::app::AppStub, typename... _Stubs>
class AppSomeIPStubAdapterInternal
    : public virtual AppStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< AppSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> AppSomeIPStubAdapterHelper;

    ~AppSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        AppSomeIPStubAdapterHelper::deinit();
    }

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v0::commonapi::app::AppStub,
        CommonAPI::Version
    > getAppInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v0::commonapi::app::AppStub,
        std::tuple< std::string>,
        std::tuple< std::string>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>,
        std::tuple< CommonAPI::SomeIP::StringDeployment>
    > pingStubDispatcher;
    
    AppSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        AppSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< AppStub>(_stub)),
        getAppInterfaceVersionStubDispatcher(&AppStub::lockInterfaceVersionAttribute, &AppStub::getInterfaceVersion, false, true),
        pingStubDispatcher(
            &AppStub::ping,
            false,
            _stub->hasElement(0),
            std::make_tuple(&::v0::commonapi::app::App_::ping_requestDeployment),
            std::make_tuple(static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr)))
        
    {
        AppSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x7530) }, &pingStubDispatcher );
        // Provided events/fields
    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};


template <typename _Stub, typename... _Stubs>
void AppSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {

}

template <typename _Stub, typename... _Stubs>
void AppSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {

}

template <typename _Stub = ::v0::commonapi::app::AppStub, typename... _Stubs>
class AppSomeIPStubAdapter
    : public AppSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    AppSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          AppSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace app
} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_APP_App_SOMEIP_STUB_ADAPTER_HPP_
