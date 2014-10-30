#ifndef MapScene_h__
#define MapScene_h__

#include "cocos2d.h"

class ReadyMenu;

class MapScene :
	public cocos2d::Scene
{
public:
	MapScene();
	~MapScene();
	static MapScene *create();
	virtual bool init() override;

private:
private:
	ReadyMenu *_readyMenu;
};

#endif // MapScene_h__
