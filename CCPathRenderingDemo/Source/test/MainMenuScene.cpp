//
//  MainMenuScene.cpp
//  CCTextureTransform
//
//  Created by bman on 10/27/13.
//
//

#include "MainMenuScene.h"
#include "CCPathRenderingTestScene.h"


Scene* MainMenuScene::scene() {
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    MainMenuScene *layer = MainMenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

MainMenuScene::~MainMenuScene () {
}

bool MainMenuScene::init() {
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    
    auto menuLabel1 = LabelTTF::create("CCPathRendering", "Arial", 24);
    auto menuItem1 = MenuItemLabel::create(menuLabel1, [] (Ref*) {
        auto scene = CCPathRenderingTestScene::scene();
        Director::getInstance()->replaceScene(scene);
    });
    
    auto menu = Menu::create(menuItem1, nullptr);
    menu->alignItemsVerticallyWithPadding(125);
    menu->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(menu);
    
    return true;
}
