#include "Ship.h"

Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, mDirection(0, 0)
	, mStartPos(0, 0, 0)
	, mLastFramePos(0, 0)
	, mShipSpeed(START_SPEED)

{
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
	mCollider = new BoxCollider(this, mStartPos.x, mStartPos.y, mStartPos.z, 3, 3, 3);
}

Ship::~Ship()
{
	delete mCollider;
	mCollider = nullptr;
}

void Ship::Update()
{
	float dt = gTimer->GetDeltaTime();

	// Do what need to be done for each input, check every frame
	HandleInput(dt);
}

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
	
	//std::cout << "DIRECTIONX: " << mDirection.x << std::endl;
	//std::cout << "DIRECTIONY: " << mDirection.y << std::endl;
	// Move the ship in the good direction
	Move(dt);
}

void Ship::Move(float dt)
{
	// Store position in temporary variables
	float tempX = GetPosition().x;
	float tempY = GetPosition().y;

	// If the ship go over our boudaries
	if (abs(sqrt((GetPosition().x * GetPosition().x) + (GetPosition().y * GetPosition().y))) >= BOUNDARIES)
	{
		SetPosition(mLastFramePos.x, mLastFramePos.y, GetPosition().z);
		tempX = GetPosition().x;
		tempY = GetPosition().y;

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

		SetPosition(tempX -= mDirection.x * mShipSpeed * dt, tempY -= mDirection.y * mShipSpeed * dt, GetPosition().z);
		// Set it's speed to 0
		//mShipSpeed = 0;
		// Set it's position to the lasttime he was inside the boundaries

	}
	// If the ship is inside the boundaries
	
	else if (abs(sqrt((GetPosition().x * GetPosition().x) + (GetPosition().y * GetPosition().y))) <= BOUNDARIES)
	{
		// Set the variable of the last correct frame and it's speed back to normal
		mLastFramePos = D3DXVECTOR2(GetPosition().x, GetPosition().y);
		mShipSpeed = START_SPEED;
		SetPosition(tempX += mDirection.x * mShipSpeed * dt, tempY += mDirection.y * mShipSpeed * dt, GetPosition().z);
	}	
}

void Ship::OnCollision()
{
	// TODO if needed to do something on collision
}

void Ship::Kill()
{
	SetPosition(mStartPos.x, mStartPos.y, mStartPos.z);
	SetActive(false);
}

void Ship::Activate()
{
	SetActive(true);
}


