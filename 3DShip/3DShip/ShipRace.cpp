#include "ShipRace.h"

ShipRace::ShipRace()
	: mBaseCamPos(0, 0, 0)
	, mGameStarted(false)
	, mGameOver(false)
{
	// Load the needed assets
	LoadAssets();

	// Set the base camPos to the ...base cam pos....
	mBaseCamPos = gEngine->GetCamera()->GetCamPos();

	// Test for sprite on screen
	gEngine->GetCamera()->SetCamPos(D3DXVECTOR3(0, 0, -500));

	// Should be put in a startscreen class...TODO
	test = new Sprite(Texture::ID::TEST);
}

ShipRace::~ShipRace()
{
	// If the game is not started only delete the ncessary stuffs
	if (mGameStarted)
	{
		QuitGame();
	}
	else
	{
		delete test;
	}
	
}

void ShipRace::Start()
{

}

void ShipRace::Update()
{
	// Get the button to start the game, as the test sprite, should be put in the same class
	if (gDInput->keyPressed(DIK_Q) && !mGameStarted)
	{
		InitGame();
	}
}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}

// Init all the games variables
void ShipRace::InitGame()
{
	mGameStarted = true;
	gEngine->GetCamera()->SetCamPos(mBaseCamPos);
	test->SetVisible(false);
	ship = new Ship();
	tunnel = new Tunnel();
	score = new Score();
	obstacle = new Obstacle();
}

// Delete everything
void ShipRace::QuitGame()
{
	delete test;
	delete tunnel;
	delete score;
	delete ship;
	delete obstacle;
}

// Methods for the restart game
void ShipRace::RestartGame()
{
	
}

// Load the necessary assets
void ShipRace::LoadAssets()
{
	Textures->LoadTexture(Texture::ID::TEST, "E_Gold01.png");
}