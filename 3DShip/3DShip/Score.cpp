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
	float deltaTime = gTimer->GetDeltaTime();
	
	GetScoreAsString(deltaTime);

}

void Score::Draw()
{
	RECT fontRect;
	::GetClientRect(gApp->GetMainWindow(), &fontRect);
	mFont->DrawTextA(0, _T(scoreString), -1, &fontRect, DT_LEFT | DT_BOTTOM | DT_SINGLELINE, D3DCOLOR_XRGB(255, 255, 255));
}

char* Score::GetScoreAsString(float deltaTime)
{
	scoreString = "DEFAULT_SCORE";
	return scoreString;
}
