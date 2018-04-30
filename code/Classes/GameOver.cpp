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

	//添加用户名

	//添加Logout按钮（类似于开始界面的start)

	//添加continue按钮（类似于开始界面的start）

	//加载score

	//提交按钮

	//排名按钮

}

// 点击提交按钮
void GameOver::submitCallback(Ref* sender) {

}

//// 点击排名按钮,最多查询前10名,默认查前十名,
void GameOver::rankCallback(Ref * sender) {

}

// 清空username,返回开始界面
void GameOver::logoutCallback(Ref * sender) {
	database->setStringForKey("username", ""); 
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.3f, MenuScene::createScene()));
}

//返回游戏界面，继续游戏
void GameOver::continueCallback(Ref * pSender) {
	Director::getInstance()->replaceScene(TransitionCrossFade::create(0.4f, GameScene::createScene()));
}

// 提交响应函数,如果成功提交则更新排名
void GameOver::onsubmitCompleted(HttpClient* sender, HttpResponse* res) {

}

// 排名响应函数,成功则显示前n名排名
void GameOver::onrankCompleted(HttpClient* sender, HttpResponse* res) {

}
