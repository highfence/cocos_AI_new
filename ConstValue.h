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
		const char CHOCO_SPRITE[] = "Choco.png";
		const char CHOCO_ATTACK_SPRITE[] = "Choco_Attacking.png";

		// Member Variable
		const float SEARCHING_RANGE = 500.f;
		const float CHASING_RANGE = 600.f;
		const float ATTACK_RANGE = 150.f;
		const float INIT_WIDTH = 0.8f;
		const float INIT_HEIGHT = 0.8f;
		const float MOVE_SPEED = 200.f;
	}
}