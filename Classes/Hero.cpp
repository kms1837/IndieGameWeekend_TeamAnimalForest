#include "Hero.h"

using namespace cocos2d;

Hero::Hero() :
_body(nullptr),
_eventListenerCustom(nullptr),
_velocity(0),
_maxVelocity(3),
_speed(0.72),
_gravity(0),
_jumpPower(14.0f),
_jumpHeight(0.0f),
_animeSwitch(false),
_state(NORMAL),
_prevState(NORMAL)
{
    Director* director = Director::getInstance();
    Scheduler *scheduler = director->getScheduler();
    scheduler->schedule(schedule_selector(Hero::update), this, 0, false);
}

Hero::~Hero()
{
}

void Hero::update(float dt)
{
    switch (_state) {
        case NORMAL: {
            _body->stopAllActions();
            _body->setTexture("rockman_normal.png");
            _animeSwitch = false;
            break;
        }
        case MOVE: {
            if(!_animeSwitch){
                _body->stopAllActions();
                
                Vector<SpriteFrame*> animaFrames(4);
                animaFrames.pushBack(SpriteFrame::create("rockman_run2.png", Rect(0, 0, 170, 180)));
                animaFrames.pushBack(SpriteFrame::create("rockman_run3.png", Rect(0, 0, 170, 180)));
                animaFrames.pushBack(SpriteFrame::create("rockman_run2.png", Rect(0, 0, 170, 180)));
                animaFrames.pushBack(SpriteFrame::create("rockman_run1.png", Rect(0, 0, 170, 180)));
            
                auto rockManRunAnime   = Animation::createWithSpriteFrames(animaFrames, _speed);
                auto runAnimate        = Animate::create(rockManRunAnime);
                auto rockManRunAnimate = RepeatForever::create(runAnimate);
                _body->runAction(rockManRunAnimate);
                
                _animeSwitch = true;
                
            }

            break;
        }
        case JUMP: {
            jumpProcess();
            break;
        }
    }
}

void Hero::jumpProcess()
{
    switch (_jumpState)
    {
        case JUMPUP: { // up
            _jumpHeight += _gravity;
            if (_gravity <= 0.0f) _jumpState = JUMPDOWN;
            else                  _gravity -= JUMPACCELL;
            
            break;
        }
            
        case JUMPDOWN: { // down
            _jumpHeight -= _gravity;
            if (_jumpHeight > _jumpStart) _gravity += JUMPACCELL;
            else                          _state = _prevState;
            
            break;
        }
    }
    
    CCLOG("jumpHeight : %f", _jumpHeight);
    Vec2 bodyPosition = _body->getPosition();
    _body->setPosition(Vec2(bodyPosition.x, _jumpHeight));
}

void Hero::create(cocos2d::Layer* layer, float x, float y)
{
    _body = Sprite::create("rockman_normal.png");
    _body->setPosition(Vec2(x, y));
    layer->addChild(_body);
}

void Hero::registerEventListener()
{
	Director *director = Director::getInstance();
	EventDispatcher *eventDispatcher = director->getEventDispatcher();

	EventListenerCustom *customEventListener = EventListenerCustom::create("slide", CC_CALLBACK_1(Hero::onSlide, this));
	eventDispatcher->addEventListenerWithFixedPriority(customEventListener, 1);

	customEventListener = EventListenerCustom::create("jump", CC_CALLBACK_1(Hero::onJump, this));
	eventDispatcher->addEventListenerWithFixedPriority(customEventListener, 1);

	customEventListener = EventListenerCustom::create("right", CC_CALLBACK_1(Hero::onRight, this));
	eventDispatcher->addEventListenerWithFixedPriority(customEventListener, 1);

	customEventListener = EventListenerCustom::create("left", CC_CALLBACK_1(Hero::onLeft, this));
	eventDispatcher->addEventListenerWithFixedPriority(customEventListener, 1);
}

void Hero::unregisterEventListener()
{

}

void Hero::onRight(cocos2d::EventCustom* event)
{
    if(_velocity < _maxVelocity && _state != JUMP) {
        _animeSwitch = false;
        _state = MOVE;
        _velocity += 1;
        
        if(_velocity == 0){
            _state = NORMAL;
           _speed = 0.72;
        }else if(_velocity > 0){
            _speed -= 0.18;
        }else{
            _speed += 0.18;
        }
    }
    
    CCLOG("velovity : %d, state : %d, speed: %f", _velocity, _state, _speed);
    CCLOG(__FUNCTION__);
}

void Hero::onLeft(cocos2d::EventCustom* event)
{
    if(_velocity > -(_maxVelocity) && _state != JUMP) {
        _animeSwitch = false;
        _state = MOVE;
        _velocity -= 1;
        
        if(_velocity == 0){
            _state = NORMAL;
            _speed = 0.72;
        }else if(_velocity < 0){
            _speed -= 0.18;
        }else{
            _speed += 0.18;
        }
    }
    
    CCLOG("velovity : %d, state : %d, speed: %f", _velocity, _state, _speed);
	CCLOG(__FUNCTION__);
}

void Hero::onJump(cocos2d::EventCustom* event)
{
    if(_state != JUMP){
        Vec2 bodyPosition = _body->getPosition();
        _gravity = _jumpPower;
        _jumpState = JUMPUP;
        _jumpStart = bodyPosition.y;
        _jumpHeight = _jumpStart;
        
        _prevState = _state;
        _state = JUMP;
        
        _animeSwitch = false;
        _body->stopAllActions();
        _body->setTexture("rockman_jump.png");
    }
	CCLOG(__FUNCTION__);
}

void Hero::onSlide(cocos2d::EventCustom* event)
{
    if(_state == MOVE) {
        
    }
	CCLOG(__FUNCTION__);
}

