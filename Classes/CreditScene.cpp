#include "CreditScene.h"

USING_NS_CC;

bool CreditScene::init()
{
    if ( !Layer::init() ) return false;
    
    Sprite* creditImage = Sprite::create("credit.png");
    creditImage->setPosition(Vec2(640.0f, 360.0f));
    addChild(creditImage);
    
    return true;
}

Scene* CreditScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = CreditScene::create();
    scene->addChild(layer);

    return scene;
}

