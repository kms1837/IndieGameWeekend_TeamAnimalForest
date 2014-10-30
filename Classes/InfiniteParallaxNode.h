#ifndef InfiniteParallaxNode_h__
#define InfiniteParallaxNode_h__

#include "cocos2d.h"

class InfiniteParallaxNode :
	public cocos2d::ParallaxNode
{
public:
	static InfiniteParallaxNode *create();
	void updatePosition();
};

#endif // InfiniteParallaxNode_h__
