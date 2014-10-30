#include "GameMainScene.h"


USING_NS_CC;
USING_NS_CC_EXT;

GameMainScene::GameMainScene()
{
}

GameMainScene::~GameMainScene()
{
    
}

Scene* GameMainScene::createScene()
{
    cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    nodeLoaderLibrary->registerNodeLoader("GameMainBuilderLayer", GameMainBuilderLoader::loader());
    cocosbuilder::CCBReader* ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    
    auto node = ccbReader->readNodeGraphFromFile("MainMenuScene.ccbi");
    auto scene = (Scene*)node;
    
    return scene;
}

SEL_MenuHandler GameMainScene::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    CCLOG("%s", pSelectorName);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "startButton", GameMainScene::startButton);
    CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "creditButton", GameMainScene::creditButton);
    
    return NULL;
}

void GameMainScene::startButton(CCObject *pSender)
{
    CCLOG("Start");
}

void GameMainScene::creditButton(CCObject *pSender)
{
    CCLOG("credit");
}

Control::Handler GameMainScene::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool GameMainScene::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node)
{
    return false;
}

bool GameMainScene::onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
    return false;
}

void GameMainScene::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{
    CCLOG("로드완료");
}

