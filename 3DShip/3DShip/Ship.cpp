#include "Ship.h"


Ship::Ship()
{
	HR(D3DXCreateCylinder(gD3DDevice, 10.f, 0.f, 5.f, 20, 20, &mShip, 0));
	HR(mShip->DrawSubset(0));
	SetPosition(gEngine->GetCamera()->GetCamPos().x, gEngine->GetCamera()->GetCamPos().y, gEngine->GetCamera()->GetCamPos().z + 10);
}


Ship::~Ship()
{
}
