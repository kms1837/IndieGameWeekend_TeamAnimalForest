#include "ObstacleLayer.h"

#include "JsonParser.h"
#include "CollisionDetector.h"

using namespace cocos2d;

ObstacleLayer::ObstacleLayer(CollisionDetector *collisionDetector) :
_layer(nullptr),
_eventListeners(),
_velocity(0),
_obstacleVector(),
_obstacles(),
_penguin(nullptr),
_seagull(nullptr),
_crap(nullptr),
_collisionDetector(collisionDetector)
{
	_layer = Layer::create();
	_layer->retain();

	Director *director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->schedule(schedule_selector(ObstacleLayer::update), this, 0.0f, false);
}

ObstacleLayer::~ObstacleLayer()
{
	_layer->release();
	delete _penguin;
	Director *director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->unschedule(schedule_selector(ObstacleLayer::update), this);
}

void ObstacleLayer::loadFromJson(const std::string &filePath)
{
	JsonParser::getObstaclesFromFile(filePath, &_obstacles);
}

void ObstacleLayer::generatePenguin(Penguin::Pattern pattern, float positionX)
{
	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();
	Vec2 position = _layer->convertToNodeSpace(Vec2(winSize.width + positionX, 200.0f));
	Penguin *penguin = new Penguin();
	Sprite *body = penguin->createPenguin(pattern);
	_collisionDetector->addObstacles(penguin);
	_obstacleVector.push_back(body);
	body->setPosition(position);
	_layer->addChild(body);
}

void ObstacleLayer::generateSeagull(float positionX)
{
	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();
	Vec2 position = _layer->convertToNodeSpace(Vec2(winSize.width + positionX, 640.0f));
	Seagull *seagull = new Seagull();
	_collisionDetector->addObstacles(seagull);
	Sprite *body = seagull->createSeagull();
	_obstacleVector.push_back(body);
	body->setPosition(position);
	_layer->addChild(body);
}

void ObstacleLayer::generateCrap(float positionX)
{
	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();
	Vec2 position = _layer->convertToNodeSpace(Vec2(-100.0f, 200.0f));
	Crap *crap = new Crap();
	_collisionDetector->addObstacles(crap);
	Sprite *body = crap->createCrap();
	_obstacleVector.push_back(body);
	body->setPosition(position);
	_layer->addChild(body);
}

void ObstacleLayer::generateSeaweed(float positionX)
{
	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();
	Vec2 position = _layer->convertToNodeSpace(Vec2(winSize.width + positionX, 200.0f));
	Seaweed *seaweed = new Seaweed();
	_collisionDetector->addObstacles(seaweed);
	Sprite *body = seaweed->createSeaweed();
	_obstacleVector.push_back(body);
	body->setPosition(position);
	_layer->addChild(body);
}

void ObstacleLayer::generateRock(float positionX)
{
	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();
	Vec2 position = _layer->convertToNodeSpace(Vec2(winSize.width + positionX, 200.0f));
	Rock *rock = new Rock();
	_collisionDetector->addObstacles(rock);
	Sprite *body = rock->createRock();
	_obstacleVector.push_back(body);
	body->setPosition(position);
	_layer->addChild(body);
}

void ObstacleLayer::registerEventListener()
{
	Director *director = Director::getInstance();
	EventDispatcher *eventDispatcher = director->getEventDispatcher();

	EventListenerCustom *eventListener = EventListenerCustom::create("left", CC_CALLBACK_1(ObstacleLayer::onLeft, this));
	eventDispatcher->addEventListenerWithFixedPriority(eventListener, 1);
	_eventListeners.push_back(eventListener);

	eventListener = EventListenerCustom::create("right", CC_CALLBACK_1(ObstacleLayer::onRight, this));
	eventDispatcher->addEventListenerWithFixedPriority(eventListener, 1);
	_eventListeners.push_back(eventListener);
}

void ObstacleLayer::unregisterEventListener()
{
	Director *director = Director::getInstance();
	EventDispatcher *eventDispatcher = director->getEventDispatcher();

	for (EventListenerCustom *eventListener : _eventListeners) {
		eventDispatcher->removeEventListener(eventListener);
	}
	_eventListeners.clear();
}

void ObstacleLayer::onLeft(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
	if (-3 < _velocity) {
		_velocity--;
	}

}

void ObstacleLayer::onRight(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
	if (_velocity < 3) {
		_velocity++;
	}
}

void ObstacleLayer::update(float dt)
{
	Vec2 layerPosition = _layer->getPosition();
	_layer->setPosition(Vec2(layerPosition.x + (-8.0f * _velocity), layerPosition.y));

	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();
	for (auto it = _obstacles.begin(); it != _obstacles.end(); ++it) {
		Obstacle obstacle = *it;
		Vec2 position(winSize.width / 2, 0.0f);
		position = _layer->convertToNodeSpace(position);
		if (obstacle.sensorPositionX <= position.x) {
			generateObstacles(obstacle.kinds);
			_obstacles.erase(it);
			return;
		}
	}
}

void ObstacleLayer::generateObstacles(std::vector<Kind> &kinds)
{
	for (Kind &kind : kinds) {
		if (kind.name == "Penguin1") {
			generatePenguin(Penguin::Pattern1, kind.positionX);
		}
		else if (kind.name == "Penguin2") {
			generatePenguin(Penguin::Pattern2, kind.positionX);
		}
		else if (kind.name == "Penguin3") {
			generatePenguin(Penguin::Pattern3, kind.positionX);
		}
		else if (kind.name == "Penguin4") {
			generatePenguin(Penguin::Pattern4, kind.positionX);
		}
		else if (kind.name == "Penguin5") {
			generatePenguin(Penguin::Pattern5, kind.positionX);
		}
		else if (kind.name == "Seaweed") {
			generateSeaweed(kind.positionX);
		}
		else if (kind.name == "Rock") {
			generateRock(kind.positionX);
		}
		else if (kind.name == "Seagull") {
			generateSeagull(kind.positionX);
		}
	}
}
