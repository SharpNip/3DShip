#include "Score.h"

// Default constructor to create the score on the screen
Score::Score()
	: mFont(nullptr)
	, currentScore(0.0f)
{
	D3DXFONT_DESC fontDesc;
	fontDesc.Height = 30;
	fontDesc.Width = 30;
	fontDesc.MipLevels = 0;
	fontDesc.Italic = false;
	fontDesc.CharSet = DEFAULT_CHARSET;
	fontDesc.OutputPrecision = OUT_DEFAULT_PRECIS;
	fontDesc.PitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;
	fontDesc.Quality = DEFAULT_QUALITY;
	strcpy_s(fontDesc.FaceName, _T("Times New Roman"));
	D3DXCreateFontIndirect(gD3DDevice, &fontDesc, &mFont);
}
// Destructor that gets releases the ID3DXFont
Score::~Score()
{
	ReleaseCOM(mFont);
}
// Necessary function to avoid crashing at runtime
void Score::OnResetDevice()
{
	HR(mFont->OnResetDevice());
}
// Necessary function to avoid crashing at runtime
void Score::OnLostDevice()
{
	HR(mFont->OnLostDevice());
}
// Draws the text on screen using DX's draw text function
void Score::Draw()
{
	::GetClientRect(gApp->GetMainWindow(), &fontRect);
	mFont->DrawTextA(0, _T(MakeScoreString()), 4, 
		&fontRect, DT_LEFT | DT_BOTTOM | DT_SINGLELINE, D3DCOLOR_XRGB(1, 1, 1));
}
// Function that uses the sprintf function to create a c-style string to "push" to the drawtext function
// snprintf could not be used.
char* Score::MakeScoreString()
{
	sprintf(scoreString, "%f", currentScore);
	return scoreString;
}
// Used by Ship to set the float in this class to its current value
void Score::SetScore(float distanceTraveledFromShip)
{
	currentScore = distanceTraveledFromShip;
}