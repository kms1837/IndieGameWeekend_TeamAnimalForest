#ifndef __ProtoType__GameMainBuilderLoader__
#define __ProtoType__GameMainBuilderLoader__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "cocosbuilder/CocosBuilder.h"

class GameMainScene
: public cocos2d::Layer
, public cocosbuilder::CCBSelectorResolver
, public cocosbuilder::CCBMemberVariableAssigner
, public cocosbuilder::NodeLoaderListener
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(GameMainScene, create);
    GameMainScene();
    ~GameMainScene();
    
    static cocos2d::Scene* createScene();
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget, const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node);
    virtual bool onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue);
    virtual void onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader);
    
private:
    void startButton(cocos2d::CCObject *pSender);
    void creditButton(cocos2d::CCObject *pSender);
    
};

class CCBReader;

class GameMainBuilderLoader : public cocosbuilder::LayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameMainBuilderLoader, loader);
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameMainScene);
};


#endif
