#pragma once
#include "PrimitiveModel.h"

////////////////////////////////////////////////////////////////////////////////
// Tunnel Class:
//		-> This class takes car of our "environment". It's a Cylinder Polymesh 
//			from the prefabricated "versions" of DX.
//			It's made to just move towards the camera.
///////////////////////////////////////////////////////////////////////////////

#define SCALE_X 20.f
#define SCALE_Y 20.f
#define SCALE_Z 100.f

class Tunnel :
	public PrimitiveModel
{
public:
	// Default constructor and destructor
	Tunnel();
	~Tunnel();

	// Inherited function through PrimitiveModel
	void Update();
	
	// Used to move the tunnel towards the camera 
	void MoveTunnel();

private:
	// A constant of speed and a constant of depth to reset the tunnel at the right place
	const float TUNNEL_SPEED;
	const float RESET_POS;

	// The tunnel's position
	D3DXVECTOR3 mPos;
};

