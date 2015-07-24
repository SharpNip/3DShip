#include "Ship.h"


Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CONE)
	, mDirection(0, 0)
	, mTether(0, 0, 0)
	, SHIP_SPEED(30)

{
	mTether = D3DXVECTOR3(gEngine->GetCamera()->GetCamPos().x, gEngine->GetCamera()->GetCamPos().y, gEngine->GetCamera()->GetCamPos().z + 20);

	// Set the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechShip");
	HR(mFx->SetTechnique(mhTech));

	// Set the start position for the ship
	SetPosition(mTether.x, mTether.y, mTether.z);
	// Scale of the ship
	SetScale(START_SCALE_X, START_SCALE_Y, START_SCALE_Z);
}

Ship::~Ship()
{


}

void Ship::Update()
{
	float dt = gTimer->GetDeltaTime();
	
	HandleInput(dt);
}

void Ship::HandleInput(float dt)
{
	mDirection.x = 0;
	mDirection.y = 0;

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
	Move(mDirection, dt);
}

void Ship::Move(D3DXVECTOR2 dir, float dt)
{
	float tempX = GetPosition().x;
	float  tempY = GetPosition().y;

	if (abs(sqrt((GetPosition().x * GetPosition().x) + (GetPosition().y * GetPosition().y))) >= 4)
	{
		SetPosition(tempX -= mDirection.x * SHIP_SPEED * dt, tempY -= mDirection.y * SHIP_SPEED * dt, GetPosition().z);
	}
	else
	{
		SetPosition(tempX += mDirection.x * SHIP_SPEED * dt, tempY += mDirection.y * SHIP_SPEED * dt, GetPosition().z);
	}

	
}

void Ship::OnCollision()
{

}


