#pragma once
#include "PrimitiveModel.h"

#define SCALE_X 20.f
#define SCALE_Y 20.f
#define SCALE_Z 100.f

class Tunnel :
	public PrimitiveModel
{
public:
	Tunnel();
	~Tunnel();

	void Update();

	void MoveTunnel();

private:
	D3DXVECTOR3 mPos;

	const float TUNNEL_SPEED;
	const float RESET_POS;
};

