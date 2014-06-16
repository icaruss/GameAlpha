#include "FrameBorder.h"

FrameBorder::FrameBorder(void)
{
}

FrameBorder::~FrameBorder(void)
{
}

Rect FrameBorder::getRect()
{
    auto s = getTexture()->getContentSize();
    return Rect(-s.width / 2, -s.height / 2, s.width, s.height);
}

FrameBorder* FrameBorder::createWithTexture(Texture2D* aTexture)
{
    FrameBorder* framePart = new FrameBorder();
    framePart->initWithTexture(aTexture);
    framePart->autorelease();

    return framePart;
}

bool FrameBorder::initWithTexture(Texture2D* aTexture)
{
    if( Sprite::initWithTexture(aTexture) )
    {
		_state = kFrameBorderStateUngrabbed;
    }
    
    return true;
}

void FrameBorder::onEnter()
{
    Sprite::onEnter();
    
    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(FrameBorder::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(FrameBorder::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(FrameBorder::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FrameBorder::onExit()
{
//    auto director = Director::getInstance();
//    director->getTouchDispatcher()->removeDelegate(this);
    Sprite::onExit();
}    

bool FrameBorder::containsTouchLocation(Touch* touch)
{
    return getRect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool FrameBorder::onTouchBegan(Touch* touch, Event* event)
{
    CCLOG("FrameBorder::onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);
    
	if (_state != kFrameBorderStateUngrabbed) return false;
    if ( !containsTouchLocation(touch) ) return false;
    
	_state = kFrameBorderStateGrabbed;
    CCLOG("return true");
    return true;
}

void FrameBorder::onTouchMoved(Touch* touch, Event* event)
{
    // If it weren't for the TouchDispatcher, you would need to keep a reference
    // to the touch from touchBegan and check that the current touch is the same
    // as that one.
    // Actually, it would be even more complicated since in the Cocos dispatcher
    // you get Sets instead of 1 UITouch, so you'd need to loop through the set
    // in each touchXXX method.
    
    CCLOG("FrameBorder::onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touch->getLocation().x, touch->getLocation().y);
    
	CCASSERT(_state == kFrameBorderStateGrabbed, "FrameBorder - Unexpected state!");    
    
    auto touchPoint = touch->getLocation();
    
    setPosition( Vec2(touchPoint.x, getPosition().y) );
}

FrameBorder* FrameBorder::clone() const
{
    FrameBorder* ret = FrameBorder::createWithTexture(_texture);
    ret->_state = _state;
    ret->setPosition(getPosition());
    ret->setAnchorPoint(getAnchorPoint());
    return ret;
}

void FrameBorder::onTouchEnded(Touch* touch, Event* event)
{
    CCASSERT(_state == kFrameBorderStateGrabbed, "FrameBorder - Unexpected state!");    
    
	_state = kFrameBorderStateUngrabbed;
} 
