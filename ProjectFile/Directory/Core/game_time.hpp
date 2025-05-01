#pragma once
#include "memory"

class GameTime
{
public:	
    GameTime() noexcept;
    ~GameTime() noexcept;

    /// @brief フレームカウントを +1
    /// @remark 毎フレーム処理前に呼び出す
    void incrementFrame() noexcept;

    /// @brief 固定フレームの更新回数を更新して返す
    int updateFixedFrameCount() noexcept;

    /// @brief 現在の1フレーム処理時間 (seconds)
    [[nodiscard]] double getCurrentFrameTime() const noexcept;

    /// @brief fpsTarget_ として指定されている時間まで待つ
    void sleepForNextFrame() const noexcept;

    /// @brief fps 制限を指定
    void setFpsTarget(int target) noexcept;

    /// @brief 2つ前と1つ前のフレーム間の時間差 (seconds)
    [[nodiscard]] static const float& getDeltaTime() noexcept { return dt_; }

private:
    /// @brief 現在のフレームの時間
    [[nodiscard]] const LONGLONG& getTime() const noexcept { return time_; }

    /// @brief 最後に fps を更新した時間 (nanoseconds)
    [[nodiscard]] const LONGLONG& getLastCheckedTime() const noexcept { return fpsCheckTime_; }

    /// @brief 起動からの時間 (seconds)
    [[nodiscard]] const float& getTimeFromBoot() const noexcept { return timeSinceStartUp_; }

    /// @brief 現在の frames per second
    [[nodiscard]] const int& getFps() const noexcept { return fps_; };

    /// @brief 最後の fps 更新からのフレームカウント
    [[nodiscard]] const int& getFpsCounter() const noexcept { return fpsCounter_; };

    /// @brief 現在の fps 制限
    [[nodiscard]] const int& getFpsTarget() const noexcept { return fpsTarget_; };

    /// @brief 現在の fps 制限によるフレーム間の秒数 (seconds)
    [[nodiscard]] const double& getSecondsPerFrame() const noexcept { return secondsPerFrame_; };

    /// @brief 最後の固定間隔更新の回数
    [[nodiscard]] const int& getLastFixedFrameCount() const noexcept { return lastFixedFrameCount_; };

    /// @brief 起動してからのフレーム数
    [[nodiscard]] const unsigned int& getFrames() const noexcept { return frames_; };

private:
    static bool instantiated_;

    GameTime(const GameTime&) = delete;
    GameTime& operator=(const GameTime&) = delete;

private:
    LONGLONG time_;
    LONGLONG fpsCheckTime_;
    LONGLONG fixedUpdateCheckTime_;
    float    timeSinceStartUp_;

    int      fps_;
    int      fpsTarget_;
    int      fpsCounter_;
    double   secondsPerFrame_;
    int      lastFixedFrameCount_;

    static float dt_;
    unsigned int frames_;

};
