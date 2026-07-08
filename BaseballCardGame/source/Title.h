#pragma once

class cTitle
{
public:
	cTitle(int nScreenWidth, int nScreenHeight);

	void Draw() const;

private:
	int m_nTitlePositionX;
	int m_nTitlePositionY;
};