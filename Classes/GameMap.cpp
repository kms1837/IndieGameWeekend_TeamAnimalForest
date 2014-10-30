#include "GameMap.h"

using namespace cocos2d;

GameMap::GameMap() :
_backLayer(nullptr),
_foreLayer(nullptr),
_eventListeners()
{
}

GameMap::~GameMap()
{
}

void GameMap::registerEventListener()
{
	Director *director = Director::getInstance();
	EventDispatcher *eventDispatcher = director->getEventDispatcher();

	EventListenerCustom *eventListener = EventListenerCustom::create("left", CC_CALLBACK_1(GameMap::onLeft, this));
	eventDispatcher->addEventListenerWithFixedPriority(eventListener, 1);
	_eventListeners.push_back(eventListener);

	eventListener = EventListenerCustom::create("right", CC_CALLBACK_1(GameMap::onRight, this));
	eventDispatcher->addEventListenerWithFixedPriority(eventListener, 1);
	_eventListeners.push_back(eventListener);

	eventListener = EventListenerCustom::create("jump", CC_CALLBACK_1(GameMap::onJump, this));
	eventDispatcher->addEventListenerWithFixedPriority(eventListener, 1);
	_eventListeners.push_back(eventListener);

	eventListener = EventListenerCustom::create("slide", CC_CALLBACK_1(GameMap::onSlide, this));
	eventDispatcher->addEventListenerWithFixedPriority(eventListener, 1);
	_eventListeners.push_back(eventListener);
}

void GameMap::unregisterEventListener()
{
	Director *director = Director::getInstance();
	EventDispatcher *eventDispatcher = director->getEventDispatcher();

	for (EventListenerCustom *eventListener : _eventListeners) {
		eventDispatcher->removeEventListener(eventListener);
	}
	_eventListeners.clear();
}

void GameMap::onLeft(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
}

void GameMap::onRight(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
}

void GameMap::onJump(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
}

void GameMap::onSlide(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
}
