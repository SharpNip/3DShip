#include "Tunnel.h"

Tunnel::Tunnel()
	: PrimitiveModel(PrimitiveModel_Type::CYLINDER)
	, mPos(0.f, 0.f, 0.f)
	, TUNNEL_SPEED(0.1f)
	// Leave this 0.9 so the tunnel doesn't flicker.
	, RESET_POS(100.f)
{
	// Set the size of the tunnel.
	SetScale(SCALE_X, SCALE_Y, SCALE_Z);

	// Set the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechTunnel");
	HR(mFx->SetTechnique(mhTech));
}

Tunnel::~Tunnel()
{
	
}

void Tunnel::Update()
{
	// Move the tunnel with his z position.
	MoveTunnel();
}

void Tunnel::MoveTunnel()
{
	// Update the new position of the tunnel.
	mPos.z += TUNNEL_SPEED;
	SetPosition(mPos.x, mPos.y, mPos.z + TUNNEL_SPEED);

	// If the position reaches the reset pos, returns the tunnel to 0.
	if (mPos.z >= RESET_POS)
	{
		mPos.z = 0;
	}
}