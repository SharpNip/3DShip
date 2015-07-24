#pragma once
#include "Sprite.h"
#include "Utils.h"
#include <stdio.h>
#include "Ship.h"

class Score
	: public Component
{
public:
	Score();
	~Score();

	void Update();
	void Draw();
	// Checks the 
	void IncrementScore(float deltaTime);
	char* GetScoreAsString();

private:

	// Buffer for score displaying
	char scoreString[8];
	// Current score (temporarily linked to the game timer)
	float currentScore;
	// To be used to display the distance traveled.
	ID3DXFont* mFont;
};

