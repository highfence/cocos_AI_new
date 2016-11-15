#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"

/*
Approaching

�÷��̾ ���� UnitVec�� �ް�, �� �������� move�ϴ� ����.

1.     AttackRange�ȿ� ���� ���, Attacking���·� ����.
2.     �÷��̾���� �Ÿ��� ChasingRange�̻����� ������ ���, Returning���·� ����.


Func : bool IsPlayerInChasingRange()

	Enemy need

	Variable
	- float m_ChasingRange
	- Vec2 m_UnitVec
	- float m_DistanceFromPlayer
	- float m_AttackRange
	- float m_MoveSpeed

	Function
	- void move(Vec2 unitVec, float dt);
-void CalUnitVecToPlayer();
-void CalDistanceFromPlayer();
*/