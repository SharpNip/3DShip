#pragma once
#include "PrimitiveModel.h"
#include "random"
#include "ResourceIDs.h"	
#include "BoxCollider.h"

///////////////////////////////////////////////////////////
// Obstacle Class:
//		-> Contains a box collider and a cube geomesh. Used to
//			Produce the obstacle that the player must avoid to
//			progress further
/////////////////////////////////////////////////////////////////

class Obstacle :
	public PrimitiveModel
{
public:
	// Default constructor and destructor
	Obstacle();
	~Obstacle();

	// Inherited method
	void Update();

	// Setter for the new position
	void SetNewPosition(int random);

	// Behavior methods used to move the obstacle towards the camera
	void MoveObstacle(float dt);
	void ResetPosition();

	// Methods used when the game is "Paused" or closed
	void Kill();
	void Activate();

private:
	// Several variables used for position
	float posX;
	float posY;
	float depth;
	float startingDepth;
	float resetZ;
	float distanceFromCenter;
	float size;
	int myRandom;
	const float OBSTACLE_SPEED;

	// The class' collider
	BoxCollider* mCollider;
};

