#include "Seaweed.h"

using namespace cocos2d;

Seaweed::Seaweed()
{

}

Seaweed::~Seaweed()
{

}

cocos2d::Sprite *Seaweed::createSeaweed()
{
	_body = Sprite::create("Seaweed.png");
	setPattern(_body);
	return _body;
}

void Seaweed::setPattern(cocos2d::Sprite *seaweed)
{
	
}

cocos2d::Rect Seaweed::getCollidableRect() const
{
	Rect rect = _body->getBoundingBox();
	Vec2 position = _body->getPosition();
	Node *parent = _body->getParent();
	Size size = rect.size;
	position = parent->convertToWorldSpace(position);
	rect.setRect(position.x, position.y, size.width, size.height);
	return rect;
}

void Seaweed::collide(CollideState state)
{
}
