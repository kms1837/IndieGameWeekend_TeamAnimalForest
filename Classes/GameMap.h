#ifndef GameMap_h__
#define GameMap_h__

#include "cocos2d.h"

class GameMap
{
public:
	GameMap();
	~GameMap();
	void registerEventListener();
	void unregisterEventListener();
	cocos2d::ParallaxNode *getBackLayer() const { return _backLayer; }
	cocos2d::Layer *getForeLayer() const { return _foreLayer; }

private:
	void onLeft(cocos2d::EventCustom* event);
	void onRight(cocos2d::EventCustom* event);
	void onJump(cocos2d::EventCustom* event);
	void onSlide(cocos2d::EventCustom* event);

	cocos2d::ParallaxNode *_backLayer;
	cocos2d::Layer *_foreLayer;
	std::vector<cocos2d::EventListenerCustom *> _eventListeners;
};

#endif // GameMap_h__
