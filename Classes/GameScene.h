#ifndef GameScene_h__
#define GameScene_h__

#include "cocos2d.h"

#include "RegionInfo.h"
#include "HeroInfo.h"
#include "ObstacleLayer.h"

class CollisionDetector;
class Hero;
class GameJesture;
class GameMap;
class GameUiLayer;

class GameScene : 
	public cocos2d::Scene
{
public:
	GameScene();
	~GameScene();

	static GameScene *create(RegionInfo &regionInfo, HeroInfo &heroInfo);

	virtual bool init();

private:
	Hero *_hero;
	GameJesture *_jesture;
	GameMap *_gameMap;
	CollisionDetector *_collisionDetector;
	HeroInfo _heroInfo;
	RegionInfo _regionInfo;
	ObstacleLayer *_obstacleLayer;
	GameUiLayer *_uiLayer;
	
};

#endif // GameScene_h__