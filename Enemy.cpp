#include "pch.h"
#include "Enemy.h"
#include "math.h"


bool Enemy::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	// TODO :: ENEMY TYPE�� ���� INIT�� �� ���⼭ �ٸ� ������ �ް� �ϱ�.
	// ���� ��Ȳ�� ������ Ŭ������ init���� ������ ������ �ϰ� �ȴ�.
	// �ڵ� �ߺ� ���.

	return true;
}

void Enemy::update(float dt)
{
	m_pState->runState(this, dt);
	return;
}

// �÷��̾���� �Ÿ��� ���Ͽ� m_DistanceFromPlayer�� �������ش�.
void Enemy::CalDistanceFromPlayer(Point playerPosition)
{
	float x = playerPosition.x - m_pSprite->getPosition().x;
	float y = playerPosition.y - m_pSprite->getPosition().y;

	setDistanceFromPlayer(abs(sqrt(x * x + y * y)));

	return;
}

// Enemy�� Origin�� �Ÿ��� ���Ͽ� m_DistanceFromOrigin�� ����.
void Enemy::CalDistanceFromOrigin()
{
	Point originPoint = getOrigin();
	float x = originPoint.x - m_pSprite->getPosition().x;
	float y = originPoint.y - m_pSprite->getPosition().y;

	setDistanceFromOrigin(abs(sqrt(x * x + y * y)));

	return;
}


// Delta ���� �޾� ��������Ʈ�� �����̴� �Լ�.
void Enemy::move(float dt)
{
	float dtX = getUnitVec().x * getMoveSpeed() * dt;
	float dtY = getUnitVec().y * getMoveSpeed() * dt;

	auto currentX = m_pSprite->getPositionX();
	auto currentY = m_pSprite->getPositionY();

	m_pSprite->setPosition(currentX + dtX, currentY + dtY);
	return;
}

// Origin���� ���ϴ� UnitVec�� ���ϴ� �Լ�.
void Enemy::CalUnitVecToOrigin()
{
	if (!getDistanceFromOrigin())
	{
		return;
	}

	float distanceFromOrigin = getDistanceFromOrigin();
	Vec2 origin = getOrigin();

	float x = origin.x - m_pSprite->getPosition().x;
	float y = origin.y - m_pSprite->getPosition().y;

	Vec2 unitVecToOrigin(x / distanceFromOrigin, y / distanceFromOrigin);
	setUnitVec(unitVecToOrigin);
	return;
}

// �÷��̾�� ���ϴ� UnitVec�� ���ϴ� �Լ�.
void Enemy::CalDistanceFromPlayer(Point playerPosition)
{
	if (!getDistanceFromPlayer())
	{
		return;
	}
	float distanceFromPlayer = getDistanceFromPlayer();

	float x = playerPosition.x - m_pSprite->getPosition().x;
	float y = playerPosition.y - m_pSprite->getPosition().y;

	Vec2 unitVecToPlayer(x / distanceFromPlayer, y / distanceFromPlayer);
	setUnitVec(unitVecToPlayer);
	return;
}

