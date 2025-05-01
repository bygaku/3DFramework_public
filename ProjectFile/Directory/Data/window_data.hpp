#pragma once

class WindowData final
{
public:
#ifdef _RELEASE
    static constexpr int WIDTH  = 1920;     /// @brief ��ʉ��T�C�Y
    static constexpr int HEIGHT = 1080;     /// @brief ��ʏc�T�C�Y
#else
    static constexpr int WIDTH  = 1280;     /// @brief ��ʉ��T�C�Y
    static constexpr int HEIGHT =  720;     /// @brief ��ʏc�T�C�Y
#endif
    static constexpr int COLOR_BIT = 16;    /// @brief �J���[�r�b�g
};
