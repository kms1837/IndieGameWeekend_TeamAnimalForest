#include "GameMap.h"

#include "InfiniteParallaxNode.h"
#include "Obstacle.h"
#include "JsonParser.h"

using namespace cocos2d;

const static char *BACKGROUND_1_NAME = "Stage/1/Stage1_Bubble.png";
const static char *BACKGROUND_2_NAME = "Stage/1/Stage1_Sea.png";
const static char *BACKGROUND_3_NAME = "Stage/1/Stage1_Mountain.png";
const static char *BACKGROUND_4_NAME = "Stage/1/Stage1_Cloud.png";
const static char *BACKGROUND_5_NAME = "Stage/1/Stage1_Sky.png";
const static char *FOREGROUND_NAME   = "Stage/1/Stage1_Send.png";

GameMap::GameMap(const RegionInfo &regionInfo) :
_velocity(0.0f),
_background1(nullptr),
_background2(nullptr),
_background3(nullptr),
_background4(nullptr),
_background5(nullptr),
_foreground(nullptr),
_eventListeners(),
_regionInfo(regionInfo)
{
	_background = Layer::create();
	_background->retain();

	// background1
	_background1 = Layer::create();
	_background->addChild(_background1, 5);

	Sprite *bgSprite1 = Sprite::create(BACKGROUND_1_NAME);
	bgSprite1->setAnchorPoint(Vec2::ZERO);

	_background1->addChild(bgSprite1);
	_background1->setAnchorPoint(Vec2::ZERO);
	_background1->retain();

	// background2
	_background2 = Layer::create();
	_background->addChild(_background2, 4);

	Sprite *bgSprite2 = Sprite::create(BACKGROUND_2_NAME);
	bgSprite2->setAnchorPoint(Vec2::ZERO);

	_background2->addChild(bgSprite2);
	_background2->setAnchorPoint(Vec2::ZERO);
	_background2->retain();

	// background3
	_background3 = Layer::create();
	_background->addChild(_background3, 3);

	Sprite *bgSprite3 = Sprite::create(BACKGROUND_3_NAME);
	bgSprite3->setAnchorPoint(Vec2::ZERO);

	_background3->addChild(bgSprite3);
	_background3->setAnchorPoint(Vec2::ZERO);
	_background3->retain();

	// background4
	_background4 = Layer::create();
	_background->addChild(_background4, 2);

	Sprite *bgSprite4 = Sprite::create(BACKGROUND_4_NAME);
	bgSprite4->setAnchorPoint(Vec2::ZERO);

	_background4->addChild(bgSprite4);
	_background4->setAnchorPoint(Vec2::ZERO);
	_background4->retain();

	// background5
	_background5 = Layer::create();
	_background->addChild(_background5, 1);

	Sprite *bgSprite5 = Sprite::create(BACKGROUND_5_NAME);
	bgSprite5->setAnchorPoint(Vec2::ZERO);

	_background5->addChild(bgSprite5);
	_background5->setAnchorPoint(Vec2::ZERO);
	_background5->retain();

	// foreground
	_foreground = Layer::create();
	_foreground->retain();

	Sprite *fgSprite = Sprite::create(FOREGROUND_NAME);
	fgSprite->setAnchorPoint(Vec2::ZERO);

	_foreground->addChild(fgSprite);
	_foreground->setAnchorPoint(Vec2::ZERO);
	_foreground->retain();

	Director *director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->schedule(schedule_selector(GameMap::update), this, 0.0f, false);
}

GameMap::~GameMap()
{
	_background1->release();
	_background2->release();
	_foreground->release();
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
	if (-3 < _velocity) {
		_velocity--;
	}

}

void GameMap::onRight(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
	if (_velocity < 3) {
		_velocity++;
	}
}

void GameMap::onJump(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
}

void GameMap::onSlide(cocos2d::EventCustom* event)
{
	CCLOG(__FUNCTION__);
}

void GameMap::update(float dt)
{
	Vec2 bg1PresentPosition = _background1->getPosition();
	_background1->setPosition(Vec2(bg1PresentPosition.x + (-5.0f * _velocity), bg1PresentPosition.y));

	Vec2 bg2PresentPosition = _background2->getPosition();
	_background2->setPosition(Vec2(bg2PresentPosition.x + (-4.0f * _velocity), bg2PresentPosition.y));

	Vec2 bg3PresentPosition = _background3->getPosition();
	_background3->setPosition(Vec2(bg3PresentPosition.x + (-1.0f * _velocity), bg3PresentPosition.y));

	Vec2 bg4PresentPosition = _background4->getPosition();
	_background4->setPosition(Vec2(bg4PresentPosition.x + (-0.5f * _velocity), bg4PresentPosition.y));

	//Vec2 bg5PresentPosition = _background5->getPosition();
	//_background5->setPosition(Vec2(bg5PresentPosition.x + (-1.0f * _velocity), bg5PresentPosition.y));

	Vec2 fgPresentPosition = _foreground->getPosition();
	_foreground->setPosition(Vec2(fgPresentPosition.x + (-8.0f * _velocity), fgPresentPosition.y));

	setInfiniteBackground(_background1, BACKGROUND_1_NAME);
	setInfiniteBackground(_background2, BACKGROUND_2_NAME);
	setInfiniteBackground(_background3, BACKGROUND_3_NAME);
	setInfiniteBackground(_background4, BACKGROUND_4_NAME);
	setInfiniteBackground(_background5, BACKGROUND_5_NAME);
	setInfiniteBackground(_foreground, FOREGROUND_NAME);
}

float GameMap::getMinWorldPositionXOfChildren(cocos2d::Layer *layer) const
{
	static float minPositionX = (float)INT_MAX;
	minPositionX = (float)INT_MAX;
	Vector<Node*> children = layer->getChildren();
	for (Node *child : children) {
		Vec2 position = child->convertToWorldSpace(Vec2::ZERO);
		if (position.x < minPositionX) {
			minPositionX = position.x;
		}
	}
	return minPositionX;
}

float GameMap::getMaxWorldPositionXOfChildren(cocos2d::Layer *layer) const
{
	float maxPositionX = (float)INT_MIN;
	maxPositionX = (float)INT_MIN;
	Vector<Node*> children = layer->getChildren();
	for (Node *child : children) {
		Size size = child->getContentSize();
		Vec2 position = child->convertToWorldSpace(Vec2(size.width, size.height));
		if (maxPositionX < position.x) {
			maxPositionX = position.x;
		}
	}
	return maxPositionX;
}

void GameMap::setInfiniteBackground(cocos2d::Layer *layer, const std::string &fileName)
{
	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();

	float minPositionX = getMinWorldPositionXOfChildren(layer);
	float maxPositionX = getMaxWorldPositionXOfChildren(layer);

	Node *child = layer->getChildren().at(0);
	Size childSize = child->getContentSize();
	Vec2 childPosition = child->getPosition();
	Vec2 childWorldPosition = layer->convertToWorldSpace(childPosition);

	if (0 < minPositionX) {
		Sprite *bgSprite = Sprite::create(fileName);
		bgSprite->setAnchorPoint(Vec2::ZERO);
		Vec2 worldPosition = Vec2(minPositionX - childSize.width, childWorldPosition.y);
		Vec2 position = layer->convertToNodeSpace(worldPosition);
		bgSprite->setPosition(position);
		layer->addChild(bgSprite);
	}
	if (maxPositionX < winSize.width) {
		Sprite *bgSprite = Sprite::create(fileName);
		bgSprite->setAnchorPoint(Vec2::ZERO);
		Vec2 position(maxPositionX, childPosition.y);
		position = layer->convertToNodeSpace(position);
		bgSprite->setPosition(position);
		layer->addChild(bgSprite);
	}
}
