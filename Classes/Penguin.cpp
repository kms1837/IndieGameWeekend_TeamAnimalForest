#include "Penguin.h"

using namespace cocos2d;

const static char *PENGUIN_FLY = "Obstacles/Fly_Penguin.png";
const static char *PENGUIN_JUMP = "Obstacles/Jump_Penguin.png";
const static char *PENGUIN_RUN_ARRAY[] =
{
	"Obstacles/1.png",
	"Obstacles/2.png",
	"Obstacles/3.png",
	"Obstacles/4.png",
	"Obstacles/5.png",
	"Obstacles/6.png",
	"Obstacles/7.png"
};

Penguin::Penguin()
{
}

Penguin::~Penguin()
{
}

cocos2d::Sprite * Penguin::createPenguin(Pattern pattern)
{
	_body = Sprite::create(PENGUIN_RUN_ARRAY[0]);

	if (pattern == Pattern1) {
		setPattern1(_body);
	}
	else if (pattern == Pattern2) {
		setPattern2(_body);
	}
	else if (pattern == Pattern3) {
		setPattern3(_body);
	}
	else if (pattern == Pattern4) {
		setPattern4(_body);
	}
	else if (pattern == Pattern5) {
		setPattern5(_body);
	}
	return _body;
}

void Penguin::setPattern1(cocos2d::Sprite *penguin)
{
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	for (int i = 0; i < 7; ++i) {
		animation->addSpriteFrameWithFile(PENGUIN_RUN_ARRAY[i]);
	}
	RepeatForever *action = RepeatForever::create(Animate::create(animation));
	penguin->runAction(action);
	penguin->runAction(
		Sequence::create(
		MoveBy::create(4.0f, Vec2(-1000.0f, 0.0f)),
		FadeOut::create(0.5f), 
		nullptr));
}

void Penguin::setPattern2(cocos2d::Sprite *penguin)
{
	penguin->runAction(
		Sequence::create(
		MoveBy::create(1.0f, Vec2(-500.0f, 0.0f)),
		JumpBy::create(0.3, Vec2(-500.0f, 0.0f), 300.0f, 1),
		MoveBy::create(4.0f, Vec2(-2000.0f, 0.0f)),
		FadeOut::create(0.5f),
		CallFunc::create([penguin](){  }),
		nullptr));
}

void Penguin::setPattern3(cocos2d::Sprite *penguin)
{
	penguin->runAction(
		Sequence::create(
		JumpBy::create(4.0f, Vec2(-3000.0f, 0.0f), 200.0f, 10),
		FadeOut::create(0.5f),
		nullptr));

}

void Penguin::setPattern4(cocos2d::Sprite *penguin)
{
	TextureCache *textureCache = Director::getInstance()->getTextureCache();
	penguin->setTexture(textureCache->addImage(PENGUIN_JUMP));
	penguin->setContentSize(Size(110.0f, 110.0f));
	penguin->setScale(1.0);
	penguin->runAction(
		Spawn::create(
		RotateBy::create(3.2f, Vec3(0, 0, 10000.0f)),
		Sequence::create(
		JumpBy::create(0.4f, Vec2(-300.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-100.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-300.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-100.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-300.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-100.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-300.0f, 0.0f), 200.0f, 1),
		JumpBy::create(0.4f, Vec2(-100.0f, 0.0f), 200.0f, 1),
		FadeOut::create(0.5f),
		nullptr),
		nullptr));
}

void Penguin::setPattern5(cocos2d::Sprite *penguin)
{
	TextureCache *textureCache = Director::getInstance()->getTextureCache();
	penguin->setTexture(textureCache->addImage(PENGUIN_FLY));
	penguin->setContentSize(Size(250.0f, 110.0f));
	penguin->runAction(
		Sequence::create(
		MoveBy::create(2.0f, Vec2(-4000, 0)),
		FadeOut::create(0.5f),
		nullptr));
}

cocos2d::Rect Penguin::getCollidableRect() const
{
	Rect rect = _body->getBoundingBox();
	Vec2 position = _body->getPosition();
	Node *parent = _body->getParent();
	Size size = rect.size;
	position = parent->convertToWorldSpace(position);
	rect.setRect(position.x, position.y, size.width, size.height);
	return rect;
}

void Penguin::collide(CollideState state)
{
}
