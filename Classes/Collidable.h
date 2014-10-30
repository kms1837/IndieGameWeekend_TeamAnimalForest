#ifndef Collidable_h__
#define Collidable_h__

#include "cocos2d.h"


class Collidable
{
public:
	enum CollideState
	{
		Success = 0,
		Fail
	};
public:
	virtual cocos2d::Rect getCollidableRect() const = 0;
	virtual void collide(CollideState state) = 0;

};

#endif // Collidable_h__
