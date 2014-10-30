#include "Crap.h"

using namespace cocos2d;

Crap::Crap()
{

}

Crap::~Crap()
{

}

cocos2d::Sprite *Crap::createCrap()
{
	_body = Sprite::create("Crap.png");
	setPattern(_body);
	return _body;
}

void Crap::setPattern(cocos2d::Sprite *crap)
{
	crap->runAction(
		MoveBy::create(2.0f, Vec2(4000.0f, 0.0f)));
}

cocos2d::Rect Crap::getCollidableRect() const
{
	Rect rect = _body->getBoundingBox();
	Vec2 position = _body->getPosition();
	Node *parent = _body->getParent();
	Size size = rect.size;
	position = parent->convertToWorldSpace(position);
	rect.setRect(position.x, position.y, size.width, size.height);
	return rect;
}

void Crap::collide(CollideState state)
{

}

