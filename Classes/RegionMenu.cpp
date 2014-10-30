#include "RegionMenu.h"

using namespace cocos2d;

RegionMenu::RegionMenu(const RegionInfo &regionInfo) :
_layer(nullptr),
_regionInfo(regionInfo)
{
	_layer = Layer::create();
	_layer->setPosition(Vec2(320.0f, 360.0f));
	_layer->retain();

	Sprite *region = Sprite::create("TestRegion.png");
	_layer->addChild(region);
}

RegionMenu::~RegionMenu()
{
	_layer->release();
}

