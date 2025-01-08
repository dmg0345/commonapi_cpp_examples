/**
 ***********************************************************************************************************************
 * @file        runtime.hpp
 * @author      Diego Martínez García (dmg0345@gmail.com)
 * @date        08-01-2025 17:09:18 (UTC)
 * @version     1.0.0
 * @copyright   github.com/dmg0345/commonapi_cpp_examples/blob/master/LICENSE
 ***********************************************************************************************************************
 */

#ifndef LUTILS_CCAPI_RUNTIME_HPP
#define LUTILS_CCAPI_RUNTIME_HPP

#include <memory>
#include <string>
#include <utility>

#include "utils/error/error.hpp"

#include <CommonAPI/CommonAPI.hpp>

namespace Utils::Capi
{

/** Singleton that provides generic functionality related to the Common API C++ runtime for the application. */
class Runtime
{
    /** Private constructor for singleton pattern. */
    Runtime(void);

    /** Delete copy constructor, move constructor, copy operator and move operator. @{ */
    Runtime(const Runtime &) = delete;
    Runtime(Runtime &&) = delete;
    Runtime & operator=(const Runtime &) = delete;
    Runtime & operator=(Runtime &&) = delete;
    /** @} */

public:
    /** Class destructor. */
    ~Runtime(void);

    /**
     * @brief Retrieves the instance associated to the singleton class.
     * @return The singleton instance.
     */
    static Runtime & get_instance(void);

    /**
     * @brief Gets a pointer to the Common API C++ runtime.
     * @param[out] ptr The pointer retrieved.
     * @return Identifier for the error.
     */
    Utils::Error::ID get_runtime(std::shared_ptr<CommonAPI::Runtime> & ptr) const;

    /**
     * @brief Sets the values of one or multiple properties.
     *
     * Known properties used internally by the framework are:
     *
     * - @c LogApplication and @c LogContext to configure logging.
     * - @c LibraryBase to configure library runtime bindings when not found via other means.
     *
     * Check the source code of the runtime bindings for details on how these properties are used.
     * 
     * @param[in] props Names and values for each property.
     * @return Identifier for the error.
     */
    Utils::Error::ID set_properties(const std::map<std::string, std::string> & props) const;

    /**
     * @brief Gets the value of one or multiple properties.
     * @param[in] names Names of the properties to obtain.
     * @param[out] props Names and values for each property.
     * @return Identifier for the error.
     */
    Utils::Error::ID get_properties(const std::vector<std::string> & names,
                                    std::map<std::string, std::string> & props) const;
};

}

#endif /* LUTILS_CCAPI_RUNTIME_HPP */

/******************************************************************************************************END OF FILE*****/
