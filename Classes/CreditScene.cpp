#include "CreditScene.h"
#include "MainMenuScene.h"

USING_NS_CC;

bool CreditScene::init()
{
    if ( !Layer::init() ) return false;
    
    Sprite* creditImage = Sprite::create("credit.png");
    creditImage->setPosition(Vec2(640.0f, 360.0f));
    addChild(creditImage);
    
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(CreditScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

Scene* CreditScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = CreditScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool CreditScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event)
{
    Director *director = Director::getInstance();
    director->replaceScene(TransitionFade::create(1.0f, MainMenuScene::createScene()));

    return true;
}