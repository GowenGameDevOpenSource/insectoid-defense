//
//  DSGameScreen.cpp
//  tappyplane
//
//  Created by Stephen Gowen on 8/20/15.
//  Copyright (c) 2015 Gowen Game Dev. All rights reserved.
//

#include "DSGameScreen.h"
#include "TouchEvent.h"
#include "Vector2D.h"
#include "DSRenderer.h"
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

#include <3ds.h>

#include <string.h>

DSGameScreen::DSGameScreen(int levelIndex, int difficulty, int topScreenWidth, int topScreenHeight, int bottomScreenWidth, int bottomScreenHeight) : GameScreen(levelIndex, difficulty)
{
    m_renderer = std::unique_ptr<DSRenderer>(new DSRenderer(GFX_BOTTOM, bottomScreenWidth, bottomScreenHeight));

    m_iTopScreenWidth = topScreenWidth;
    m_iTopScreenHeight = topScreenHeight;
    m_iBottomScreenWidth = bottomScreenWidth;
    m_iBottomScreenHeight = bottomScreenHeight;
}

void DSGameScreen::touchToWorld(TouchEvent &touchEvent)
{
    float x = (touchEvent.getX() / (float) m_iBottomScreenWidth) * GAME_WIDTH;
    float y = (((float) m_iBottomScreenHeight) - touchEvent.getY()) / ((float) m_iBottomScreenHeight) * GAME_HEIGHT;

    m_touchPoint->set(x, y);
}

void DSGameScreen::platformResume()
{
    // Empty
}

void DSGameScreen::platformPause()
{
    // Empty
}

void DSGameScreen::exit()
{
    m_renderer->cleanUp();
}