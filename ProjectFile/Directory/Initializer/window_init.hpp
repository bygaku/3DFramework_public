#pragma once

class Window final
{
public:
    Window() noexcept;
    ~Window() noexcept;

    /// @brief ウィンドウの初期化
    bool initialize() noexcept;

private:
    static bool instantiated_;

};