#include "Title.h"

#include "raylib.h"

cTitle::cTitle(int nScreenWidth, int nScreenHeight)
	: m_nTitlePositionX((nScreenWidth / 2) - 128)
	, m_nTitlePositionY((nScreenHeight / 2) - 128)
{}

void cTitle::Draw() const
{
	DrawText("Baseball Card Game", m_nTitlePositionX - 40, m_nTitlePositionY, 40, BLACK);
	DrawText("Press [ENTER] to Start", m_nTitlePositionX - 40, m_nTitlePositionY + 50, 20, DARKGRAY);
}