#ifndef CollisionDetector_h__
#define CollisionDetector_h__

#include "cocos2d.h"

#include <unordered_set>

class Collidable;

class CollisionDetector :
	public cocos2d::Ref
{
public:
	CollisionDetector();
	~CollisionDetector();
	void setHero(Collidable *hero);
	void removeHero();
	void setSnack(Collidable *snack);
	void removeSnack();
	void addObstacles(Collidable *obstacle);
	void removeObstacle(Collidable *obstacle);

private:
	void collisionHeroCheck();
	void collisionSnackCheck();
	void update(float dt);

private:
	Collidable *_hero;
	Collidable *_snack;
	std::unordered_set<Collidable *> _obstacles;
};

#endif // CollisionDetector_h__
