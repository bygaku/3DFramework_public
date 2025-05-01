#pragma once

class Lib final
{
public:
    Lib() noexcept;
    ~Lib() noexcept;

    /// @brief ƒVƒXƒeƒ€‚Ì‰Šú‰»
    bool initialize() noexcept;

private:
    bool succeedInit_;
    static bool instantiated_;

};