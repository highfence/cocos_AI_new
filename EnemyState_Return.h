#pragma once
#include "EnemyState.h"

class EnemyState_Return: public EnemyState
{
public:
	CREATE_FUNC(EnemyState_Return);
	bool		init() override
	{
		return true;
	}

	void		startState(Enemy* enemy) override;
	void		runState(Enemy* enemy, float dt) override;
	void		endState(Enemy* enemy) override;

	bool		isPlayerInChasingRange(Enemy*, float);

};