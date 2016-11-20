#pragma once

class Player : public Sprite
{
public :
	CREATE_FUNC(Player);

	virtual bool         init();
	void 	     		 onKeyPressed(EventKeyboard::KeyCode, Event*);
	void				 onKeyReleased(EventKeyboard::KeyCode, Event*);

	void				 move(float);

	CC_SYNTHESIZE(Point, m_PlayerPosition, PlayerPosition);
	CC_SYNTHESIZE(int, m_PlayerDirectionX, PlayerDirectionX);
	CC_SYNTHESIZE(int, m_PlayerDirectiony, PlayerDirectionY);
	CC_SYNTHESIZE(bool, m_IsAttacking, IsAttacking);

private :
	Sprite*              m_pCharacter;
	Animation*		     m_pAnimation;
	Animate*			 m_pAnimate;

};