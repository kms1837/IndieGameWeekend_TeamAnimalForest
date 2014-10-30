#ifndef Penguin_h__
#define Penguin_h__

#include "cocos2d.h"

#include "Collidable.h"

class Penguin :
	public Collidable
{
public:
	enum Pattern
	{
		Pattern1 = 0,
		Pattern2,
		Pattern3,
		Pattern4,
		Pattern5
	};

public:
	Penguin();
	~Penguin();
	cocos2d::Sprite *createPenguin(Pattern pattern);

private:
	void setPattern1(cocos2d::Sprite *penguin);
	void setPattern2(cocos2d::Sprite *penguin);
	void setPattern3(cocos2d::Sprite *penguin);
	void setPattern4(cocos2d::Sprite *penguin);
	void setPattern5(cocos2d::Sprite *penguin);

public:
	virtual cocos2d::Rect getCollidableRect() const override;
	virtual void collide(CollideState state);

private:
	cocos2d::Sprite *_body;
	cocos2d::Rect _collisionBox;
};

#endif // Penguin_h__
