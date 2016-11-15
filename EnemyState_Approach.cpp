#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Attack.h"
#include "EnemyState_Return.h"

/*
	Approaching

	플레이어를 향한 UnitVec를 받고, 그 방향으로 move하는 상태.

	1.     AttackRange안에 들어온 경우, Attacking상태로 돌입.
	2.     플레이어와의 거리가 ChasingRange이상으로 벌어진 경우, Returning상태로 돌입.
*/


void EnemyState_Approach::startState(Enemy* enemy)
{
	CCLOG("start_Approaching!");
}

void EnemyState_Approach::runState(Enemy* enemy, float dt)
{
	float distanceFromPlayer = enemy->getDistanceFromPlayer();

	if (isPlayerInAttackRangeMinus(enemy, distanceFromPlayer))
	{
		enemy->changeState<EnemyState_Attack>();
	}
	else if (!isPlayerInChasingRange(enemy, distanceFromPlayer))
	{
		enemy->changeState<EnemyState_Return>();
	}
	else
	{
		enemy->CalUnitVecToPlayer();
		enemy->move(dt);
	}

	return;
}

void EnemyState_Approach::endState(Enemy* enemy)
{
	CCLOG("end_Approach!");
}

// 플레이어가 enemy의 Chasing_Range 안에 있다면 true를 반환하는 함수.
bool EnemyState_Approach::isPlayerInChasingRange(Enemy* enemy, float distance)
{
	if (distance < enemy->getChasingRange())
	{
		return true;
	}

	return false;
}

// 플레이어가 enemy의 Attack_Range - 100 안에 있다면 true를 반환하는 함수.
bool EnemyState_Approach::isPlayerInAttackRangeMinus(Enemy* enemy, float distance)
{
	if (distance < enemy->getAttackRange() - STATIC::ATTACK_MINUS_VAL)
	{
		return true;
	}

	return false;
}