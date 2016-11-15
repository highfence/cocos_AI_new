#pragma once

#include "Enemy.h"

class Enemy_Choco : public Enemy
{
	bool init(ENEMY::ENEMY_TYPE enemy_type) override;

	bool isAttackedOnce;

	CREATE_FUNC_ENEMY(Enemy_Choco);

};