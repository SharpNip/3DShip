#include "ShipRace.h"

// Default Ctor
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
	
	// Setup of a "StartScreen"
	title = new Sprite(Texture::ID::TITLE);
	title->SetPosition(-screenPosition, screenPosition);
	title->SetRotationDeg(0, 180.f, 0);
}

// Dtor
ShipRace::~ShipRace()
{
	// If the game is not started only delete the necessary stuffs
	if (mGameStarted)
	{
		// Delete everything
		QuitGame();
	}
	else
	{
		// Delete titlescren
		delete title;
	}
}

// Handle the gameflow, start, restartm die...etc.
void ShipRace::Update()
{
	// Get the button to start the game if the game is not already started...Meh !
	if (gDInput->keyPressed(DIK_SPACE) && !mGameStarted)
	{
		// Init the game
		InitGame();
	}
	
	// If gameOver...
	if (!mGameOver)
	{
		// and the game is started...
		if (mGameStarted)
		{
			// and the ship is dead
			if (ship->GetIsDead())
			{
				// Gameover !
				GameOver();
			}
		}
	}
	// Else if space is pressed and it is gameover
	else if (gDInput->keyPressed(DIK_SPACE) && mGameOver)
	{
		// Restart the game
		RestartGame();
	}
	
}

// Init all the games variables
void ShipRace::InitGame()
{
	mGameOver = false;
	mGameStarted = true;
	gEngine->GetCamera()->SetCamPos(mBaseCamPos);
	title->SetVisible(false);
	ship = new Ship();
	tunnel = new Tunnel();
	obstacle = new Obstacle();
}

// Delete everything
void ShipRace::QuitGame()
{
	delete title;
	title = nullptr;
	delete tunnel;
	tunnel = nullptr;
	delete ship;
	ship = nullptr;
	delete obstacle;
	obstacle = nullptr;
}

// Method for the gameOver
void ShipRace::GameOver()
{
	mGameOver = true;
	gEngine->GetCamera()->SetCamPos(mScreenCamPos);
	title->SetVisible(true);
	ship->Kill();
	obstacle->Kill();
	tunnel->SetActive(false);
}

// Method to restart the game
void ShipRace::RestartGame()
{
	mGameOver = false;
	gEngine->GetCamera()->SetCamPos(mBaseCamPos);
	title->SetVisible(false);
	ship->Activate();
	obstacle->Activate();
	tunnel->SetActive(true);
}


// Load the necessary assets
void ShipRace::LoadAssets()
{
	Textures->LoadTexture(Texture::ID::TITLE, "Starfox.png");
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