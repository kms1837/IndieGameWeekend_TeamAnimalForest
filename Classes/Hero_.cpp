#include "Hero.h"

#include "MapScene.h"

using namespace cocos2d;

const static int NORMAL = 1;
const static int MOVE = 2;
const static int JUMP = 3;
const static int SLIDE = 4;
const static int ATTACK = 5;

const static int JUMPUP = 101;
const static int JUMPDOWN = 102;

const static float JUMPACCELL = 0.35f;

Hero::Hero(const HeroInfo &heroInfo) :
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
_prevState(NORMAL),
_heroInfo(heroInfo)
{
	_body = Sprite::create("rockman_normal.png");
	_body->setPosition(Vec2(640, 200));
	_body->retain();
	
    Director* director = Director::getInstance();
    Scheduler *scheduler = director->getScheduler();
    scheduler->schedule(schedule_selector(Hero::update), this, 0, false);
}

Hero::~Hero()
{
	_body->release();
	Director* director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->unschedule(schedule_selector(Hero::update), this);
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
        case SLIDE: {
            _body->stopAllActions();
            _body->setTexture("rockman_slide.png");
            break;
        }
        case ATTACK: {
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
            else                          afterProcess();
            
            break;
        }
    }
    
    //CCLOG("jumpHeight : %f, state : %d", _jumpHeight, _state);
    Vec2 bodyPosition = _body->getPosition();
    _body->setPosition(Vec2(bodyPosition.x, _jumpHeight));
}

void Hero::afterProcess()
{
    switch (_state) {
        case JUMP:
            if(_prevState != SLIDE && _prevState != ATTACK) {
                _state = _prevState;
                if(_velocity == 0) {
                    _state = NORMAL;
                    _speed = 0.72;
                }
            }else{
                _state = MOVE;
            }
            break;
        default:
            break;
    }
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
    
    customEventListener = EventListenerCustom::create("zKey", CC_CALLBACK_1(Hero::onKeyZ, this));
    eventDispatcher->addEventListenerWithFixedPriority(customEventListener, 1);
}

void Hero::unregisterEventListener()
{

}

void Hero::onRight(cocos2d::EventCustom* event)
{
    if(_state != ATTACK){
        if(_state == SLIDE) {
            _animeSwitch = false;
            _state = MOVE;
        }
        
        if(_velocity < _maxVelocity) {
            if(_state != JUMP){
                _animeSwitch = false;
                _state = MOVE;
            }
            _velocity += 1;
        
            if(_velocity == 0 && _state != JUMP){
                _state = NORMAL;
                _speed = 0.72;
            }else if(_velocity > 0){
                _speed -= 0.18;
            }else{
                _speed += 0.18;
            }
        }
    }
    
    CCLOG("velovity : %d, state : %d, speed: %f", _velocity, _state, _speed);
    CCLOG(__FUNCTION__);
}

void Hero::onLeft(cocos2d::EventCustom* event)
{
    if(_state != ATTACK){
        if(_state == SLIDE) {
            _animeSwitch = false;
            _state = MOVE;
        }
        
        if(_velocity > -(_maxVelocity)) {
            if(_state != JUMP){
                _animeSwitch = false;
                _state = MOVE;
            }
            _velocity -= 1;
        
            if(_velocity == 0 && _state != JUMP){
                _state = NORMAL;
                _speed = 0.72;
            }else if(_velocity < 0){
                _speed -= 0.18;
            }else{
                _speed += 0.18;
            }
        }
    }
    
    CCLOG("velovity : %d, state : %d, speed: %f", _velocity, _state, _speed);
	CCLOG(__FUNCTION__);
}

void Hero::onJump(EventCustom* event)
{
    if(_state != JUMP && _state != ATTACK) {
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/Jump.wav");
        
        Vec2 bodyPosition = _body->getPosition();
        _gravity    = _jumpPower;
        _jumpState  = JUMPUP;
        _jumpStart  = bodyPosition.y;
        _jumpHeight = _jumpStart;
        
        _prevState  = _state;
        _state      = JUMP;
        
        _animeSwitch = false;
        _body->stopAllActions();
        _body->setTexture("rockman_jump.png");
    }
	CCLOG(__FUNCTION__);
}

void Hero::onSlide(EventCustom* event)
{
    if(_state == MOVE){
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/Slide.wav");
        _state = SLIDE;
    }
    
	CCLOG(__FUNCTION__);
}

void Hero::onKeyZ(EventCustom* event)
{
    if(_state != ATTACK && _state != JUMP) {
        _prevState  = _state;
        _state = ATTACK;
        _body->stopAllActions();
        _body->setTexture("rockman_attack.png");
        
        CallFunc* delayToNormal = CallFunc::create([&] (){
            _animeSwitch = false;
            _state = _prevState;
        });
        
        _body->runAction(Sequence::create(DelayTime::create(1.0f), delayToNormal, nullptr));
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sound/Snack.wav");
    }
    CCLOG(__FUNCTION__);
}

cocos2d::Rect Hero::getCollidableRect()  const
{
	Rect rect = _body->getBoundingBox();
	Vec2 position = _body->getPosition();
	Node *parent = _body->getParent();
	Size size = rect.size;
	position = parent->convertToWorldSpace(position);
	rect.setRect(position.x, position.y, size.width, size.height);
	return rect;
}

void Hero::collide(CollideState state)
{
	if (state == CollideState::Fail) {
		Sprite *pauseBoard = Sprite::create("GameUi/popup_board2.png");

		Sprite *exitNormal = Sprite::create("GameUi/popup_UI2.png");
		Sprite *exitSelected = Sprite::create("GameUi/popup_UI2.png");
		exitNormal->setScale(1.2);
		std::function<void(Ref *ref)>
			onExit = [](Ref *ref)
		{
			Director *director = Director::getInstance();
			director->resume();
			director->replaceScene(MapScene::create());
		};
		MenuItemSprite *exitMenuItem = MenuItemSprite::create(exitNormal, exitSelected, onExit);
		Menu *exitMenu = Menu::create(exitMenuItem, nullptr);
		exitMenu->setPosition(Vec2(640, 240));
		pauseBoard->addChild(exitMenu);

		Director *director = Director::getInstance();
		Scene *scene = director->getRunningScene();
		pauseBoard->setAnchorPoint(Vec2::ZERO);
		scene->addChild(pauseBoard);
	}
}

