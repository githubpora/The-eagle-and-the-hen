#include "GameOver.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "network/HttpClient.h"
#include "json/rapidjson.h"
#include "json/document.h"

#define database UserDefault::getInstance()
USING_NS_CC;

using namespace cocos2d::network;

Scene* GameOver::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOver::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameOver::init() {
	if (!Layer::init()) {
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto visibleHeight = visibleSize.height;
	auto visibleWidth = visibleSize.width;
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("gameOver.png");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(background, 0);

	//����û���

	//���Logout��ť�������ڿ�ʼ�����start)

	//���continue��ť�������ڿ�ʼ�����start��

	//����score

	//�ύ��ť

	//������ť

}

// ����ύ��ť
void GameOver::submitCallback(Ref* sender) {

}

//// ���������ť,����ѯǰ10��,Ĭ�ϲ�ǰʮ��,
void GameOver::rankCallback(Ref * sender) {

}

// ���username,���ؿ�ʼ����
void GameOver::logoutCallback(Ref * sender) {
	database->setStringForKey("username", ""); 
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3f, MenuScene::createScene()));
}

//������Ϸ���棬������Ϸ
void GameOver::continueCallback(Ref * pSender) {
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.4f, GameScene::createScene()));
}

// �ύ��Ӧ����,����ɹ��ύ���������
void GameOver::onsubmitCompleted(HttpClient* sender, HttpResponse* res) {

}

// ������Ӧ����,�ɹ�����ʾǰn������
void GameOver::onrankCompleted(HttpClient* sender, HttpResponse* res) {

}
