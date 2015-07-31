#include "Tunnel.h"



// Default constructor, creating a cylinder to produce the "tunnel" effect
Tunnel::Tunnel()
	: PrimitiveModel(PrimitiveModel_Type::CYLINDER)
	, mPos(0.f, 0.f, 0.f)
	, TUNNEL_SPEED(0.1f)
	, RESET_POS(100.f)
{
	// Sets the size of the tunnel.
	SetScale(SCALE_X, SCALE_Y, SCALE_Z);

	// Sets the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechTunnel");
	HR(mFx->SetTechnique(mhTech));
}

Tunnel::~Tunnel()
{
	// Nothing to do here	
}

void Tunnel::Update()
{
	// Move the tunnel toward the camera using only the depth position
	MoveTunnel();
}

void Tunnel::MoveTunnel()
{
	// Increment the tunnel's depth using the constant of speed.
	mPos.z += TUNNEL_SPEED;
	SetPosition(mPos.x, mPos.y, mPos.z + TUNNEL_SPEED);

	// If the position reaches the "Resetting position", returns the tunnel to it's original starting position
	if (mPos.z >= RESET_POS)
	{
		mPos.z = 0;
	}
}