#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Return.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Search.h"

/*
Returning

���� ���¿��� Origin�� ���� UnitVec�� �ް�, �� �������� move�ϴ� ����.

1.       �÷��̾���� �Ÿ��� ChasingRange - 300������ ���, Approaching ���·� ����.
2.       Origin���� �Ÿ��� 50�ΰ��, Searching ���·� ����.

*/

void EnemyState_Return::startState(Enemy* enemy)
{
	CCLOG("Start Return!");
}


void EnemyState_Return::runState(Enemy* enemy, float dt)
{
	float distanceFromPlayer = enemy->getDistanceFromPlayer();
	float distanceFromOrigin = enemy->getDistanceFromOrigin();

	if (isPlayerInReChasingRange(enemy, distanceFromPlayer))
	{
		enemy->changeState<EnemyState_Approach>();
	}
	else if (distanceFromOrigin < STATIC::ORIGIN_RANGE)
	{
		enemy->changeState<EnemyState_Search>();
	}
	else
	{
		enemy->CalUnitVecToOrigin();
		enemy->move(dt);
	}

	return;
}


void EnemyState_Return::endState(Enemy* enemy)
{
	CCLOG("End Return");
}


// �÷��̾ enemy�� ReChasing_Range �ȿ� �ִٸ� true�� ��ȯ�ϴ� �Լ�.
bool EnemyState_Return::isPlayerInReChasingRange(Enemy* enemy, float distance)
{
	if (distance < enemy->getChasingRange() - STATIC::CHASING_MINUS_VAL)
	{
		return true;
	}

	return false;
}