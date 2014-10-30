#ifndef MapScrollView_h__
#define MapScrollView_h__

#include "cocos2d.h"
#include "cocos-ext.h"

class MapScrollView : 
	public cocos2d::Layer, 
	public cocos2d::extension::ScrollViewDelegate
{
public:
	MapScrollView(void);
	~MapScrollView(void);

	// create()의 사용을 위한 함수들
	virtual bool init();
	CREATE_FUNC(MapScrollView);

	// ScrollViewDelegate 상속 메소드 선언
	void scrollViewDidScroll(cocos2d::extension::ScrollView* view);
	void scrollViewDidZoom(cocos2d::extension::ScrollView* view);
};

#endif // MapScrollView_h__