/// @file assert_for_dxlib.hpp
/// @ref https://qiita.com/ASURA-the-great-robot/items/07c9756b6b8b1be0c937

#ifndef DXLIB_ASSERT_HPP
#define DXLIB_ASSERT_HPP
#pragma once

#include "DxLib.h"
#include "string_view"
#include "source_location"

namespace gaku_utils
{
    /// @brief エラーメッセージを表示して終了する関数
    [[noreturn]] void ErrorAssert(
        std::string_view conditional_expression,
        std::string_view error_mes,
        std::string_view file,
        std::string_view func,
        int line);

    /// @brief エラーに関連する定数
    namespace error_constants 
    {
        constexpr int exit_code = 99;
        constexpr auto assertion_header =
            "Assertion Error! Please press 'X button' or 'Escape key' on the window to exit!\n\n";
    }
}

#ifdef _DEBUG
/// @brief エラーが発生したときにエラーメッセージを表示する。
/// DxLib の動作を止め、独自のエラーメッセージを表示する。
/// DxLib が初期化されていない場合は、例外を投げる。
/// @param expr TRUE条件文
/// @param error_message エラーメッセージ
#define ASSERT(expr, error_message)                                     \
do {                                                                    \
    const auto result_ = (expr);                                        \
    if (!(result_))                                                     \
    {                                                                   \
        const auto location = std::source_location::current();          \
        if (DxLib_IsInit() != TRUE)                                     \
        {                                                               \
            std::fprintf(stderr, "DxLib is not initialized.\n");        \
            std::exit(1);                                               \
        }                                                               \
        else                                                            \
        {                                                               \
            gaku_utils::ErrorAssert(#expr, error_message,               \
                location.file_name(), location.function_name(),         \
                location.line());                                       \
        }                                                               \
    }                                                                   \
} while(false)

/// @brief ポインタがnullptrでないことを確認する
#define ASSERT_NOT_NULL_PTR(ptr)         \
ASSERT((ptr) != nullptr, "nullptr.")     \

#else

#define ASSERT(expr, error_mes) ((void)0)
#define ASSERT_NOT_NULL_PTR(ptr) ((void)0)

#endif

#endif // DXLIB_ASSERT_HPP