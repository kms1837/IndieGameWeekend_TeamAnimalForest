#ifndef _Cafri_JsonParser_H_
#define _Cafri_JsonParser_H_

#include <string>
#include "json/rapidjson.h"
#include "json/document.h"
#include "Obstacle.h"

class JsonParser
{
public:
	JsonParser();
	~JsonParser();
	static void getObstaclesFromFile(const std::string &fileName, Obstacles *obstacles);
private:
};
#endif