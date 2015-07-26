#pragma once

#include "ResourceIDs.h"
#include "TriGrid.h"
#include "Tunnel.h"
#include "Ship.h"
#include "Score.h"
#include "Obstacle.h"

class ShipRace
	: public Component
{
public:
	// Ctor/Dtor
	ShipRace();
	~ShipRace();

	// Heritage methods
	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	// Private methods
	void InitGame();
	void QuitGame();
	void RestartGame();
	void LoadAssets();

	// Class needed to make the game
	Tunnel* tunnel;
	Ship* ship;
	Score* score;
	Obstacle* obstacle;
	Sprite *test;

	// Private variables
	D3DXVECTOR3 mBaseCamPos;
	bool mGameOver;
	bool mGameStarted;
};

