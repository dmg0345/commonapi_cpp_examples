/**
 ***********************************************************************************************************************
 * @file        server.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef LUTILS_CCAPI_SERVER_HPP
#define LUTILS_CCAPI_SERVER_HPP

#include <memory>
#include <functional>
#include <concepts>

#include "utils/capi/priv/runtime.hpp"
#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppStubDefault.hpp>

namespace Utils::Capi
{

namespace Priv
{

/**
 * @brief Base implementation for a service, each service maps to a single Common API C++ stub.
 * @tparam Stub The Common API C++ stub type this service maps to.
 */
template<typename Stub>
class ServiceBase : public Stub
{
    /** Delete default constructor copy constructor, move constructor, copy operator and move operator. @{ */
    ServiceBase(void) = delete;
    ServiceBase(const ServiceBase &) = delete;
    ServiceBase(ServiceBase &&) = delete;
    ServiceBase & operator=(const ServiceBase &) = delete;
    ServiceBase & operator=(ServiceBase &&) = delete;
    /** @} */

public:
    /** Class Destructor. */
    ~ServiceBase(void) override { }

    /**
     * @brief Generate a new instance of the service as a shared pointer.
     * @tparam Service The type of service create, this is, the derived service from the base service.
     * @tparam ServiceTArgs The type of parameters to forward to the initialization of the shared pointer.
     * @param[in] domain Domain identifier for the service.
     * @param[in] instance Instance identifier for the service.
     * @param[in] connection Connection identifier for the service.
     * @param[in] ServiceFArgs Service specific parameters.
     * @return The shared pointer with the instance or @c nullptr on error.
     */
    template<typename Service, typename... ServiceTArgs>
    static std::shared_ptr<Service> make(const std::string & domain,
                                         const std::string & instance,
                                         const std::string & connection,
                                         ServiceTArgs... ServiceFArgs)
    {
        // Create shared pointer to instance and keep a weak reference.
        auto ptr = std::make_shared<Service>(domain, instance, connection, std::forward<ServiceTArgs>(ServiceFArgs)...);
        ptr->stub = std::static_pointer_cast<ServiceBase>(ptr);

        return ptr;
    }

    /**
     * @brief Starts the service in the Common API C++ runtime.
     * @return Identifier for the error.
     */
    Utils::Error::ID start(void)
    {
        auto error = Utils::Error::ID::UNKNOWN;
        std::shared_ptr<CommonAPI::Runtime> runtime_ptr = nullptr;
        std::shared_ptr<Stub> stub_ptr = this->get_stub_ptr();

        // Ensure pointer is valid, this is redundant.
        RET_ON_TRUE_WITH_ERROR(stub_ptr == nullptr, Utils::Error::ID::NULL_POINTER);
        // Check if already registered, and in that case silently return.
        RET_ON_TRUE_WITH_ERROR(this->registered, Utils::Error::ID::OK);
        // Get runtime and register service.
        RET_ON_ERROR(Capi::Runtime::get_instance().get_runtime(runtime_ptr));
        // Register service.
        RET_ON_TRUE_WITH_ERROR(!runtime_ptr->registerService(this->domain, this->instance, stub_ptr, this->connection),
                               Utils::Error::ID::CAPI_SERVER);

        // All good.
        this->registered = true;
        error = Utils::Error::ID::OK;

        return error;
    }

    /**
     * @brief Stops the service in the Common API C++ runtime.
     * @return Identifier for the error.
     */
    Utils::Error::ID stop(void)
    {
        auto error = Utils::Error::ID::UNKNOWN;
        std::shared_ptr<CommonAPI::Runtime> runtime_ptr = nullptr;
        std::shared_ptr<Stub> stub_ptr = this->get_stub_ptr();

        // Ensure pointer is valid, this is redundant.
        RET_ON_TRUE_WITH_ERROR(stub_ptr == nullptr, Utils::Error::ID::NULL_POINTER);
        // Check if already registered, and in that case silently return.
        RET_ON_TRUE_WITH_ERROR(!this->registered, Utils::Error::ID::OK);
        // Get runtime and register service.
        RET_ON_ERROR(Capi::Runtime::get_instance().get_runtime(runtime_ptr));
        // Unregister service.
        const auto & unreg_info = stub_ptr->getStubAdapter()->getAddress();
        RET_ON_TRUE_WITH_ERROR(!runtime_ptr->unregisterService(unreg_info.getDomain(),
                                                               unreg_info.getInterface(),
                                                               unreg_info.getInstance()),
                               Utils::Error::ID::CAPI_SERVER);

        // All good.
        this->registered = false;
        error = Utils::Error::ID::OK;

        return error;
    }

protected:
    /** Class constructor, refer to Utils::Capi::Priv::ServiceBase::make for details on the parameters. */
    ServiceBase(const std::string & domain, const std::string & instance, const std::string & connection) :
        Stub(), domain(domain), instance(instance), connection(connection), registered(false)
    { }

    std::string domain; /**< Domain identifier. */
    std::string instance; /**< Instance identifier. */
    std::string connection; /**< Connection identifier. */
    bool registered; /**< @c true if service has been registered and @c false otherwise. */

private:
    /**
     * @brief Converts a shared pointer to the Common API C++ stub type.
     * @return The pointer to the Common API C++ stub type for the service or @c nullptr.
     * @note It should not be possible for this function to return @c nullptr, but perform checks anyway.
     */
    std::shared_ptr<Stub> get_stub_ptr(void) { return std::static_pointer_cast<Stub>(stub.lock()); }

    std::weak_ptr<ServiceBase> stub; /**< Weak pointer to instance created as a shared pointer. */
};

}

/** Application service base type. */
using AppServiceBase = Priv::ServiceBase<v0_1::commonapi::app::AppStubDefault>;

/**
 * @brief The implementation of the server, all the services.
 * @tparam AppService The application service, with the Common API C++ hooks implemented.
 */
template<typename AppService>
    requires std::derived_from<AppService, AppServiceBase>
class Server
{
    /** Delete default constructor copy constructor, move constructor, copy operator and move operator. @{ */
    Server(void) = delete;
    Server(const Server &) = delete;
    Server(Server &&) = delete;
    Server & operator=(const Server &) = delete;
    Server & operator=(Server &&) = delete;
    /** @} */

public:
    /**
     * @brief Class constructor.
     * @param[in] app Application service instance.
     */
    explicit Server(const std::shared_ptr<AppService> & app) : app(app) { }

    /** Class Destructor. */
    virtual ~Server(void) { }

    /**
     * @brief Starts the server.
     * @return Identifier for the error.
     */
    Utils::Error::ID start(void)
    {
        auto error = Utils::Error::ID::UNKNOWN;

        // Start application service.
        RET_ON_ERROR(this->app->start());

        // All good.
        error = Utils::Error::ID::OK;

        return error;
    }

    /**
     * @brief Stops the server.
     * @return Identifier for the error.
     */
    Utils::Error::ID stop(void)
    {
        auto error = Utils::Error::ID::UNKNOWN;

        // Stop application service.
        RET_ON_ERROR(this->app->stop());

        // All good.
        error = Utils::Error::ID::OK;

        return error;
    }

    std::shared_ptr<AppService> app; /**< Application service. */
};

}

#endif /* LUTILS_CCAPI_SERVER_HPP */

/******************************************************************************************************END OF FILE*****/
