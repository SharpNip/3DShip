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

	void OnResetDevice();
	void OnLostDevice();

	void Update();
	void Draw();
	//Used to get the score from the player and add it to the current thing
	void IncrementScore(float deltaTime);
	char* GetScoreAsString();

private:
	RECT fontRect;
	// Buffer for score displaying
	char scoreString[300];
	// Current score (temporarily linked to the game timer)
	float currentScore;
	// To be used to display the distance traveled.
	ID3DXFont* mFont;
};

