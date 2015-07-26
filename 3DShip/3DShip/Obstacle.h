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
	void MoveObstacle(float dt);
	void ResetPosition();

private:
	float posX, posY, depth, resetZ;
	const float OBSTACLE_SPEED;
};

