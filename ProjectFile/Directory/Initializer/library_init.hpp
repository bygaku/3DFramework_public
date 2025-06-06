#pragma once

class Lib final
{
public:
    Lib() noexcept;
    ~Lib() noexcept;

    /// @brief システムの初期化
    bool initialize() noexcept;

private:
    bool succeedInit_;
    static bool instantiated_;

};