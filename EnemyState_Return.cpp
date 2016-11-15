#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Return.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Search.h"

/*
Returning

현재 상태에서 Origin을 향한 UnitVec를 받고, 그 방향으로 move하는 상태.

1.       플레이어와의 거리가 ChasingRange - 300이하인 경우, Approaching 상태로 돌입.
2.       Origin과의 거리가 50인경우, Searching 상태로 돌입.

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


// 플레이어가 enemy의 ReChasing_Range 안에 있다면 true를 반환하는 함수.
bool EnemyState_Return::isPlayerInReChasingRange(Enemy* enemy, float distance)
{
	if (distance < enemy->getChasingRange() - STATIC::CHASING_MINUS_VAL)
	{
		return true;
	}

	return false;
}