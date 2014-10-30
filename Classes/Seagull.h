#ifndef __ProtoType__Seagull__
#define __ProtoType__Seagull__

#include "cocos2d.h"

#include "Collidable.h"

class Seagull :
	public Collidable
{
public:
	Seagull();
	~Seagull();
	cocos2d::Sprite *createSeagull();

public:
	virtual cocos2d::Rect getCollidableRect() const override;
	virtual void collide(CollideState state);

private:
	void setPattern(cocos2d::Sprite *_body);
	cocos2d::Sprite *_body;
};

#endif
