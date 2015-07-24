#include "Ship.h"


Ship::Ship()
	:PrimitiveModel(PrimitiveModel_Type::CYLINDER)
{
	SetPosition(gEngine->GetCamera()->GetCamPos().x, gEngine->GetCamera()->GetCamPos().y, gEngine->GetCamera()->GetCamPos().z + 10);
	SetScale(2.f, 1.f, 1.f);
}

Ship::~Ship()
{

}

void Ship::HandleInput()
{
	//if(DIK_A)
	//
	//if ()
	//{
	//
	//}
}

void Ship::Move()
{

}

void Ship::OnCollision()
{

}

