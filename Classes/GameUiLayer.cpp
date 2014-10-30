#include "GameUiLayer.h"

#include "PauseLayer.h"
#include "MapScene.h"

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
	};
	MenuItemSprite *pauseMenuItem = MenuItemSprite::create(pauseNormal, pauseSelected, onPauseTouched);
	Menu *menu = Menu::create(pauseMenuItem, nullptr);
	menu->setPosition(Vec2(100, 620));
	_layer->addChild(menu);
}

GameUiLayer::~GameUiLayer()
{
	_layer->release();
}

