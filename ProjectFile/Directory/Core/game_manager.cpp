#include "DxLib.h"
#include "Utility/assert_for_dxlib.hpp"
#include "Core/game_time.hpp"
#include "Core/game_manager.hpp"

Game* Game::instance_ = nullptr;

Game::Game() noexcept
	: gameTime_(new GameTime())
	, time_(0.0f)
{
}

Game& Game::getInstance() noexcept
{
	ASSERT(instance_ != nullptr, "instance_ isn't existing.");
	return *instance_;
}
 
void Game::create() noexcept
{
	ASSERT(instance_ == nullptr, "instance_ already exist.");
	instance_ = new Game();
}

void Game::destroy() noexcept
{
	ASSERT(instance_ != nullptr, "instance_ is nullptr.");
	DxLib_End();
	delete instance_;
	instance_ = nullptr;
}

void Game::onUpdate() noexcept
{
	clsDx();
	ClearDrawScreen();
	time_ += gameTime_->getDeltaTime();

	printfDx("GameTime:%.1f\n", time_);
	printfDx("Game.OnUpdate()\n");

	gameTime_->sleepForNextFrame();
	gameTime_->incrementFrame();
}
