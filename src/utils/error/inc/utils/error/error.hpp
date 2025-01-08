/**
 ***********************************************************************************************************************
 * @file        error.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef LUTILS_CERROR_HPP
#define LUTILS_CERROR_HPP

#include <cstdint>
#include <stdexcept>

/**
 * @rst
 * The *error* component provides definitions, functions and macros for optional error management application wide.
 * @endrst
 */
namespace Utils::Error
{

/**
 * @brief Internal implementation details.
 * @private
 */
namespace Priv
{

/**
 * @brief Layer identifiers.
 */
enum class LID : uint32_t
{
    None = 0U, /**< No layer identifier. */
    App, /**< Application layer identifier. */
    Utils /**< Utils layer identifier. */
};

/**
 * @brief Component identifiers.
 */
enum class CID : uint32_t
{
    None = 0U, /**< No component identifier. */
    Error, /**< Error component identifier. */
    Version, /**< Version component identifier. */
    CommonAPI, /**< Common API C++, also known as @c capi, component identifier. */
    Startup, /**< Startup component identifier. */
    Client, /**< Client component identifier. */
    Server /**< Server component identifier. */
};

/**
 * @brief Defines an error.
 * @param[in] eid The error identifier.
 * @param[in] cid The component identifier.
 * @param[in] lid The layer identifier.
 * @return The error.
 */
constexpr uint32_t def(const uint32_t eid, const CID cid, const LID lid)
{
    const uint32_t eid_r = ((eid & 0xFFU) << 0U);
    const uint32_t cid_r = ((static_cast<uint32_t>(cid) & 0xFFU) << 8U);
    const uint32_t lid_r = ((static_cast<uint32_t>(lid) & 0xFFU) << 16U);

    return (eid_r | cid_r | lid_r);
}

}

/** Identifiers for the different error codes. */
enum class ID : uint32_t
{
    /** Generic no error, success. */
    OK = def(0U, Priv::CID::None, Priv::LID::None),
    /** Generic unknown error. */
    UNKNOWN = def(1U, Priv::CID::None, Priv::LID::None),
    /** Generic invalid arguments error. */
    INVALID_ARGS = def(2U, Priv::CID::None, Priv::LID::None),
    /** Generic null pointer error. */
    NULL_POINTER = def(3U, Priv::CID::None, Priv::LID::None),

    /** Underlying error in the Common API C++ Runtime abstraction. */
    CAPI_RUNTIME = def(0U, Priv::CID::CommonAPI, Priv::LID::Utils),
    /** Underlying error in the Common API C++ Client / Proxy abstraction. */
    CAPI_CLIENT = def(1U, Priv::CID::CommonAPI, Priv::LID::Utils),
    /** Underlying error in the Common API C++ Server / Stub abstraction. */
    CAPI_SERVER = def(2U, Priv::CID::CommonAPI, Priv::LID::Utils)
};

/** Base exception for errors. */
class BaseException : public std::exception
{
public:
    /**
     * @brief Class constructor.
     * @param what The message to be raised as part of the exception.
     */
    explicit BaseException(const std::string & what) : message(what) { }

    /**
     * @brief Message to raise for the exception.
     * @return Message for the exception as a C NULL terminated string.
     */
    const char * what(void) const noexcept override { return message.c_str(); }

private:
    std::string message; /**< Message related to the exception. */
};

// clang-format off

/**
 * @brief Triggers a @c return of when the given expression results in an error not Utils::Error::ID::OK.
 * @param[in] expr The expression.
 * @return The error returned by @p expr.
 * @pre Requires an Error variable named @c error where to store the returned error.
 */
#define RET_ON_ERROR(expr)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        error = (expr);                                                                                                \
        if (error != Utils::Error::ID::OK)                                                                             \
        {                                                                                                              \
            return error;                                                                                              \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c return with the error specified when the given expression results in an error not
 * Utils::Error::ID::OK.
 * @param[in] expr The expression.
 * @param[in] new_error The error to return.
 * @return The error specified in @p new_error.
 */
#define RET_WITH_ERROR(expr, new_error)                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((expr) != Utils::Error::ID::OK)                                                                            \
        {                                                                                                              \
            return new_error;                                                                                          \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c return with the error specified when the given expression results in @c true.
 * @param[in] expr The expression.
 * @param[in] new_error The error to return.
 * @return The error specified in @p new_error.
 */
#define RET_ON_TRUE_WITH_ERROR(expr, new_error)                                                                        \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((expr))                                                                                                    \
        {                                                                                                              \
            return new_error;                                                                                          \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c goto to @c end label when the given expression results in an error not Utils::Error::ID::OK.
 * @param[in] expr The expression.
 * @pre Requires an Error variable named @c error where to store the returned error and a @c end label.
 */
#define END_ON_ERROR(expr)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        error = (expr);                                                                                                \
        if (error != Utils::Error::ID::OK)                                                                             \
        {                                                                                                              \
            goto end;                                                                                                  \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c goto to @c end label with the error specified when the given expression results in an error
 * not Utils::Error::ID::OK.
 * @param[in] expr The expression.
 * @param[in] new_error The error to store in the @c error variable defined.
 * @pre Requires an Error variable named @c error where to store the returned error and a @c end label.
 */
#define END_WITH_ERROR(expr, new_error)                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((expr) != Utils::Error::ID::OK)                                                                            \
        {                                                                                                              \
            error = (new_error);                                                                                       \
            goto end;                                                                                                  \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c goto to @c end label with the error specified when the given expression results in @c true.
 * @param[in] expr The expression.
 * @param[in] new_error The error to store in the @c error variable defined.
 * @pre Requires an Error variable named @c error where to store the returned error and a @c end label.
 */
#define END_ON_TRUE_WITH_ERROR(expr, new_error)                                                                        \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((expr))                                                                                                    \
        {                                                                                                              \
            error = (new_error);                                                                                       \
            goto end;                                                                                                  \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

// clang-format on

}

#endif /* LUTILS_CERROR_HPP */

/******************************************************************************************************END OF FILE*****/
