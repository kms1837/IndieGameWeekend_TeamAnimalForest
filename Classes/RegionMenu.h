#ifndef RegionMenu_h__
#define RegionMenu_h__

#include "cocos2d.h"

#include "RegionInfo.h"

class RegionMenu
{
public:
	RegionMenu(const RegionInfo &regionInfo);
	~RegionMenu();
	cocos2d::Layer *getLayer() const { return _layer; }
	
private:
	cocos2d::Layer *_layer;
	RegionInfo _regionInfo;
};

#endif // RegionMenu_h__
