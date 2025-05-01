#pragma once

class WindowData final
{
public:
#ifdef _RELEASE
    static constexpr int WIDTH  = 1920;     /// @brief 画面横サイズ
    static constexpr int HEIGHT = 1080;     /// @brief 画面縦サイズ
#else
    static constexpr int WIDTH  = 1280;     /// @brief 画面横サイズ
    static constexpr int HEIGHT =  720;     /// @brief 画面縦サイズ
#endif
    static constexpr int COLOR_BIT = 16;    /// @brief カラービット
};
