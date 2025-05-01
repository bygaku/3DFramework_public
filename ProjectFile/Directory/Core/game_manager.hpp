#pragma once
#include "memory"

class GameTime;

class Game
{
public:
	static Game& getInstance() noexcept;
	static void create() noexcept;
	static void destroy() noexcept;

	bool isRunning() const noexcept { return !ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE); };
	void onUpdate() noexcept;

private:
	static Game* instance_;

	GameTime* gameTime_;

private:
	Game() noexcept;
	~Game() noexcept = default;

	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;

	float time_;
};
