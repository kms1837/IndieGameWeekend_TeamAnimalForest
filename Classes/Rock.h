#ifndef __ProtoType__Rock__
#define __ProtoType__Rock__

#include "cocos2d.h"

#include "Collidable.h"

class Rock :
	public Collidable
{
public:
	Rock();
	~Rock();
	cocos2d::Sprite *createRock();

public:
	virtual cocos2d::Rect getCollidableRect() const override;
	virtual void collide(CollideState state);

private:
	void setPattern(cocos2d::Sprite *rock);
	cocos2d::Sprite *_body;
};

#endif
