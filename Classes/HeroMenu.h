#ifndef HeroMenu_h__
#define HeroMenu_h__

#include "cocos2d.h"

#include "HeroInfo.h"

class HeroMenu
{
public:
	HeroMenu(const HeroInfo &heroInfo);
	~HeroMenu();
	cocos2d::Layer *getLayer() const { return _layer; }

private:
	cocos2d::Layer *_layer;
	HeroInfo _heroInfo;

};

#endif // HeroMenu_h__
