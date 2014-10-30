#ifndef GameMap_h__
#define GameMap_h__

#include "cocos2d.h"

#include "RegionInfo.h"
#include "Obstacle.h"

class InfiniteParallaxNode;

class GameMap :
	public cocos2d::Ref
{
public:
	GameMap(const RegionInfo &regionInfo);
	~GameMap();
	void registerEventListener();
	void unregisterEventListener();
	void loadFromJson();
	cocos2d::Layer *getBackground() const { return _background; }
	cocos2d::Layer *getForeground() const { return _foreground; }

private:
	float getMinWorldPositionXOfChildren(cocos2d::Layer *layer) const;
	float getMaxWorldPositionXOfChildren(cocos2d::Layer *layer) const;
	void setInfiniteBackground(cocos2d::Layer *layer, const std::string &fileName);
	void onLeft(cocos2d::EventCustom* event);
	void onRight(cocos2d::EventCustom* event);
	void onJump(cocos2d::EventCustom* event);
	void onSlide(cocos2d::EventCustom* event);
	void update(float dt);

private:
	float _velocity;
	cocos2d::Layer *_background;
	cocos2d::Layer *_background1;
	cocos2d::Layer *_background2;
	cocos2d::Layer *_background3;
	cocos2d::Layer *_background4;
	cocos2d::Layer *_background5;
	cocos2d::Layer *_foreground;
	std::vector<cocos2d::EventListenerCustom *> _eventListeners;
	RegionInfo _regionInfo;
	Obstacles _obstacles;
};

#endif // GameMap_h__
