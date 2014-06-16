#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__


#include <vector>
#include "cocos2d.h"
#include "FrameBorder.h"
#include "SpriteObject.h"

using namespace cocos2d;
using namespace std;

class GameScene : public Layer
{
public:

	vector<Point*> *points;

	Point *frameDelta;


    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);



	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchCancelled(Touch *touch, Event *event);



private:

	bool		isTouchOnFrame(Point point);
	void		CreateObjects(int staticObjects, int movingObjects);
	void		CreateBorders();
	void		doStep(float delta);
	void		resetAndScoreBallForPlayer(SpriteObject* movingObject);

	//void		moveObjectsRandomly(int movingObjects);
	//void        setObjectToMove(Sprite *sprite, int angle);
	//Point		getNewPositionToMoveToByAngle(int angle);


	Vector<FrameBorder*> _frames;
	Vector<SpriteObject*> _movingObjects;
};

#endif // __HELLOWORLD_SCENE_H__
