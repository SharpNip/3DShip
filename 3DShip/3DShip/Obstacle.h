#pragma once

#include "PrimitiveModel.h"
#include "random"
#include "ResourceIDs.h"	
#include "BoxCollider.h"

class Obstacle :
	public PrimitiveModel
{
public:
	Obstacle();
	~Obstacle();

	void Update();
	void SetNewPosition(int random);
	void MoveObstacle(float dt);
	void ResetPosition();

private:
	float posX;
	float posY;
	float depth;
	float startingDepth;
	float resetZ;
	float distanceFromCenter;
	float size;
	int myRandom;
	const float OBSTACLE_SPEED;

	BoxCollider* mCollider;


};

