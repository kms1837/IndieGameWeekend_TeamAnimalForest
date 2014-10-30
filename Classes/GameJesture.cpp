#include "GameJesture.h"

using namespace cocos2d;

GameJesture::GameJesture() :
_keyboardEventListener(nullptr)
{

}

GameJesture::~GameJesture()
{

}

void GameJesture::registerEventListener()
{
	_keyboardEventListener = EventListenerKeyboard::create();

	std::function<void(EventKeyboard::KeyCode keyCode, Event* event)>
		onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event)
	{
		// TODO: sent custom event
		if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
			EventCustom event("slide");
			Director *director = Director::getInstance();
			EventDispatcher *eventDispatcher = director->getEventDispatcher();
			eventDispatcher->dispatchEvent(&event);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
			EventCustom event("jump");
			Director *director = Director::getInstance();
			EventDispatcher *eventDispatcher = director->getEventDispatcher();
			eventDispatcher->dispatchEvent(&event);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
			EventCustom event("right");
			Director *director = Director::getInstance();
			EventDispatcher *eventDispatcher = director->getEventDispatcher();
			eventDispatcher->dispatchEvent(&event);
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			EventCustom event("left");
			Director *director = Director::getInstance();
			EventDispatcher *eventDispatcher = director->getEventDispatcher();
			eventDispatcher->dispatchEvent(&event);
        }
	};
	_keyboardEventListener->onKeyPressed = onKeyPressed;

	Director *director = Director::getInstance();
	EventDispatcher *eventDispatcher = director->getEventDispatcher();
	eventDispatcher->addEventListenerWithFixedPriority(_keyboardEventListener, -1);
}

void GameJesture::unregisterEvent()
{
	// TODO: 
}
