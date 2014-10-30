#include "MapScene.h"

#include "cocos-ext.h"

#include "GameScene.h"
#include "ReadyMenu.h"
#include "RegionInfo.h"
#include "HeroInfo.h"

using namespace cocos2d;
using namespace cocos2d::extension;

MapScene::MapScene() :
_readyMenu(nullptr)
{

}

MapScene::~MapScene()
{
	if (_readyMenu) {
		delete _readyMenu;
		_readyMenu = nullptr;
	}
}

MapScene* MapScene::create()
{
	MapScene *menu = new MapScene();
	if (menu && menu->init()) {
		menu->autorelease();
		return menu;
	}
	CC_SAFE_DELETE(menu);
	return nullptr;
}

bool MapScene::init()
{
	if (!Scene::init()){
		return false;
	}

	Director *director = Director::getInstance();
	Size winSize = director->getWinSize();

	Layer *mapLayer = Layer::create();

	Sprite *map = Sprite::create("Map/Main_Main.png");
	map->setAnchorPoint(Vec2::ZERO);
	mapLayer->addChild(map);

	Sprite *regionNormal = Sprite::create("Map/Main_flag.png");
	Sprite *regionSelected = Sprite::create("Map/Main_flag.png");
	regionSelected->setScale(1.2f);
	std::function<void(Ref *ref)>
		onRegionTouched = [this](Ref *ref)->void
	{
		if (_readyMenu) {
			delete _readyMenu;
			_readyMenu = nullptr;
		}
		RegionInfo regionInfo;
		HeroInfo heroInfo;
		regionInfo.stageName = "Stage1.json";
		heroInfo.heroName = "normal";
		_readyMenu = new ReadyMenu(regionInfo, heroInfo);
		Layer *readyLayer = _readyMenu->getLayer();
		addChild(readyLayer);
	};
	MenuItemSprite *regionMenuItem = MenuItemSprite::create(regionNormal, regionSelected, onRegionTouched);
	Menu *regionMenu = Menu::create(regionMenuItem, nullptr);
	regionMenu->setPosition(Vec2(700.0f, 220.0f));
	mapLayer->addChild(regionMenu);

	ScrollView *scrollView = ScrollView::create(winSize, mapLayer);
	scrollView->setTouchEnabled(true);
	scrollView->setContentSize(map->getContentSize());
	scrollView->setPosition(Vec2::ZERO);
	scrollView->setDirection(ScrollView::Direction::BOTH);
	scrollView->setBounceable(false);
	addChild(scrollView);
    
	return true;
}

