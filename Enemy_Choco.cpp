#include "pch.h"
#include "Enemy_Choco.h"
#include "EnemyState_Search.h"

using namespace ENEMY::CHOCO;

bool Enemy_Choco::init()
{
	if (!Enemy::init())
	{
		return false;
	}

	setSearchingRange(SEARCHING_RANGE);
	setChasingRange(CHASING_RANGE);
	setAttackRange(ATTACK_RANGE);
	setOrigin(Point(STATIC::visibleSize.width * INIT_WIDTH, STATIC::visibleSize.height * INIT_HEIGHT));
	setMoveSpeed(MOVE_SPEED);
	setIsAttackedOnce(false); 
	setIsHited(false);

	m_pSprite = Sprite::create(CHOCO_SPRITE);
	m_pSprite->setPosition(getOrigin());
	addChild(m_pSprite);

	changeState<EnemyState_Search>();

	return true;
}

// m_pSprite를 공격 스프라이트로 변환.
void Enemy_Choco::SetSpriteToAttack()
{
	m_pSprite = Sprite::create(CHOCO_ATTACK_SPRITE);
	addChild(m_pSprite);
	return;
}

// m_pSprite를 일상 스프라이트로 변환.
void Enemy_Choco::SetSpriteToCommon()
{
	m_pSprite = Sprite::create(CHOCO_SPRITE);
	addChild(m_pSprite);
	return;
}