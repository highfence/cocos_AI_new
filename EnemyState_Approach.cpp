#include "pch.h"
#include "Enemy.h"
#include "EnemyState_Approach.h"

/*
Approaching

플레이어를 향한 UnitVec를 받고, 그 방향으로 move하는 상태.

1.     AttackRange안에 들어온 경우, Attacking상태로 돌입.
2.     플레이어와의 거리가 ChasingRange이상으로 벌어진 경우, Returning상태로 돌입.


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