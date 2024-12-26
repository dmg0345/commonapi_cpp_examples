/**
 ***********************************************************************************************************************
 * @file        error.hpp
 * @author      ${PROJECT_AUTHOR} (${PROJECT_CONTACT})
 * @date        ${PROJECT_BUILD_TIMESTAMP_UTC}
 * @version     ${PROJECT_VERSION}
 * @copyright   ${PROJECT_COPYRIGHT}
 ***********************************************************************************************************************
 */

#ifndef UTILS_ERROR_HPP
#define UTILS_ERROR_HPP

#include <cstdint>

/**
 * @brief Error namespace.
 *
 * Provides error definitions and error management and handling functionality.
 *
 * To add an error, add the layer identifier to @c LID, add the component identifier to @c CID and define the error
 * in @c Error with an error identifier.
 */
namespace Utils::Error
{

/**
 * @brief Internal definitions.
 * @private
 */
namespace
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
    Version /**< Version component identifier. */
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

enum class Error : uint32_t
{
    OK = def(0U, CID::None, LID::None), /**< Generic no error, success. */
    UNKNOWN = def(1U, CID::None, LID::None), /**< Generic unknown error. */
    INVALID_ARGS = def(2U, CID::None, LID::None) /**< Generic invalid arguments error. */
};

// clang-format off

/**
 * @brief Triggers a @c return of when the given expression results in an error not Error::OK.
 * @param[in] expr The expression.
 * @return The error returned by @p expr.
 */
#define RET_ON_ERROR(expr)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        Utils::Error::Error error = (expr);                                                                            \
        if (error != Utils::Error::Error::OK)                                                                          \
        {                                                                                                              \
            return error;                                                                                              \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c return with the error specified when the given expression results in an error not Error::OK.
 * @param[in] expr The expression.
 * @param[in] new_error The error to return.
 * @return The error specified in @p new_error.
 */
#define RET_WITH_ERROR(expr, new_error)                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((expr) != Utils::Error::Error::OK)                                                                         \
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
 * @brief Triggers a @c goto to @c end label when the given expression results in an error not Error::OK.
 * @param[in] expr The expression.
 * @pre Requires an Error variable named @c error where to store the returned error and a @c end label.
 */
#define END_ON_ERROR(expr)                                                                                             \
    do                                                                                                                 \
    {                                                                                                                  \
        error = (expr);                                                                                                \
        if (error != Utils::Error::Error::OK)                                                                          \
        {                                                                                                              \
            goto end;                                                                                                  \
        }                                                                                                              \
    }                                                                                                                  \
    while (false)

/**
 * @brief Triggers a @c goto to @c end label with the error specified when the given expression results in an error
 * not Error::OK.
 * @param[in] expr The expression.
 * @param[in] new_error The error to store in the @c error variable defined.
 * @pre Requires an Error variable named @c error where to store the returned error and a @c end label.
 */
#define END_WITH_ERROR(expr, new_error)                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        if ((expr) != Utils::Error::Error::OK)                                                                         \
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

#endif /* UTILS_ERROR_HPP */

/******************************************************************************************************END OF FILE*****/
