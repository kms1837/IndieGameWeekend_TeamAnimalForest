#ifndef __ProtoType__CreditScene__
#define __ProtoType__CreditScene__

#include "cocos2d.h"

class CreditScene : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(CreditScene);
    
private:
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event);
};

#endif
