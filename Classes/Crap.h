#ifndef __ProtoType__Crap__
#define __ProtoType__Crap__

#include "cocos2d.h"

#include "Collidable.h"

class Crap :
	public Collidable
{
public:
	Crap();
	~Crap();
	cocos2d::Sprite *createCrap();

public:
	virtual cocos2d::Rect getCollidableRect() const override;
	virtual void collide(CollideState state);

private:
	void setPattern(cocos2d::Sprite *crap);
	cocos2d::Sprite *_body;
};

#endif
