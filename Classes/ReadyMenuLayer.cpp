#include "ReadyMenuLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

ReadyMenuLayer::ReadyMenuLayer()
{
}

ReadyMenuLayer::~ReadyMenuLayer()
{
}

SEL_MenuHandler ReadyMenuLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    CCLOG("%s", pSelectorName);
    return NULL;
}

Control::Handler ReadyMenuLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool ReadyMenuLayer::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node)
{
    return false;
}

bool ReadyMenuLayer::onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
    return false;
}

void ReadyMenuLayer::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{
    CCLOG("로딩완료");
}