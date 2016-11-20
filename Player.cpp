#include "pch.h"
#include "Player.h"
#include "gainput\gainput.h"
#include "windows.h"

using namespace PLAYER;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//Initialize member variable
	setPlayerDirectionX(DIRECTION::NONE);
	setPlayerDirectionY(DIRECTION::NONE);
	setIsAttacking(false);

	// 초기 스프라이트 설정.
	TCHAR plistNameBuffer[255];
	TCHAR characterNameBuffer[255];
	UINT initialPosWidth;
	UINT initialPosHeight;

	GetPrivateProfileString(L"PLAYER_SPRITE", L"PLAYER_PLIST", L"", plistNameBuffer, 255, L"test.ini" );
	GetPrivateProfileString(L"PLAYER_SPRITE", L"PLAYER_SPRITE", L"", characterNameBuffer, 255, L"test.ini");
	initialPosWidth = GetPrivateProfileInt(L"PLAYER_CONST", L"INIT_WIDTH", 0, L"test.ini");
	initialPosHeight = GetPrivateProfileInt(L"PLAYER_CONST", L"INIT_HEIGHT", 0, L"test.ini");

	char plistName[255];
	char initSpriteName[255];

	WideCharToMultiByte(CP_ACP, 0, plistNameBuffer, 255, plistName, 255, NULL, NULL);
	WideCharToMultiByte(CP_ACP, 0, characterNameBuffer, 255, initSpriteName, 255, NULL, NULL);

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistName);
	m_pCharacter = Sprite::createWithSpriteFrameName(initSpriteName);
	m_pCharacter->setPosition(Point(initialPosWidth, initialPosHeight));
	addChild(m_pCharacter);

	// 키보드 입력 설정.
	auto keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	keylistener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(keylistener, 2);

	// Schedule update;
	scheduleUpdate();

	return true;

}


void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event)
{

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		setPlayerDirectionX(DIRECTION::RIGHT);
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		setPlayerDirectionX(DIRECTION::LEFT);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		setPlayerDirectionY(DIRECTION::UP);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		setPlayerDirectionY(DIRECTION::DOWN);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		setIsAttacking(true);
		break;

	}

	return;
}


void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event *event)
{

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		setPlayerDirectionX(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		setPlayerDirectionX(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		setPlayerDirectionY(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		setPlayerDirectionY(DIRECTION::NONE);
		break;
	case EventKeyboard::KeyCode::KEY_A:
		setIsAttacking(false);
		break;
	}

	return;
}


void Player::move(float dt)
{
	float dtX = getPlayerDirectionX() * PIXEL_PER_SEC * dt;
	float dtY = getPlayerDirectionY() * PIXEL_PER_SEC * dt;

	auto currentX = m_pCharacter->getPositionX();
	auto currentY = m_pCharacter->getPositionY();

	m_pCharacter->setPosition(currentX + dtX, currentY + dtY);
	setPlayerPosition(m_pCharacter->getPosition());
	return;
}
