#ifndef Hero_h__
#define Hero_h__

#include "cocos2d.h"

#include "Collidable.h"
#include "HeroInfo.h"

class Hero : 
	public cocos2d::Ref,
	public Collidable
{
public:
	Hero(const HeroInfo &heroInfo);
	~Hero();
	void registerEventListener();
	void unregisterEventListener();
	cocos2d::Sprite *getHeroSprite() const { return _body; }

public:
	virtual cocos2d::Rect getCollidableRect() const override;
	virtual void collide(CollideState state) override;

private:
	void onLeft(cocos2d::EventCustom* event);
	void onRight(cocos2d::EventCustom* event);
	void onJump(cocos2d::EventCustom* event);
	void onSlide(cocos2d::EventCustom* event);
    void onKeyZ(cocos2d::EventCustom* event);
    void update(float);
    
    void jumpProcess();
    
    void afterProcess();

	cocos2d::Sprite *_body;
	cocos2d::EventListenerCustom *_eventListenerCustom;
    int _velocity;
    int _maxVelocity;
    
    float _jumpPower;
    float _jumpHeight;
    float _jumpStart;
    int _jumpState;
    float _gravity;
    
    float _speed;
    
    float _attackSpeed;
    
    int _state;
    int _prevState;
    int _animeSwitch;

	HeroInfo _heroInfo;
};

#endif // Hero_h__
