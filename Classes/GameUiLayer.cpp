#include "GameUiLayer.h"

#include "PauseLayer.h"
#include "MapScene.h"
#include "PauseLayer.h"

using namespace cocos2d;
using namespace extension;

GameUiLayer::GameUiLayer() :
_layer(nullptr)
{
	_layer = cocos2d::Layer::create();
	_layer->retain();

	Sprite *pauseNormal = Sprite::create("GameUi/PAUSE_BOTTON.png");
	Sprite *pauseSelected = Sprite::create("GameUi/PAUSE_BOTTON.png");
	pauseSelected->setScale(1.2f);
	std::function<void(Ref *ref)>
		onPauseTouched = [this](Ref *ref)
	{
        
        Menu *pauseMenu;
        
        cocosbuilder::NodeLoaderLibrary * nodeLoaderLibrary = cocosbuilder::NodeLoaderLibrary::newDefaultNodeLoaderLibrary();
        nodeLoaderLibrary->registerNodeLoader("PauseLayer", PauseLayerBuilderLoader::loader());
        cocosbuilder::CCBReader* ccbReader = new cocosbuilder::CCBReader(nodeLoaderLibrary);
        auto node = ccbReader->readNodeGraphFromFile("PauseLayer.ccbi");
        node->setTag(3);
        _layer->addChild(node);
        
        std::function<void(Ref *ref)>
        onCont = [node, pauseMenu](Ref *ref)
        {
            Director *director = Director::getInstance();
            Scene *scene = director->getRunningScene();
            director->resume();
            node->removeFromParent();
        };
        
        std::function<void(Ref *ref)>
        onExit = [](Ref *ref)
        {
            Director *director = Director::getInstance();
            director->resume();
            director->replaceScene(MapScene::create());
        };
        
        
        MenuItemSprite *contMenuItem = MenuItemSprite::create(Sprite::create("GameUi/popup_UI.png"),
                                                              Sprite::create("GameUi/popup_UI.png"),
                                                              CC_CALLBACK_1(GameUiLayer::pauseMenuCallback, this));
        
        contMenuItem->setScale(0.8f);
        contMenuItem->setTag(1);
        
        MenuItemSprite *exitMenuItem = MenuItemSprite::create(Sprite::create("GameUi/popup_UI2.png"),
                                                              Sprite::create("GameUi/popup_UI2.png"),
                                                              CC_CALLBACK_1(GameUiLayer::pauseMenuCallback, this));
        exitMenuItem->setScale(0.8f);
        exitMenuItem->setTag(2);
        
        pauseMenu = Menu::create(contMenuItem, exitMenuItem, nullptr);
        pauseMenu->alignItemsHorizontally();
        pauseMenu->setPosition(Vec2(0.0f, 231.0f));
        pauseMenu->setOpacity(0);
        pauseMenu->runAction(Sequence::create(DelayTime::create(0.54f), FadeIn::create(0.1f), NULL));
        pauseMenu->setTag(4);
        contMenuItem->setPositionX(820.0f);
        exitMenuItem->setPositionX(524.0f);
        _layer->addChild(pauseMenu);

        /*
		Sprite *pauseBoard = Sprite::create("GameUi/popup_board3.png");
		
		Sprite *contNormal = Sprite::create("GameUi/popup_UI.png");
		contNormal->setScale(0.8);
		Sprite *contSelected = Sprite::create("GameUi/popup_UI.png");
		std::function<void(Ref *ref)> 
			onCont = [pauseBoard](Ref *ref)
		{
			Director *director = Director::getInstance();
			Scene *scene = director->getRunningScene();
			director->resume();
			pauseBoard->removeFromParent();
		};
		MenuItemSprite *contMenuItem = MenuItemSprite::create(contNormal, contSelected, onCont);
		Menu *contMenu = Menu::create(contMenuItem, nullptr);
		contMenu->setPosition(Vec2(140, 40));
		pauseBoard->addChild(contMenu);

		Sprite *exitNormal = Sprite::create("GameUi/popup_UI2.png");
		exitNormal->setScale(0.8);
		Sprite *exitSelected = Sprite::create("GameUi/popup_UI2.png");
		std::function<void(Ref *ref)>
			onExit = [](Ref *ref)
		{
			Director *director = Director::getInstance();
			director->resume();
			director->replaceScene(MapScene::create());
		};
		MenuItemSprite *exitMenuItem = MenuItemSprite::create(exitNormal, exitSelected, onExit);
		Menu *exitMenu = Menu::create(exitMenuItem, nullptr);
		exitMenu->setPosition(Vec2(490, 40));
		pauseBoard->setPosition(Vec2(640, 360));
		pauseBoard->addChild(exitMenu);
		_layer->addChild(pauseBoard);
        */
	};
	MenuItemSprite *pauseMenuItem = MenuItemSprite::create(pauseNormal, pauseSelected, onPauseTouched);
	Menu *menu = Menu::create(pauseMenuItem, nullptr);
	menu->setPosition(Vec2(100, 620));
	_layer->addChild(menu);
}

void GameUiLayer::pauseMenuCallback(Ref* pSender)
{
    CCMenuItem* pMenuItem = (CCMenuItem *)pSender;
    Director *director = Director::getInstance();

    switch (pMenuItem->getTag()) {
        case 1:{
            Director *director = Director::getInstance();
            Scene *scene = director->getRunningScene();
            director->resume();
            //_layer->removeChild(_layer->getChildByTag(4), true);
            _layer->getChildByTag(4)->removeFromParent();
            _layer->getChildByTag(3)->removeFromParent();
            CCLOG("제거");
            break;
        }
            
        case 2:{
            
            CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
            CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/MainBGM.mp3", true);
            
            director->resume();
            
            director->replaceScene(TransitionFade::create(1.0f, MapScene::create()));
            break;
        }
    }
    
}

GameUiLayer::~GameUiLayer()
{
	_layer->release();
}

