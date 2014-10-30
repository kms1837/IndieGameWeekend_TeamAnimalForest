#ifndef ReadyMenu_h__
#define ReadyMenu_h__

#include "cocos2d.h"

#include "RegionMenu.h"
#include "HeroMenu.h"

class ReadyMenu
{
public:
	ReadyMenu(RegionInfo &regionInfo, HeroInfo &heroInfo);
	~ReadyMenu();
	cocos2d::Layer *getLayer() const { return _layer; }

private:
	cocos2d::LayerColor *_layer;
	RegionMenu *_regionMenu;
	HeroMenu *_heroMenu;
	RegionInfo _regionInfo;
	HeroInfo _heroInfo;
};

#endif // ReadyMenu_h__
