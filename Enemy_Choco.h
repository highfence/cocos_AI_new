#pragma once

#include "Enemy.h"

class Enemy_Choco : public Enemy
{
	bool init() override;

	bool isAttackedOnce;

	// Function
	virtual void SetSpriteToAttack();
	virtual void SetSpriteToCommon();

	CREATE_FUNC(Enemy_Choco);


};