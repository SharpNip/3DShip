#pragma once
#include "Sprite.h"
#include "Utils.h"
#include <stdio.h>

class Score
	: public Component
{
public:
	Score();
	~Score();

	void Update();
	void Draw();
	void IncrementScore(char* score);
	char* GetScoreAsString(float deltaTime);

private:
	char* scoreString;
	float currentScore;
	ID3DXFont* mFont;
};

