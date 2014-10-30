#include "GameScene.h"

#include "Hero.h"
#include "GameJesture.h"
#include "GameMap.h"
#include "Logo.h"
#include "CollisionDetector.h"
#include "GameUiLayer.h"

USING_NS_CC;

GameScene::GameScene()
{
	
}

GameScene::~GameScene()
{
	_gameMap->release();
	delete _jesture;
	delete _hero;
	_collisionDetector->release();
	_obstacleLayer->release();
	delete _uiLayer;
}

GameScene* GameScene::create(RegionInfo &regionInfo, HeroInfo &heroInfo)
{
	// 'scene' is an autorelease object
	GameScene *gameScene = new GameScene();
	if (gameScene && gameScene->init()){
		gameScene->autorelease();
		return gameScene;
	}

	CC_SAFE_DELETE(gameScene);
	return nullptr;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_jesture = new GameJesture();
	_jesture->registerEventListener();

	_gameMap = new GameMap(_regionInfo);
	_gameMap->retain();

	_gameMap->registerEventListener();

	addChild(_gameMap->getBackground());

	_hero = new Hero(_heroInfo);
	_hero->registerEventListener();
	addChild(_hero->getHeroSprite());

	addChild(_gameMap->getForeground());

	_collisionDetector = new CollisionDetector();
	_collisionDetector->setHero(_hero);

	_obstacleLayer = new ObstacleLayer(_collisionDetector);
	_obstacleLayer->loadFromJson("Stage1.json");
	_obstacleLayer->registerEventListener();

	addChild(_obstacleLayer->getLayer());

	_uiLayer = new GameUiLayer();
	addChild(_uiLayer->getLayer());
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/InGameBGM.mp3");

	return true;
}
