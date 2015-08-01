#pragma once
#include "Sprite.h"
#include "Utils.h"
#include <stdio.h>

////////////////////////////////////////////////////////////////
// Score Class:
//		-> This class takes care of creating a score at the bottom
//			right of the screen, and updates using the ship's score
////////////////////////////////////////////////////////////////////
class Score
	: public Component
{
public:
	// Default constructor and Dtor
	Score();
	~Score();

	// Inherited functions from Component
	void OnResetDevice();
	void OnLostDevice();
	void Draw();

	//Used by Ship to set the current score
	void SetScore(float score);
	
private:
	// Private method to produce a c-style string that can be used by the ID3DXFont
	char* MakeScoreString();

	// The rectangle used to display the font
	RECT fontRect;

	// Buffer for score displaying
	char scoreString[300];
	
	// Current score 
	float currentScore;
	
	// To be used to display the distance traveled.
	ID3DXFont* mFont;
};

