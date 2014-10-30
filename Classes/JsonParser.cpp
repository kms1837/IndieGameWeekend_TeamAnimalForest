#include "JsonParser.h"

#include "cocos2d.h"

using namespace cocos2d;

JsonParser::JsonParser()
{
}

JsonParser::~JsonParser()
{
}

void JsonParser::getObstaclesFromFile(const std::string &fileName, Obstacles *obstacles)
{
	// sonbong: file read
	std::string filePath = FileUtils::getInstance()->fullPathForFilename(fileName);
	std::string jsonString = FileUtils::getInstance()->getStringFromFile(filePath);

	rapidjson::Document document;
	document.Parse<0>(jsonString.c_str());

	rapidjson::Value &obstaclesValue = document["Obstacles"];
	for (rapidjson::SizeType i = 0; i != obstaclesValue.Size(); ++i) {
		rapidjson::Value &obstacleValue = obstaclesValue[i];
		Obstacle obstacle;
		obstacle.sensorPositionX = obstacleValue["SensorPosition"].GetDouble();
		rapidjson::Value &kindValues = obstacleValue["Kinds"];
		for (rapidjson::SizeType i = 0; i != kindValues.Size(); ++i) {
			rapidjson::Value &kindValue = kindValues[i];
			Kind kind;
			kind.name = kindValue["Name"].GetString();
			kind.positionX = kindValue["Position"].GetDouble();
			obstacle.kinds.push_back(kind);
		}
		obstacles->push_back(obstacle);
	}
}