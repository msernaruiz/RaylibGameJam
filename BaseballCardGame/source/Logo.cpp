#include "Logo.h"

#include "raylib.h"

cLogo::cLogo(int nScreenWidth, int nScreenHeight)
    : m_bFinished(false)
    , m_nLogoPositionX((nScreenWidth / 2) - 128)
    , m_nLogoPositionY((nScreenHeight / 2) - 128)
    , m_nFramesCounter(0)
    , m_nLettersCount(0)
    , m_nTopSideRecWidth(16)
    , m_nLeftSideRecHeight(16)
    , m_nBottomSideRecWidth(16)
    , m_nRightSideRecHeight(16)
    , m_nState(0)
    , m_fAlpha(1.0f)
{}

void cLogo::Update()
{
    switch(m_nState)
    {
        case 0: // Small box blinking
        {
            ++m_nFramesCounter;

            if(m_nFramesCounter == 120)
            {
                m_nState = 1;
                m_nFramesCounter = 0;
            }
        }
        break;

        case 1: // Top and left bars growing
        {
            m_nTopSideRecWidth += 4;
            m_nLeftSideRecHeight += 4;

            if(m_nTopSideRecWidth == 256)
            {
                m_nState = 2;
            }
        }
        break;

        case 2: // Bottom and right bars growing
        {
            m_nBottomSideRecWidth += 4;
            m_nRightSideRecHeight += 4;

            if(m_nBottomSideRecWidth == 256)
            {
                m_nState = 3;
            }
        }
        break;
        case 3: // Letters appearing
        {
            ++m_nFramesCounter;

            if(m_nFramesCounter / 12)
            {
                ++m_nLettersCount;
                m_nFramesCounter = 0;
            }

            if(m_nLettersCount >= 10)
            {
                m_fAlpha -= 0.02f;

                if(m_fAlpha <= 0.0f)
                {
                    m_fAlpha = 0.0f;
                    m_nState = 4;
                }
            }
        }
        break;

        case 4: // Logo Finished
        {
            m_bFinished = true;
        }
        break;
    }
}

void cLogo::Draw() const
{
    switch(m_nState)
    {
        case 0:
        {
            if((m_nFramesCounter / 15) % 2)
            {
                DrawRectangle(m_nLogoPositionX, m_nLogoPositionY, 16, 16, BLACK);
            }
        }
        break;

        case 1:
        {
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY, m_nTopSideRecWidth, 16, BLACK);
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY, 16, m_nLeftSideRecHeight, BLACK);
        }
        break;

        case 2:
        {
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY, m_nTopSideRecWidth, 16, BLACK);
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY, 16, m_nLeftSideRecHeight, BLACK);
            DrawRectangle(m_nLogoPositionX + 240, m_nLogoPositionY, 16, m_nRightSideRecHeight, BLACK);
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY + 240, m_nBottomSideRecWidth, 16, BLACK);
        }
        break;

        case 3:
        {
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY, m_nTopSideRecWidth, 16, Fade(BLACK, m_fAlpha));
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY + 16, 16, m_nLeftSideRecHeight - 32, Fade(BLACK, m_fAlpha));
            DrawRectangle(m_nLogoPositionX + 240, m_nLogoPositionY + 16, 16, m_nRightSideRecHeight - 32, Fade(BLACK, m_fAlpha));
            DrawRectangle(m_nLogoPositionX, m_nLogoPositionY + 240, m_nBottomSideRecWidth, 16, Fade(BLACK, m_fAlpha));
            DrawRectangle(GetScreenWidth() / 2 - 112, GetScreenHeight() / 2 - 112, 224, 224, Fade(RAYWHITE, m_fAlpha));
            DrawText(TextSubtext("raylib", 0, m_nLettersCount), GetScreenWidth() / 2 - 44, GetScreenHeight() / 2 + 48, 50, Fade(BLACK, m_fAlpha));
        }
        break;
    }
}