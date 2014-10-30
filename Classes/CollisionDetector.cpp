#include "CollisionDetector.h"

#include "Collidable.h"

using namespace cocos2d;

CollisionDetector::CollisionDetector() :
_hero(nullptr),
_snack(nullptr),
_obstacles()
{
	Director *director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->schedule(schedule_selector(CollisionDetector::update), this, 0.0f, false);
}

CollisionDetector::~CollisionDetector()
{
	Director *director = Director::getInstance();
	Scheduler *scheduler = director->getScheduler();
	scheduler->unschedule(schedule_selector(CollisionDetector::update), this);
}

void CollisionDetector::setHero(Collidable *hero)
{
	CCASSERT(_hero == nullptr, "_hero is not nullptr");
	_hero = hero;
}

void CollisionDetector::removeHero()
{
	_hero = nullptr;
}

void CollisionDetector::setSnack(Collidable *snack)
{
	CCASSERT(_snack == nullptr, "_snack is not nullptr");
	_snack = snack;
}

void CollisionDetector::removeSnack()
{
	_snack = nullptr;
}

void CollisionDetector::addObstacles(Collidable *obstacle)
{
	auto it = _obstacles.find(obstacle);
	CCASSERT(it == _obstacles.end(), "_obstacles have obstacle");
	_obstacles.insert(obstacle);
}

void CollisionDetector::removeObstacle(Collidable *obstacle)
{
	auto it = _obstacles.find(obstacle);
	CCASSERT(it != _obstacles.end(), "_obstacles do not have obstacle");
	_obstacles.erase(it);
}

void CollisionDetector::collisionHeroCheck()
{
	for (Collidable *obstacle : _obstacles) {
		Rect obstacleRect = obstacle->getCollidableRect();
		Rect heroRect = _hero->getCollidableRect();
		if (heroRect.intersectsRect(obstacleRect)) {
			_hero->collide(Collidable::Fail);
			obstacle->collide(Collidable::Success);
		}
	}
}

void CollisionDetector::collisionSnackCheck()
{
	if (_snack != nullptr) {
		for (Collidable *obstacle : _obstacles) {
			Rect obstacleRect = obstacle->getCollidableRect();
			Rect snackRect = _snack->getCollidableRect();
			if (snackRect.intersectsRect(obstacleRect)) {
				_snack->collide(Collidable::Fail);
				obstacle->collide(Collidable::Success);
			}
		}
	}
}

void CollisionDetector::update(float dt)
{
	collisionHeroCheck();
//	collisionSnackCheck();
}
