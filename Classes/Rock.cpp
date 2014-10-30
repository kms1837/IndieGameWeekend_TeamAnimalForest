#include "Rock.h"

using namespace cocos2d;

Rock::Rock()
{

}

Rock::~Rock()
{

}

cocos2d::Sprite *Rock::createRock()
{
	_body = Sprite::create("Rock.jpg");
	setPattern(_body);
	return _body;
}

void Rock::setPattern(cocos2d::Sprite *rock)
{
	rock->runAction(
		MoveBy::create(2.0f, Vec2(4000.0f, 0.0f)));
}

cocos2d::Rect Rock::getCollidableRect() const
{
	Rect rect = _body->getBoundingBox();
	Vec2 position = _body->getPosition();
	Node *parent = _body->getParent();
	Size size = rect.size;
	position = parent->convertToWorldSpace(position);
	rect.setRect(position.x, position.y, size.width, size.height);
	return rect;
}

void Rock::collide(CollideState state)
{

}

