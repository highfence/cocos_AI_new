#pragma once

namespace STATIC
{
	const Size visibleSize = Size(1024, 768);
}


namespace PLAYER
{
	enum DIRECTION
	{
		NONE = 0, RIGHT = 1, LEFT = -1, UP = 1, DOWN = -1
	};

	const char PLAYER_SPRITE[] = "Character.png";
	const float INIT_WIDTH = 0.2f;
	const float INIT_HEIGHT = 0.2f;
	const int PIXEL_PER_SEC = 300;
}


namespace ENEMY
{
	enum ENEMY_TYPE
	{
		Choco
	};

	namespace CHOCO
	{
		// Sprite


		// Member Variable
		float SEARCHING_RANGE = 500.f;
		float CHASING_RANGE = 600.f;
		float ATTACK_RANGE = 150.f;
		float INIT_WIDTH = 0.8f;
		float INIT_HEIGHT = 0.8f;
		float MOVE_SPEED = 200.f;
	}
}