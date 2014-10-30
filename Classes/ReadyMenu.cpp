#include "ReadyMenu.h"
#include "ReadyMenuLayer.h"
#include "CollectionScene.h"

#include "GameScene.h"

using namespace cocos2d;

ReadyMenu::ReadyMenu(RegionInfo &regionInfo, HeroInfo &heroInfo) :
_layer(nullptr),
_regionMenu(nullptr),
_heroMenu(nullptr)
{
	_layer = LayerColor::create(Color4B(0, 0, 0, 160));
	_layer->retain();
    
    cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
    nodeLoaderLibrary->registerNodeLoader("ReadyMenuLayer", ReadyMenuLayerBuilderLoader::loader());
    cocosbuilder::CCBReader* ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
    auto node = ccbReader->readNodeGraphFromFile("ReadyMenuLayer.ccbi");
    _layer->addChild(node);
    
    /*
	_regionMenu = new RegionMenu(regionInfo);
	_heroMenu = new HeroMenu(heroInfo);

	_regionInfo = regionInfo;
	_heroInfo = heroInfo;

	_layer->addChild(_regionMenu->getLayer());
	_layer->addChild(_heroMenu->getLayer());
    */
    
	std::function<void(Ref *ref)>
		onStartTouched = [this](Ref *ref)
	{
		GameScene *gameScene = GameScene::create(_regionInfo, _heroInfo);
		Director *director = Director::getInstance();
		director->replaceScene(TransitionFade::create(1.0f, gameScene));
	};
    
	Menu *startMenu = Menu::create(MenuItemImage::create("UIResources/Second_UI4.png",
                                                         "UIResources/Second_UI4.png",
                                                         onStartTouched),
                                   nullptr);
    
	startMenu->setPosition(Vec2(1000.0f, 84.0f));
    startMenu->setOpacity(0);
    startMenu->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
	_layer->addChild(startMenu);
    
    Sprite* mapImage = Sprite::create("UIResources/Second_MAP.png");
    mapImage->setPosition(Vec2(640.0f, 360.0f));
    mapImage->setOpacity(0);
    mapImage->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
    _layer->addChild(mapImage);
    
    Sprite* backPicture = Sprite::create("UIResources/Second_backpicture.png");
    backPicture->setPosition(Vec2(1003.0f, 434.0f));
    backPicture->setOpacity(0);
    backPicture->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
    _layer->addChild(backPicture);
    
    Sprite* totem = Sprite::create("UIResources/Second_CLOSE.png");
    totem->setPosition(Vec2(381.0f, 404.0f));
    totem->setOpacity(0);
    totem->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
    _layer->addChild(totem);
    
    Sprite* stagePenel = Sprite::create("UIResources/Second_UI2.png");
    stagePenel->setPosition(Vec2(380.0f, 624.0f));
    stagePenel->setOpacity(0);
    stagePenel->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
    _layer->addChild(stagePenel);
    
    Sprite* buttonPenel = Sprite::create("UIResources/Second_UI5.png");
    buttonPenel->setPosition(Vec2(267.0f, 119.0f));
    buttonPenel->setOpacity(0);
    buttonPenel->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
    _layer->addChild(buttonPenel);
    
    std::function<void(Ref *ref)>
    moveCollectionScene = [this](Ref *ref)
    {
        Scene* collectionScene = CollectionScene::createScene();
        Director* director = Director::getInstance();
        director->replaceScene(collectionScene);
    };
    
    Menu* collectionMenu = Menu::create(MenuItemImage::create("UIResources/Second_UI3.png", "UIResources/Second_UI3.png", moveCollectionScene), nullptr);
    collectionMenu->setPosition(Vec2(874.0f, 234.0f));
    collectionMenu->setOpacity(0);
    collectionMenu->runAction(Sequence::create(DelayTime::create(0.5f), FadeIn::create(0.3f), nullptr));
    _layer->addChild(collectionMenu);
    
}

ReadyMenu::~ReadyMenu()
{
	_layer->release();
	delete _regionMenu;
	delete _heroMenu;
}

