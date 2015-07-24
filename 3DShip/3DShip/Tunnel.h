#pragma once

#include "PrimitiveModel.h"

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

	const float SCALE_X, SCALE_Y, SCALE_Z;
	const float TUNNEL_SPEED;
	const float RESET_POS;
};

