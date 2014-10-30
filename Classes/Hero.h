#ifndef Hero_h__
#define Hero_h__

#include "cocos2d.h"

#define NORMAL  1
#define MOVE    2
#define JUMP    3

#define JUMPUP   1
#define JUMPDOWN 2

#define JUMPACCELL 0.35

class Hero : public cocos2d::Ref
{
public:
	Hero();
	~Hero();
	void registerEventListener();
	void unregisterEventListener();
    void create(cocos2d::Layer*, float, float);

private:
	void onLeft(cocos2d::EventCustom* event);
	void onRight(cocos2d::EventCustom* event);
	void onJump(cocos2d::EventCustom* event);
	void onSlide(cocos2d::EventCustom* event);
    void update(float);
    
    void jumpProcess();

	cocos2d::Sprite *_body;
	cocos2d::EventListenerCustom *_eventListenerCustom;
    int _velocity;
    int _maxVelocity;
    
    float _jumpPower;  // 점프력
    float _jumpHeight;
    float _jumpStart;
    int _jumpState;
    float _gravity;
    
    float _speed; //애니메이션 속도
    
    int _state;
    int _prevState;
    int _animeSwitch;
};

#endif // Hero_h__
