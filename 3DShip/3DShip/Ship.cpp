#include "Ship.h"


Ship::Ship()
	: PrimitiveModel(PrimitiveModel_Type::CYLINDER)
	, mDirection(0, 0)
	, SHIP_SPEED(50)
{
	SetPosition(gEngine->GetCamera()->GetCamPos().x, gEngine->GetCamera()->GetCamPos().y, gEngine->GetCamera()->GetCamPos().z + 20);
	SetScale(2.f, 1.f, 1.f);
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
	mDirection = D3DXVECTOR2(0, 0);
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
	SetPosition(tempX += mDirection.x * SHIP_SPEED * dt, tempY += mDirection.y * SHIP_SPEED * dt , GetPosition().z);
}

void Ship::OnCollision()
{

}
void Ship::SetDirection(D3DXVECTOR2 dir)
{
	mDirection = dir;
}


