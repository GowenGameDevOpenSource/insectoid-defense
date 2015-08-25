//
//  IOS8OpenGLESGameScreen.cpp
//  insectoid-defense
//
//  Created by Stephen Gowen on 7/22/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include "IOS8OpenGLESGameScreen.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "OpenGLESRenderer.h"
#include "OpenGLESManager.h"
#include "GameConstants.h"
#include "SpriteBatcher.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Font.h"
#include "RectangleBatcher.h"
#include "LineBatcher.h"
#include "CircleBatcher.h"
#include "BackgroundElements.h"
#include "TimeButton.h"
#include "Dialog.h"
#include "TouchCursor.h"
#include "Text.h"
#include "Asteroid.h"
#include "ShipModule.h"
#include "CoreShipModule.h"
#include "TowerCursor.h"
#include "TowerOptionButton.h"

IOS8OpenGLESGameScreen::IOS8OpenGLESGameScreen(int levelIndex, int difficulty, int screenWidth, int screenHeight, int pointsWidth, int pointsHeight) : IOSOpenGLESGameScreen(levelIndex, difficulty, screenWidth, screenHeight, pointsWidth, pointsHeight)
{
    // Empty
}

void IOS8OpenGLESGameScreen::touchToWorld(TouchEvent &touchEvent)
{
    m_touchPoint->set((touchEvent.getX() / (float) m_iPointsWidth) * GAME_WIDTH, (1 - touchEvent.getY() / (float) m_iPointsHeight) * GAME_HEIGHT);
}