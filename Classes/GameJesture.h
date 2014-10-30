#ifndef GameJesture_h__
#define GameJesture_h__

#include "cocos2d.h"

class GameJesture
{
public:
	GameJesture();
	~GameJesture();
	void registerEventListener();
	void unregisterEvent();

private:


private:
	cocos2d::EventListenerKeyboard *_keyboardEventListener;
};

#endif // GameJesture_h__
