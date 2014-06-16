#ifndef _SPRITEOBJECT_H_
#define _SPRITEOBJECT_H_

#include "cocos2d.h"

class FrameBorder;

USING_NS_CC;

class SpriteObject : public Sprite
{
    Vec2 _velocity;
public:
    SpriteObject(void);
    virtual ~SpriteObject(void);

    float radius();

    void move(float delta);
    void collideWithFrame(FrameBorder* frameBorder);


public:
    void setVelocity(Vec2 velocity){_velocity = velocity;}
    Vec2 getVelocity(){return _velocity;}

public:
    static SpriteObject* spriteWithTexture(Texture2D* aTexture);
	static SpriteObject* spriteWithFileName(const std::string& filename);
};

#endif
