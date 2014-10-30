#ifndef Logo_h__
#define Logo_h__

#include "cocos2d.h"

class Logo :
	public cocos2d::Scene
{
public:
	Logo();
	~Logo();
	static Logo *create();
	virtual bool init() override;

private:
	void update(float dt);

private:
	cocos2d::Layer *_layer;
};

#endif // Logo_h__
