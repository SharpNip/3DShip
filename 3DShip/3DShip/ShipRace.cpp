#include "ShipRace.h"

ShipRace::ShipRace()
	: mBaseCamPos(0, 0, 0)
	, mGameStarted(false)
	, mGameOver(false)
	, mScreenCamPos(0, 0, -1000)
	, screenPosition(500)
{
	// Load the needed assets
	LoadAssets();
	
	// Initialize the camera of the game
	InitCamera();
	
	// Should be put in a startscreen class...TODO
	test = new Sprite(Texture::ID::TEST);
	test->SetPosition(-screenPosition, screenPosition);
	test->SetRotationDeg(0, 180.f, 0);
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
	if (gDInput->keyPressed(DIK_SPACE) && !mGameStarted)
	{
		InitGame();
	}
	
	if (mGameStarted)
	{
		if (ship->GetIsDead() && !mGameOver)
		{
			GameOver();
		}
	}
	
	if (mGameOver && gDInput->keyPressed(DIK_Q) && mGameStarted)
	{
		RestartGame();
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
	obstacle = new Obstacle();
}

// Delete everything
void ShipRace::QuitGame()
{
	delete test;
	test = nullptr;
	delete tunnel;
	tunnel = nullptr;
	delete ship;
	ship = nullptr;
	delete obstacle;
	obstacle = nullptr;
}

// Methods for the restart game
void ShipRace::GameOver()
{
	gEngine->GetCamera()->SetCamPos(mScreenCamPos);
	mGameOver = true;
	test->SetVisible(true);
	ship->Kill();
	obstacle->Kill();
	tunnel->SetActive(false);
}

void ShipRace::RestartGame()
{
	gEngine->GetCamera()->SetCamPos(mBaseCamPos);
	mGameOver = false;
	test->SetVisible(false);
	ship->Activate();
	obstacle->Activate();
	tunnel->SetActive(true);
}


// Load the necessary assets
void ShipRace::LoadAssets()
{
	Textures->LoadTexture(Texture::ID::TEST, "Starfox.png");
}

void ShipRace::InitCamera()
{
	// Set the base camPos to the ...base camera position....
	D3DXVECTOR3 temp = CAM_POS;
	temp.y += 5;
	mBaseCamPos = temp;
	
	// Test for sprite on screen
	gEngine->GetCamera()->SetCamPos(mScreenCamPos);
}