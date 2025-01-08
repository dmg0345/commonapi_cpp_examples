/**
 ***********************************************************************************************************************
 * @file        client.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LUTILS_CCAPI_CLIENT_HPP
#define LUTILS_CCAPI_CLIENT_HPP

#include <memory>
#include <functional>
#include <concepts>

#include "utils/capi/priv/runtime.hpp"
#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/app/AppProxy.hpp>

namespace Utils::Capi
{

namespace Priv
{

/**
 * @brief Base implementation for a client, each client maps to a single Common API C++ proxy.
 * @tparam Proxy The Common API C++ proxy type this client maps to.
 * @tparam AttributeExtensions Attribute extensions for @p Proxy, if any.
 */
template<template<typename...> typename Proxy, typename... AttributeExtensions>
class ClientBase
{
    /** Delete default constructor copy constructor, move constructor, copy operator and move operator. @{ */
    ClientBase(void) = delete;
    ClientBase(const ClientBase &) = delete;
    ClientBase(ClientBase &&) = delete;
    ClientBase & operator=(const ClientBase &) = delete;
    ClientBase & operator=(ClientBase &&) = delete;
    /** @} */

public:
    /** Class Destructor. */
    virtual ~ClientBase(void) { }

    /**
     * @brief Generate a new instance of the client as a shared pointer.
     * @tparam Client The type of client create, this is, the derived client from the base client.
     * @tparam ClientTArgs The type of parameters to forward to the initialization of the shared pointer.
     * @param[in] domain Domain identifier for the client.
     * @param[in] instance Instance identifier for the client.
     * @param[in] connection Connection identifier for the client.
     * @param[in] ClientFArgs Client specific parameters.
     * @return The shared pointer with the instance or @c nullptr on error.
     */
    template<typename Client, typename... ClientTArgs>
    static std::shared_ptr<Client> make(const std::string & domain,
                                        const std::string & instance,
                                        const std::string & connection,
                                        ClientTArgs... ClientFArgs)
    {
        // Create shared pointer to instance.
        return std::make_shared<Client>(domain, instance, connection, std::forward<ClientTArgs>(ClientFArgs)...);
    }

    /**
     * @brief Starts the client.
     * @return Identifier for the error.
     */
    Utils::Error::ID start(void)
    {
        auto error = Error::ID::UNKNOWN;

        // If already started then silently return.
        RET_ON_TRUE_WITH_ERROR(this->proxy != nullptr, Error::ID::OK);
        // Get runtime pointer.
        std::shared_ptr<CommonAPI::Runtime> runtime_ptr = nullptr;
        RET_ON_ERROR(Capi::Runtime::get_instance().get_runtime(runtime_ptr));
        // Build proxy and ensure it is not null.
        auto proxy_ptr = runtime_ptr->buildProxy<Proxy>(this->domain, this->instance, this->connection);
        RET_ON_TRUE_WITH_ERROR(proxy_ptr == nullptr, Error::ID::NULL_POINTER);
        // Wait until available to start it. // TODO: Add timeout
        while (!proxy_ptr->isAvailable())
        {
            ;
        }

        // All good.
        this->proxy = std::move(proxy_ptr);
        error = Error::ID::OK;

        return error;
    }

    /**
     * @brief Stops the client.
     * @return Identifier for the error.
     */
    Utils::Error::ID stop(void)
    {
        auto error = Error::ID::UNKNOWN;

        // If already stopped then silently return.
        RET_ON_TRUE_WITH_ERROR(this->proxy == nullptr, Error::ID::OK);
        // Fetch termination promise and explicitly destroy pointer.
        auto term_promise = this->proxy->getCompletionFuture();
        this->proxy = nullptr;
        // Clear proxy and wait for termination promise to acknowledge termination.
        term_promise.wait(); // TODO: Add timeout.

        // All good.
        error = Error::ID::OK;

        return error;
    }

protected:
    /**
     * @brief Class constructor.
     * @param[in] domain Domain identifier for the service.
     * @param[in] instance Instance identifier for the service.
     * @param[in] connection Connection identifier for the service.
     */
    ClientBase(const std::string & domain, const std::string & instance, const std::string & connection) :
        domain(domain), instance(instance), connection(connection)
    { }

    std::string domain; /**< Domain identifier. */
    std::string instance; /**< Instance identifier. */
    std::string connection; /**< Connection identifier. */
    std::shared_ptr<Proxy<AttributeExtensions...>> proxy; /**< Proxy instance. */
};

}

using AppClientBase = Priv::ClientBase<v0_1::commonapi::app::AppProxy>; /**< Application client base type. */

/**
 * @brief The implementation of all the clients.
 * @tparam AppClient The application client, with the Common API C++ hooks implemented.
 */
template<typename AppClient>
    requires std::derived_from<AppClient, AppClientBase>
class Client
{
    /** Delete default constructor copy constructor, move constructor, copy operator and move operator. @{ */
    Client(void) = delete;
    Client(const Client &) = delete;
    Client(Client &&) = delete;
    Client & operator=(const Client &) = delete;
    Client & operator=(Client &&) = delete;
    /** @} */

public:
    /**
     * @brief Class constructor.
     * @param[in] app Application client instance.
     */
    explicit Client(const std::shared_ptr<AppClient> & app) : app(app) { }

    /** Class Destructor. */
    virtual ~Client(void) { }

    /**
     * @brief Starts the client.
     * @return Identifier for the error.
     */
    Utils::Error::ID start(void)
    {
        auto error = Utils::Error::ID::UNKNOWN;

        // Start application client.
        RET_ON_ERROR(this->app->start());

        // All good.
        error = Utils::Error::ID::OK;

        return error;
    }

    /**
     * @brief Stops the client.
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

    std::shared_ptr<AppClient> app; /**< Application client. */
};

}

#endif /* LUTILS_CCAPI_CLIENT_HPP */

/******************************************************************************************************END OF FILE*****/
