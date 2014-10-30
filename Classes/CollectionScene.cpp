#include "CollectionScene.h"
#include "ResultLayer.h"
#include "PauseLayer.h"
#include "MapScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

CollectionScene::CollectionScene()
{
    
}

CollectionScene::~CollectionScene()
{
    
}

bool CollectionScene::init()
{
    cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    nodeLoaderLibrary->registerNodeLoader("CollectionScene", CollectionSceneBuilderLoader::loader());
    cocosbuilder::CCBReader* ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    auto node = ccbReader->readNodeGraphFromFile("CollectionScene.ccbi");
    addChild(node);
    
    /*
    cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary2 = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    nodeLoaderLibrary2->registerNodeLoader("ResultLayer", ResultLayerBuilderLoader::loader());
    cocosbuilder::CCBReader* ccbReader2 = new cocosbuilder::CCBReader(nodeLoaderLibrary2);
    auto node2 = ccbReader2->readNodeGraphFromFile("ResultLayer.ccbi");
    addChild(node2);
    
    cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary3 = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    nodeLoaderLibrary3->registerNodeLoader("PauseLayer", PauseLayerBuilderLoader::loader());
    cocosbuilder::CCBReader* ccbReader3 = new cocosbuilder::CCBReader(nodeLoaderLibrary3);
    auto node3 = ccbReader3->readNodeGraphFromFile("PauseLayer.ccbi", this);
    addChild(node3, 4);
    */
    
    MenuItem* backButton = MenuItemSprite::create(Sprite::create("UIResources/Collection_botton.png"), Sprite::create("UIResources/Collection_botton2.png"), Sprite::create("UIResources/Collection_botton2.png"), CC_CALLBACK_1(CollectionScene::menuTouchCallBack, this) );
    
    Menu* menu = Menu::create(backButton, nullptr);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(1105.0f, 662.0f));
    addChild(menu);
    
    MenuItem* character1 = MenuItemImage::create("character/original_1.png", "UIResources/original_1.png", CC_CALLBACK_1(CollectionScene::characterSelecteCallBack, this));
    MenuItem* character2 = MenuItemImage::create("character/collecsion_rhinoceros_1.png", "UIResources/collecsion_rhinoceros_1.png", CC_CALLBACK_1(CollectionScene::characterSelecteCallBack, this));
    MenuItem* character3 = MenuItemImage::create("character/collecsion_penguin_1.png", "character/collecsion_penguin_1.png", CC_CALLBACK_1(CollectionScene::characterSelecteCallBack, this));
    character1->setTag(1);
    character2->setTag(2);
    character3->setTag(3);
    
    Menu* characterSelecteMenu = Menu::create(character1, character2, character3, nullptr);
    characterSelecteMenu->alignItemsHorizontally();
    characterSelecteMenu->setPosition(Vec2(350.0f, 270.0f));
    characterSelecteMenu->setScale(0.45f);
    
    character2->setPositionX(160.0f);
    character3->setPositionX(600.0f);
    characterSelecteMenu->setOpacity(0);
    addChild(characterSelecteMenu);
    
    Sprite* selectedCharacter = Sprite::create("character/original_1.png");
    selectedCharacter->setPosition(Vec2(250.0f, 330.0f));
    selectedCharacter->setName("selectedCharacter");
    selectedCharacter->setOpacity(0);
    addChild(selectedCharacter);
    
    characterSelecteMenu->runAction(Sequence::create(DelayTime::create(1.0f), FadeIn::create(0.3f), nullptr));
    selectedCharacter->runAction(Sequence::create(DelayTime::create(1.0f), FadeIn::create(0.3f), nullptr));

    
    return true;
}

Scene* CollectionScene::createScene()
{
    CollectionScene* scene = new CollectionScene();
    if (scene && scene->init()) {
        scene->autorelease();
        return (Scene*)scene;
    }
    CC_SAFE_DELETE(scene);
    
    return nullptr;
}

void CollectionScene::menuTouchCallBack(cocos2d::CCObject *pSender)
{
    MapScene *gameScene = MapScene::create();
    Director* director = Director::getInstance();
    director->replaceScene(gameScene);
}

void CollectionScene::characterSelecteCallBack(cocos2d::CCObject *pSender)
{
    CCMenuItem* pMenuItem = (CCMenuItem *)pSender;
    Sprite* selectedCharacter = (Sprite *)this->getChildByName("selectedCharacter");
    Sprite* effectSprite = Sprite::createWithTexture(selectedCharacter->getTexture());
    
    effectSprite->setPosition(selectedCharacter->getPosition());
    
    CallFunc* actionToDelete = CallFunc::create([&] (){
        removeChild(effectSprite);
    });

    
    switch (pMenuItem->getTag()) {
        case 1:
            selectedCharacter->setTexture("character/original_1.png");
            break;
        case 2:
            selectedCharacter->setTexture("character/collecsion_rhinoceros_1.png");
            break;
        case 3:
            selectedCharacter->setTexture("character/collecsion_penguin_1.png");
            break;
    }
    
    addChild(effectSprite);
    
    selectedCharacter->setOpacity(0);
    effectSprite->setOpacity(255);
    
    selectedCharacter->runAction(FadeIn::create(0.3f));
    effectSprite->runAction(Sequence::create(FadeOut::create(0.3f), actionToDelete, NULL));
}

SEL_MenuHandler CollectionScene::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    CCLOG("%s", pSelectorName);
    // CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "startButton", GameMainScene::startButton);
    // CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "creditButton", GameMainScene::creditButton);
    
    return NULL;
}

Control::Handler CollectionScene::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool CollectionScene::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node)
{
    return false;
}

bool CollectionScene::onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
    return false;
}

void CollectionScene::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{
    CCLOG("로드완료");
}
