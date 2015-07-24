#include "Score.h"


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

Score::~Score()
{
	ReleaseCOM(mFont);
}

void Score::Update()
{
	float deltaTime = gTimer->GetGameTime();
	
	IncrementScore(deltaTime);
	GetScoreAsString();
}

void Score::Draw()
{
	RECT fontRect;
	::GetClientRect(gApp->GetMainWindow(), &fontRect);
	mFont->DrawTextA(0, _T(strcat(GetScoreAsString(), "km")), -1, 
		&fontRect, DT_LEFT | DT_BOTTOM | DT_SINGLELINE, D3DCOLOR_XRGB(1, 1, 1));
}

char* Score::GetScoreAsString()
{
	sprintf(scoreString, "%f", currentScore);
	return scoreString;
	
}

void Score::IncrementScore(float deltaTime)
{
	currentScore = deltaTime;
}