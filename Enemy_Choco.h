#pragma once

#include "Enemy.h"

class Enemy_Choco : public Enemy
{
public :
	bool init() override;


	// Function
/*	virtual void SetSpriteToAttack();
	virtual void SetSpriteToCommon()*/;

	CREATE_FUNC(Enemy_Choco);


};