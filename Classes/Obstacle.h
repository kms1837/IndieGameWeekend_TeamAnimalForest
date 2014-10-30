#ifndef Obstacle_h__
#define Obstacle_h__

#include "cocos2d.h"

struct Kind
{
	std::string name;
	float positionX;
};

struct Obstacle
{
	float sensorPositionX;
	std::vector<Kind> kinds;
};

typedef std::vector<Obstacle> Obstacles;

#endif // Obstacle_h__
