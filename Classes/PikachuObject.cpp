//
//  PikachuObject.cpp
//  PikachuConnect
//
//  Created by NguyenHoang on 8/18/16.
//
//

#include "PikachuObject.h"
#include "GameDefine.h"
#define MAX_ARRAY 36
enum{
    z_Order_bgNode = 0,
    z_Order_Character = 1,
};

static std::string foodAnimaltileName[MAX_ARRAY] = {"foodAnimal1.png","foodAnimal2.png","foodAnimal3.png","foodAnimal4.png","foodAnimal5.png","foodAnimal6.png","foodAnimal7.png","foodAnimal8.png","foodAnimal9.png","foodAnimal10.png","foodAnimal11.png","foodAnimal12.png","foodAnimal13.png","foodAnimal14.png","foodAnimal15.png","foodAnimal16.png","foodAnimal17.png","foodAnimal18.png","foodAnimal19.png","foodAnimal20.png","foodAnimal21.png","foodAnimal22.png","foodAnimal23.png","foodAnimal24.png","foodAnimal25.png","foodAnimal26.png","foodAnimal27.png","foodAnimal28.png","foodAnimal29.png","foodAnimal30.png","foodAnimal31.png","foodAnimal32.png","foodAnimal33.png","foodAnimal34.png","foodAnimal35.png","foodAnimal36.png"};

PikachuObject::PikachuObject()
{
    
}
PikachuObject::~PikachuObject()
{
    
}

void PikachuObject::runActionStartGame()
{
    
}


void PikachuObject::createUIObject()
{
    bgNode = Sprite::create("bgAnimal1.png");
    bgNode->setPosition(this->getPosition());
    this->addChild(bgNode,z_Order_bgNode);
    character = Sprite::createWithSpriteFrameName(foodAnimaltileName[type]);
    character->setPosition(Vec2(this->getPosition().x - 10, this->getPosition().y + 10));
    character->setScale(0.8);
    this->addChild(character,z_Order_Character);
    if (valueVisiable == TAG_PIKACHU_VISIABLE)
    {
        character->setVisible(true);
        bgNode->setVisible(true);
    }
    else
    {
        character->setVisible(false);
        bgNode->setVisible(false);
    }
}
void PikachuObject::updateUI(int type)
{
    
    if(character)
    {
        character->setSpriteFrame(foodAnimaltileName[type]);
    }
}
void PikachuObject::setTagObject(int tagObject)
{
    this->tagObject = tagObject;
}
int PikachuObject::getTagObject()
{
    return tagObject;
}

void PikachuObject::actionWhenClick()
{
    auto action1 = ScaleTo::create(0.08f, 0.8f);
    auto action2 = DelayTime::create(0.02f);
    auto sequence = Sequence::create(action1, action2, NULL);
    bgNode->runAction(sequence);
}
void PikachuObject::effectWhenDieObject()
{
    bgNode->setVisible(false);
    character->setVisible(false);
}
void PikachuObject::backToStartObject()
{
    bgNode->runAction(ScaleTo::create(0.1f, 1.0f));
}

void PikachuObject::hidePikachu()
{
    bgNode->setVisible(false);
    character->setVisible(false);
}
void PikachuObject::updateNewPosition(const Vec2& position)
{
    this->setPosition(position);
    if(bgNode)
    {
        bgNode->setPosition(this->getPosition());
    }
    if(character)
    {
        character->setPosition(Vec2(this->getPosition().x - 10, this->getPosition().y + 10));
    }
}
void PikachuObject::setValueVisiable(int valueVisiable)
{
    this->valueVisiable = valueVisiable;
}
int PikachuObject::getValueVisiable()
{
    return valueVisiable;
}
void PikachuObject::update(float dt)
{
    if(this->getValueVisiable() ==  TAG_PIKACHU_HIDDEN)
    {
        bgNode->setVisible(false);
        character->setVisible(false);
    }
    else
    {
        bgNode->setVisible(true);
        character->setVisible(true);
    }
}

void PikachuObject::onEnter()
{
    Node::onEnter();
}
void PikachuObject::onExit()
{
    Node::onExit();
}
void PikachuObject::setVisiableSprite()
{
    if(bgNode->isVisible() == false)
    {
        bgNode->setVisible(true);
    }
    if(character->isVisible() == false)
    {
        character->setVisible(true);
    }
}
void PikachuObject::updateZorder(int newZoder)
{
    
}

void PikachuObject::objectWhenPause()
{
    
    if(bgNode)
    {
        bgNode->setLocalZOrder(10001);
    }
    if(character)
    {
        character->setLocalZOrder(10000);
    }
    
}
void PikachuObject::objectWhenPlay()
{
    
    if(bgNode)
    {
        bgNode->setLocalZOrder(10000);
    }
    if(character)
    {
        character->setLocalZOrder(10001);
    }
    
}


