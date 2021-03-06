#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Attack.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Waiting.h"

/*

	Attacking

	Attack Range안에 들어온 경우, 공격을 시도하는 상태. 스프라이트 전환.

	1.     플레이어와의 거리가 Attack Range 이상인 경우, Approaching 상태로 돌입.
	2.     IsAttackedOnce가 False인 경우, Waiting상태로 돌입.

*/

void EnemyState_Attack::startState(Enemy* enemy)
{
	CCLOG("Start Attack!");
	enemy->SetSpriteToAttack();
}

void EnemyState_Attack::runState(Enemy* enemy, float dt)
{
	float distanceFromPlayer = enemy->getDistanceFromPlayer();

	if (!enemy->getIsAttackedOnce())
	{
		enemy->changeState<EnemyState_Waiting>();
	}
	else if (!isPlayerInAttackRange(enemy, distanceFromPlayer))
	{
		enemy->changeState<EnemyState_Approach>();
	}
	else
	{
		CCLOG("Attack!");
	}

	return;
}

void EnemyState_Attack::endState(Enemy* enemy)
{
	CCLOG("End Attack!");
	enemy->SetSpriteToCommon();
}

bool EnemyState_Attack::isPlayerInAttackRange(Enemy* enemy, float distance)
{
	if (distance < enemy->getAttackRange())
	{
		return true;
	}

	return false;
}