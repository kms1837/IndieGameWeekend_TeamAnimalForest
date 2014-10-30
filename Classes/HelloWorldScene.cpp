#include "HelloWorldScene.h"

#include "Hero.h"
#include "InfiniteParallaxNode.h"
#include "GameJesture.h"
#include "GameMap.h"
#include "Logo.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

HelloWorld::HelloWorld()
{

}

HelloWorld::~HelloWorld()
{
	_gameMap->release();
	delete _jesture;
	delete _hero;
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//_jesture = new GameJesture();
	//_jesture->registerEventListener();

	//_gameMap = new GameMap();
	//_gameMap->retain();

	//_gameMap->registerEventListener();

	//addChild(_gameMap->getBackground());
	//addChild(_gameMap->getForeground());

	//_hero = new Hero();
	//_hero->registerEventListener();
	//addChild(_hero->getHeroSprite());

	//cocostudio::GUIReader *reader = cocostudio::GUIReader::getInstance();

	//ui::Widget *widget = reader->widgetFromJsonFile("gameMainTest_1\gameMainTest_1.ExportJson");

	//cocostudio::SceneReader *sceneReader = cocostudio::SceneReader::getInstance();
	//Node *node = sceneReader->createNodeWithSceneFile("test\\DemoHead_UI\\DemoHead_UI.json");
	//this->addChild(node);

	

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
