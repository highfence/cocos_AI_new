#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Waiting.h"
#include "EnemyState_Attack.h"
#include "EnemyState_Approach.h"

/*

Waiting

     Player�� ������ ��ٸ��� ����.

	1.     IsAttackedOnce�� True�� ��� Attacking���·� ����.
	2.     �÷��̾���� �Ÿ��� Attack Range �̻��� ���, Approaching ���·� ����.


     Enemy need

          Variable
          - bool IsAttackedOnce
*/

void EnemyState_Waiting::startState(Enemy* enemy)
{
	CCLOG("Start Waiting");
}

void EnemyState_Waiting::runState(Enemy* enemy, float dt)
{
	if (enemy->getIsAttackedOnce())
	{
		enemy->changeState<EnemyState_Attack>();
	}
	else if (!isPlayerInAttackRange(enemy, enemy->getDistanceFromPlayer()))
	{
		enemy->changeState<EnemyState_Approach>();
	}

	return;
}

void EnemyState_Waiting::endState(Enemy* enemy)
{
	CCLOG("End Waiting");
}

bool EnemyState_Waiting::isPlayerInAttackRange(Enemy* enemy, float distance)
{
	if (distance < enemy->getAttackRange())
	{
		return true;
	}

	return false;
}
