#include "Logo.h"

#include "MainMenuScene.h"

using namespace cocos2d;

Logo::Logo()
{
	_layer = Layer::create();
	addChild(_layer);

	Sprite *topLogo = Sprite::create("Top_logo.png");
	topLogo->setPosition(Vec2(640.0f, 660.0f));
	topLogo->setOpacity(0);
	topLogo->runAction(
		Sequence::create(
		DelayTime::create(1.0f),
		FadeIn::create(0.0f),
		nullptr));
	_layer->addChild(topLogo);

	Sprite *midLogo = Sprite::create("Middle_logo.png");
	midLogo->setPosition(Vec2(640.0f, 580.0f));
	midLogo->setOpacity(0);
	midLogo->runAction(
		Sequence::create(
		DelayTime::create(1.5f),
		FadeIn::create(0.0f),
		nullptr));
	_layer->addChild(midLogo);

	Sprite *bottomLogo = Sprite::create("Bottom_logo.png");
	bottomLogo->setPosition(Vec2(640.0f, 320.0f));
	bottomLogo->setOpacity(0);
	bottomLogo->runAction(
		Sequence::create(
		DelayTime::create(2.0f),
		FadeIn::create(0.0f),
		nullptr));
	_layer->addChild(bottomLogo);

	Sprite *treeLogo = Sprite::create("Tree_logo.png");
	treeLogo->setPosition(Vec2(640.0f, 200.0f));
	treeLogo->setOpacity(0);
	treeLogo->runAction(
		Sequence::create(
		DelayTime::create(2.5f),
		FadeIn::create(0.0f),
		Blink::create(2.0f, 4),
		nullptr));
	_layer->addChild(treeLogo);
	
	Director *director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->schedule(schedule_selector(Logo::update), this, 0.0f, false);
}

Logo::~Logo()
{
}

Logo * Logo::create()
{
	Logo *logo = new Logo();
	if (logo && logo->init()) {
		logo->autorelease();
		return logo;
	}
	return nullptr;
}

bool Logo::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}
	return true;
}

void Logo::update(float dt)
{
	static float time = 0.0f;
	time += dt;
	if (5.0f < time) {
		time = 0.0f;
		Director *director = Director::getInstance();
		Scheduler *scheduler = director->getScheduler();
		scheduler->unschedule(schedule_selector(Logo::update), this);
		
        CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sound/TitleBGM.mp3", true);
        
		MainMenuScene *scene = MainMenuScene::create();
        
		director->replaceScene(TransitionFade::create(1.0f, scene->createScene()));
	}
}
