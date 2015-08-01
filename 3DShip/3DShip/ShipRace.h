#pragma once

#define CAM_POS gEngine->GetCamera()->GetCamPos()

#include "ResourceIDs.h"
#include "TriGrid.h"
#include "Tunnel.h"
#include "Ship.h"
#include "Obstacle.h"

///////////////////////////////////////////////////////////
// ShipRace Class:
//		-> This is the main class where the game takes form
//			This is where we check the game states and the gameOver and such
//			
/////////////////////////////////////////////////////////////////
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
	void GameOver();
	void RestartGame();
	void LoadAssets();
	void InitCamera();

	// Class needed to make the game
	Tunnel* tunnel;
	Ship* ship;
	Obstacle* obstacle;
	Sprite* title;

	// Private variables
	D3DXVECTOR3 mBaseCamPos;
	D3DXVECTOR3 mScreenCamPos;
	bool mGameOver;
	bool mGameStarted;
	float screenPosition;
};

