#ifndef _FRAMEBORDER_H_
#define _FRAMEBORDER_H_

#include "cocos2d.h"

USING_NS_CC;

typedef enum tagFrameBorderState 
{
    kFrameBorderStateGrabbed,
    kFrameBorderStateUngrabbed
} FrameBorderState; 

class FrameBorder : public Sprite, public Clonable
{
    FrameBorderState        _state;

public:
    FrameBorder(void);
    virtual ~FrameBorder(void);

    Rect getRect();
    bool initWithTexture(Texture2D* aTexture);
    virtual void onEnter() override;
    virtual void onExit() override;
    bool containsTouchLocation(Touch* touch);
    bool onTouchBegan(Touch* touch, Event* event);
    void onTouchMoved(Touch* touch, Event* event);
    void onTouchEnded(Touch* touch, Event* event);
    virtual FrameBorder* clone() const;

    static FrameBorder* createWithTexture(Texture2D* aTexture);
};

#endif
