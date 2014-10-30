#include "HeroMenu.h"

using namespace cocos2d;

HeroMenu::HeroMenu(const HeroInfo &heroInfo) :
_layer(nullptr),
_heroInfo(heroInfo)
{
	_layer = Layer::create();
	_layer->setPosition(Vec2(960.0f, 360.0f));
	_layer->retain();

	Sprite *region = Sprite::create("collecsion_rhinoceros_1.png");
	_layer->addChild(region);
}

HeroMenu::~HeroMenu()
{
	_layer->release();
}

