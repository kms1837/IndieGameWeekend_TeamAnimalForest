#ifndef GameUiLayer_h__
#define GameUiLayer_h__

#include "cocos2d.h"

class GameUiLayer
{
public:
	GameUiLayer();
	~GameUiLayer();
	cocos2d::Layer *getLayer() const { return _layer; }
private:
	cocos2d::Layer *_layer;
};

#endif // GameUiLayer_h__