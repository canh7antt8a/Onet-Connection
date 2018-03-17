//
//  PopupGame.cpp
//  PikachuConnection
//
//  Created by Hoang Nguyen on 11/15/16.
//
//

#include "PopupGame.h"
#include "SimpleAudioEngine.h"
PopupGame::PopupGame()
{
    
}
PopupGame::~PopupGame()
{
    
}
void PopupGame::createLayoutWithZorder()
{
    auto touch = EventListenerTouchOneByOne::create();
    touch->setSwallowTouches(true);
    touch->onTouchBegan = [](Touch* ptouch, Event* mEvent){
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touch, this);

}

Size PopupGame::sizeOfPopup()
{
    return sizePopup;
}

void PopupGame::createPopupWithbuttonWithFileName(const char* fileButton, const Vec2& pos, int tag)
{
    ui::Button* temp = ui::Button::create(fileButton,"","",cocos2d::ui::Widget::TextureResType::LOCAL);
    temp->setPosition(pos);
    temp->setTag(tag);
    temp->addClickEventListener(CC_CALLBACK_1(PopupGame::btnClickPopup,this));
    this->addChild(temp,100);
    
}
void PopupGame::createUibackGroundWithFileName(const char* fileName)
{
    
    Sprite* backgroundPopup = Sprite::create(fileName);
    backgroundPopup->setPosition(Vec2(Director::getInstance()->getWinSize().width/2, Director::getInstance()->getWinSize().height/2));
    this->addChild(backgroundPopup,99);
    sizePopup = backgroundPopup->getContentSize();
    
}
void PopupGame::setTypePopup(int type)
{
    
}
void PopupGame::btnClickPopup(Ref* psender)
{
     CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("soundClick.mp3");
    int tag = ((ui::Button*) psender)->getTag();
    if(delegate)
    {
        delegate->sendTagActionPopup(tag);
    }
}
void PopupGame::setdelegate(DelegateEventPopup* mdelegate)
{
    this->delegate = mdelegate;
}
void PopupGame::setLabelPopup(Label* label)
{
    this->addChild(label,100);
}
