#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"
#include "EnemyState_Attack.h"
#include "EnemyState_Return.h"

/*
	Approaching

	�÷��̾ ���� UnitVec�� �ް�, �� �������� move�ϴ� ����.

	1.     AttackRange�ȿ� ���� ���, Attacking���·� ����.
	2.     �÷��̾���� �Ÿ��� ChasingRange�̻����� ������ ���, Returning���·� ����.
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

// �÷��̾ enemy�� Chasing_Range �ȿ� �ִٸ� true�� ��ȯ�ϴ� �Լ�.
bool EnemyState_Approach::isPlayerInChasingRange(Enemy* enemy, float distance)
{
	if (distance < enemy->getChasingRange())
	{
		return true;
	}

	return false;
}

// �÷��̾ enemy�� Attack_Range - 100 �ȿ� �ִٸ� true�� ��ȯ�ϴ� �Լ�.
bool EnemyState_Approach::isPlayerInAttackRangeMinus(Enemy* enemy, float distance)
{
	if (distance < enemy->getAttackRange() - STATIC::ATTACK_MINUS_VAL)
	{
		return true;
	}

	return false;
}