#include "Seagull.h"

using namespace cocos2d;

Seagull::Seagull()
{

}

Seagull::~Seagull()
{

}

cocos2d::Sprite * Seagull::createSeagull()
{
	_body = Sprite::create();

	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	animation->addSpriteFrameWithFile("Obstacles/bird1.png");
	animation->addSpriteFrameWithFile("Obstacles/bird2.png");
	RepeatForever *action = RepeatForever::create(Animate::create(animation));
	_body->runAction(action);

	setPattern(_body);

	return _body;
}

void Seagull::setPattern(cocos2d::Sprite *body)
{
	Vec2 seagullPotion = body->getPosition();
	//MoveTo* action1 = MoveTo::create(0.78f, Vec2(seagullPotion.x-800, seagullPotion.y-100));
	//MoveTo* action2 = MoveTo::create(0.78f, Vec2(seagullPotion.x, seagullPotion.y-240));
	//Spawn* spanwnAction = Spawn::create(action1, action2, NULL);

	ccBezierConfig bezier;
	bezier.controlPoint_1 = Vec2(seagullPotion.x, seagullPotion.y);  // 첫번째 위치
	bezier.controlPoint_2 = Point(seagullPotion.x - 640, seagullPotion.y - 900);    // 두번째 위치
	bezier.endPosition = Vec2(seagullPotion.x - 1280, seagullPotion.y);

	BezierTo* patternAction = BezierTo::create(2.0f, bezier);
	body->runAction(patternAction);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/Seagull.wav");

}

cocos2d::Rect Seagull::getCollidableRect() const
{
	Rect rect = _body->getBoundingBox();
	Vec2 position = _body->getPosition();
	Node *parent = _body->getParent();
	Size size = rect.size;
	position = parent->convertToWorldSpace(position);
	rect.setRect(position.x, position.y, size.width, size.height);
	return rect;
}

void Seagull::collide(CollideState state)
{
}
