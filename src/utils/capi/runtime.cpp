/**
 ***********************************************************************************************************************
 * @file        runtime.cpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#include "utils/capi/priv/runtime.hpp"

#include <string>

#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>

namespace Capi = Utils::Capi;
namespace Error = Utils::Error;

Capi::Runtime::Runtime(void) { }

Capi::Runtime::~Runtime(void) { }

Capi::Runtime & Capi::Runtime::get_instance(void)
{
    // Initialize as a static, this is atomic and already thread safe.
    static auto inst = Runtime();

    return inst;
}

Error::ID Capi::Runtime::get_runtime(std::shared_ptr<CommonAPI::Runtime> & ptr) const
{
    auto error = Error::ID::UNKNOWN;

    // Retrieve pointer to runtime and check it is not NULL.
    auto ptr_temp = CommonAPI::Runtime::get();
    END_ON_TRUE_WITH_ERROR(ptr_temp == nullptr, Error::ID::NULL_POINTER);

    // All good.
    ptr = std::move(ptr_temp);
    error = Error::ID::OK;

end:

    return error;
}

Error::ID Capi::Runtime::set_properties(const std::map<std::string, std::string> & props) const
{
    auto error = Error::ID::UNKNOWN;
    std::shared_ptr<CommonAPI::Runtime> ptr_runtime = nullptr;

    // Get runtime pointer.
    END_ON_ERROR(this->get_runtime(ptr_runtime));

    // Set properties, in the order they were specified.
    for (const auto & [name, value] : props)
    {
        // Update value of the property.
        ptr_runtime->setProperty(name, value);

        // Retrieve value for the property after write, and ensure it was updated to specified value.
        std::map<std::string, std::string> rprops;
        END_ON_ERROR(this->get_properties({name}, rprops));
        END_ON_TRUE_WITH_ERROR(rprops[name] != value, Error::ID::CAPI_RUNTIME);
    }

    // All good.
    error = Error::ID::OK;

end:

    return error;
}

Error::ID Capi::Runtime::get_properties(const std::vector<std::string> & names,
                                        std::map<std::string, std::string> & props) const
{
    auto error = Error::ID::UNKNOWN;
    std::shared_ptr<CommonAPI::Runtime> ptr_runtime = nullptr;
    std::map<std::string, std::string> temp_props = {};

    // Get runtime pointer.
    END_ON_ERROR(this->get_runtime(ptr_runtime));

    for (const auto & name : names)
    {
        // Get value for the property.
        auto value = ptr_runtime->getProperty(name);

        // An empty string is an error.
        END_ON_TRUE_WITH_ERROR(value.empty(), Error::ID::CAPI_RUNTIME);

        // Add value to properties found.
        temp_props[name] = std::move(value);
    }

    // All good.
    props = std::move(temp_props);
    error = Error::ID::OK;

end:

    return error;
}

/******************************************************************************************************END OF FILE*****/
