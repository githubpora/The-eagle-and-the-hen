#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;
using namespace std;

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameScene);
private:
	bool isMove;//�ɻ��ƶ�
	bool isClick;//�������
	bool isTouch; //����ɻ�
	char movekey;//ũ���ƶ��������
	Sprite *farmer;
	Sprite *player;
	Sprite *hen;

	list<Sprite*> bullets;
	list<Sprite*> hens;
	list<Sprite*> eagles;
	list<Sprite*> eggs;
	list<Sprite*> clickeggs;
	cocos2d::Vector<SpriteFrame*> explore;
	Size visibleSize;
	Vec2 origin;
	Label* eggsNum; //��������
	Label* hensNum; // ĸ������
	int score;

	void addFarmer();
	void addHens(int num);
	void addEagle();
	void preloadMusic();
	void playBgm();

	void addTouchListener();
	void addKeyboardListener();
	void fire();
	void explosion();
	void lay(float a);//����µ�


	void meet(EventCustom* event);
	void meet2(EventCustom* event);
	void addCustomListener();
	void movePlayer(char c);
	bool onTouchBegan(Touch *touch, Event *unused_event);//���������
	void onTouchEnded(Touch *touch, Event *event);
	void onKeyPressed(EventKeyboard::KeyCode code, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode code, Event* event);
	void update(float f); //ʵʱ���¼�������ĸ����

	//��������ӵĺ����벹��������
	void win();
	// -----------------------
	bool dir;
	cocos2d::SpriteFrame* frame0;
	cocos2d::Sprite* eagleToCatch;
	cocos2d::Sprite* henToBeCatched;
	cocos2d::Vector<SpriteFrame*> walkFrame;
};

#endif // __GAME_Scene_H__

