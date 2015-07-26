#pragma once

#include "PrimitiveModel.h"
#include "random"

class Obstacle :
	public PrimitiveModel
{
public:
	Obstacle();
	~Obstacle();

	void Update();
	void MoveObstacle();

private:
	//D3DXVECTOR3 mPos;

	float x, y, z;
};

