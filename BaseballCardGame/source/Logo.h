#pragma once

class cLogo
{
public:
    cLogo(int nScreenWidth, int nScreenHeight);

    bool IsFinished() const { return m_bFinished; }

    void Draw() const;
    void Update();

private:
    bool m_bFinished;

    int m_nLogoPositionX;
    int m_nLogoPositionY;
    int m_nFramesCounter;
    int m_nLettersCount;
    int m_nTopSideRecWidth;
    int m_nLeftSideRecHeight;
    int m_nBottomSideRecWidth;
    int m_nRightSideRecHeight;
    int m_nState;

    float m_fAlpha;
};
