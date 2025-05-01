#include "DxLib.h"
#include "Utility/assert_for_dxlib.hpp"
#include "Initializer/library_init.hpp"

bool Lib::instantiated_ = false;

Lib::Lib() noexcept
	: succeedInit_(false)
{
	ASSERT(instantiated_ == 0, "already instantiated.");
	instantiated_ = true;
}

Lib::~Lib() noexcept
{
	instantiated_ = false;
}

bool Lib::initialize() noexcept
{
	// DirectXを有効化
	SetUseDirect3DVersion(DX_DIRECT3D_11);
	SetUseDirectInputFlag(false);

	if (DxLib_Init() == -1) return false;
	
	// Zバッファ設定
	SetUseZBuffer3D(true);
	SetWriteZBuffer3D(true);
	SetUseBackCulling(true);

	DEBUG_BREAK();

	return true;
}
