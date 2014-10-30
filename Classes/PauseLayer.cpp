#include "PauseLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

PauseLayer::PauseLayer()
{
}

PauseLayer::~PauseLayer()
{
}

SEL_MenuHandler PauseLayer::onResolveCCBCCMenuItemSelector(Ref * pTarget, const char * pSelectorName)
{
    CCLOG("%s", pSelectorName);
    return NULL;
}

Control::Handler PauseLayer::onResolveCCBCCControlSelector(Ref * pTarget, const char * pSelectorName)
{
    return NULL;
}

bool PauseLayer::onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName, cocos2d::Node * node)
{
    return false;
}

bool PauseLayer::onAssignCCBCustomProperty(Ref* pTarget, const char* pMemberVariableName, const cocos2d::Value& pCCBValue)
{
    return false;
}

void PauseLayer::onNodeLoaded(cocos2d::Node * node, cocosbuilder::NodeLoader * nodeLoader)
{
    CCLOG("로딩완료");
}

