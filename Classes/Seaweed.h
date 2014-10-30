#ifndef __ProtoType__Seaweed__
#define __ProtoType__Seaweed__

#include "cocos2d.h"

#include "Collidable.h"

class Seaweed :
	public Collidable
{
public:
	Seaweed();
	~Seaweed();
	cocos2d::Sprite *createSeaweed();

public:
	virtual cocos2d::Rect getCollidableRect() const override;
	virtual void collide(CollideState state);

private:
	void setPattern(cocos2d::Sprite *seaweed);
	cocos2d::Sprite *_body;
};

#endif
