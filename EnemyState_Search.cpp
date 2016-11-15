#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Search.h"


void EnemyState_Search::startState(Enemy* enemy)
{
	CCLOG("start_Searching!");
}

void EnemyState_Search::runState(Enemy* enemy, float dt)
{
	float distance = enemy->getDistance();

	if (isPlayerInSearchRange(enemy, distance))
	{
		enemy->changeState<EnemyState_Approach>();
	}
}

void EnemyState_Search::endState(Enemy* enemy)
{
	CCLOG("end_Searching!");
}

// �÷��̾ enemy�� SEARCHING_RANGE�ȿ� �ִٸ� true�� ��ȯ�ϴ� �Լ�.
bool EnemyState_Search::isPlayerInSearchRange(Enemy* enemy, float distance)
{
	if (distance < enemy->SEARCHING_RANGE)
	{
		return true;
	}

	return false;
}
