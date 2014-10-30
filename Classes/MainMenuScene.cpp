#include "MainMenuScene.h"
#include "MapScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
    
}

bool MainMenuScene::init()
{
    cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    nodeLoaderLibrary->registerNodeLoader("GameMainBuilderLayer", GameMainBuilderLoader::loader());
    cocosbuilder::CCBReader* ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    auto node = ccbReader->readNodeGraphFromFile("MainMenuScene.ccbi");
    addChild(node);
    
    auto startItem = MenuItemSprite::create(Sprite::create("UIResources/Start.png"), Sprite::create("UIResources/Start_2.png"), Sprite::create("UIResources/Start.png"), CC_CALLBACK_1(MainMenuScene::menuTouchCallBack, this) );
    startItem->setTag(1);
    auto creditItem = MenuItemSprite::create(Sprite::create("UIResources/Credit.png"), Sprite::create("UIResources/Credit_2.png"), Sprite::create("UIResources/Credit.png"), CC_CALLBACK_1(MainMenuScene::menuTouchCallBack, this) );
    creditItem->setTag(2);
    Menu* menu = Menu::create( startItem, creditItem, nullptr);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(640.0f, 230.0f));
    
    addChild(menu);
    
    CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/TitleBGM.mp3", true);
    
    return true;
}

Scene* MainMenuScene::createScene()
{
    MainMenuScene* scene = new MainMenuScene();
    if (scene && scene->init()) {
        scene->autorelease();
        return (Scene*)scene;
    }
    CC_SAFE_DELETE(scene);
    
    return nullptr;
}

void MainMenuScene::menuTouchCallBack(cocos2d::CCObject *pSender)
{
    CCMenuItem* pMenuItem = (CCMenuItem *)pSender;
    
    Director *director = Director::getInstance();
    
    switch (pMenuItem->getTag()) {
        case 1: {
			MapScene *gameScene = MapScene::create();
            director->replaceScene(gameScene);
            break;
        }
        case 2:{
            break;
        }
    }
}

SEL_MenuHandler MainMenuScene::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    CCLOG("%s", pSelectorName);
   // CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "startButton", MainMenuScene::startButton);
   // CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "creditButton", MainMenuScene::creditButton);
    
    return NULL;
}

Control::Handler MainMenuScene::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool MainMenuScene::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node)
{
    return false;
}

bool MainMenuScene::onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
    return false;
}

void MainMenuScene::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{
    CCLOG("로드완료");
}

