#ifndef ObstacleLayer_h__
#define ObstacleLayer_h__

#include "cocos2d.h"

#include "Penguin.h"
#include "Obstacle.h"
#include "Seagull.h"
#include "Crap.h"
#include "Seaweed.h"
#include "Rock.h"

class CollisionDetector;

class ObstacleLayer :
	public cocos2d::Ref
{
public:
	ObstacleLayer(CollisionDetector *collisionDetector);
	~ObstacleLayer();
	cocos2d::Layer *getLayer() const { return _layer; }
	void loadFromJson(const std::string &filePath);
	void registerEventListener();
	void unregisterEventListener();
	void onLeft(cocos2d::EventCustom* event);
	void onRight(cocos2d::EventCustom* event);
	void generatePenguin(Penguin::Pattern pattern, float positionX);
	void generateSeagull(float positionX);
	void generateCrap(float positionX);
	void generateSeaweed(float positionX);
	void generateRock(float positionX);
	void generateObstacles(std::vector<Kind> &kinds);

private:
	void update(float dt);

private:
	cocos2d::Layer *_layer;
	std::vector<cocos2d::EventListenerCustom *> _eventListeners;
	int _velocity;
	Penguin *_penguin;
	Seagull *_seagull;
	Crap *_crap;
	Seaweed *_seaweed;
	Rock *_rock;
	std::vector<cocos2d::Sprite *> _obstacleVector;
	Obstacles _obstacles;
	CollisionDetector *_collisionDetector;
};

#endif // ObstacleLayer_h__
