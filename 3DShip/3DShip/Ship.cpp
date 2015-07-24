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
	if (DIK_A)
	{
		//mDirection.x = -1;
		SetDirection(D3DXVECTOR2(-1, 0));
	}
	
	if (DIK_W)
	{
		//mDirection.y = 1;
		SetDirection(D3DXVECTOR2(0, 1));
	}

	if (DIK_S)
	{
		//mDirection.x = -1;
		SetDirection(D3DXVECTOR2(0, -1));
	}

	if (DIK_D)
	{
		//mDirection.x = 1;
		SetDirection(D3DXVECTOR2(1, 0));
	}
	
	std::cout << "DIRECTIONX: " << mDirection.x << std::endl;
	std::cout << "DIRECTIONY: " << mDirection.y << std::endl;
	Move(mDirection, dt);
}

void Ship::Move(D3DXVECTOR2 dir, float dt)
{
	SetPosition(GetPosition().x * mDirection.x * SHIP_SPEED, GetPosition().y * mDirection.y * SHIP_SPEED, GetPosition().z);
}

void Ship::OnCollision()
{

}
void Ship::SetDirection(D3DXVECTOR2 dir)
{
	mDirection = dir;
}


