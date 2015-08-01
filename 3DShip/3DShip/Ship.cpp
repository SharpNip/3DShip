#include "Ship.h"

// Default Ctor
Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, mDirection(0, 0)
	, mStartPos(0, 0, 0)
	, mShipSize(2.5f, 2.5f, 1.0f)
	, mLastFramePos(0, 0)
	, mShipSpeed(START_SPEED)
	, mCollider(nullptr)
	, scoreboard(nullptr)
	, currentScore(0.f)
	, mIsDead(false)
{
	// Set the ID for collisison
	SetID(Components::ID::SHIP);

	// Set the ship to it<s base position
	mStartPos = D3DXVECTOR3(gEngine->GetCamera()->GetCamPos().x, gEngine->GetCamera()->GetCamPos().y - 10, gEngine->GetCamera()->GetCamPos().z + 20);

	// Set the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechShip");
	HR(mFx->SetTechnique(mhTech));

	// Set the start position for the ship
	SetPosition(mStartPos.x, mStartPos.y, mStartPos.z);

	// Scale of the ship
	SetScale(START_SCALE_X, START_SCALE_Y, START_SCALE_Z);

	// Create the collider and the score
	mCollider = new BoxCollider(this, mStartPos.x, mStartPos.y, mStartPos.z, mShipSize.x, mShipSize.y, mShipSize.z);
	scoreboard = new Score();
}

// Dtor
Ship::~Ship()
{
	// Delete all that needs to be here
	delete mCollider;
	mCollider = nullptr;
	delete scoreboard;
	scoreboard = nullptr;
}

// Handle the collisisons, then inputs and the score
void Ship::Update()
{
	float dt = gTimer->GetDeltaTime();

	CheckCollison();

	// Do what needs to be done for each input, check every frame
	HandleInput(dt);
	
	//Increments the score
	InceaseScore(dt);
}

//Increments the score and sends the value to the scoreboard
void Ship::InceaseScore(float distanceTraveled)
{
	currentScore += distanceTraveled;
	scoreboard->SetScore(currentScore);
}

// Handle all the inputs
void Ship::HandleInput(float dt)
{
	// Set the directions to 0
	mDirection.x = 0;
	mDirection.y = 0;
	
	// Set the right direction for the right keys pressed
	if (gDInput->keyDown(DIK_A))
	{
		mDirection.x = -1;
	}
	
	if (gDInput->keyDown(DIK_W))
	{
		mDirection.y = 1;
	}

	if (gDInput->keyDown(DIK_S))
	{
		mDirection.y = -1;
	}

	if (gDInput->keyDown(DIK_D))
	{
		mDirection.x = 1;
	}
	
	// Move the ship And "Clamp it", should have been two seperates methods...SORRY :'(
	Move(dt);
}

// MOv the ship on the screen 
void Ship::Move(float dt)
{
	// Store position in temporary variables
	float tempX = GetPosition().x;
	float tempY = GetPosition().y;

	// If the ship go over our boudaries
	if (abs(sqrt((GetPosition().x * GetPosition().x) + (GetPosition().y * GetPosition().y))) >= BOUNDARIES)
	{
		// Set the position to the last good frame
		SetPosition(mLastFramePos.x, mLastFramePos.y, GetPosition().z);
		tempX = GetPosition().x;
		tempY = GetPosition().y;

		// Depending on what  input you press ut will slide along the border of the screen
		// Almost working...lack of time :s
		if (mDirection.x == 1)
		{
			mDirection.y = -1;
		}

		else if (mDirection.x == -1)
		{
			mDirection.y = 1;
		}

		else if (mDirection.y == 1)
		{
			mDirection.x = -1;
		}

		else if (mDirection.y == -1)
		{
			mDirection.x = 1;
		}

		// Set it's position with the new direction
		SetPosition(tempX -= mDirection.x * mShipSpeed * dt, tempY -= mDirection.y * mShipSpeed * dt, GetPosition().z);

	}

	// If the ship is inside the boundaries
	else if (abs(sqrt((GetPosition().x * GetPosition().x) + (GetPosition().y * GetPosition().y))) <= BOUNDARIES)
	{
		// Set the variable of the last correct frame and it's speed back to normal
		mLastFramePos = D3DXVECTOR2(GetPosition().x, GetPosition().y);
		SetPosition(tempX += mDirection.x * mShipSpeed * dt, tempY += mDirection.y * mShipSpeed * dt, GetPosition().z);
	}

	// Move thecollider accordingly to the ship
	mCollider->SetPosition(GetPosition().x - 1.5f, GetPosition().y - 1.5f, GetPosition().z);
}

// Look for collision
void Ship::CheckCollison()
{
	for each(Collider3D *col in mCollider->LookForCollisions())
	{
		// If we get hit by an obstcale
		if(col->GetGameObject()->GetID() == Components::OBSTACLE)
		{
			// We die
			mIsDead = true;
		}
	}
}

// Method to desactivate the ship
void Ship::Kill()
{
	// Reset all the values to their base value, and set all Innactive
	mIsDead = false;
	SetPosition(mStartPos.x, mStartPos.y, mStartPos.z);
	currentScore = 0.f;
	SetActive(false);
	scoreboard->SetActive(false);
}

// Method to activate the ship
void Ship::Activate()
{
	// Sett all to active again and revive the ship =)
	scoreboard->SetActive(true);
	mIsDead = false;
	SetActive(true);
}


