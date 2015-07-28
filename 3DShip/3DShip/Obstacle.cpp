#include "Obstacle.h"

Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, startingDepth(20)
	, myRandom(rand() % 10 - 5)
	, posX(myRandom)
	, posY(myRandom)
	, depth(startingDepth)
	, OBSTACLE_SPEED(10)
	, resetZ(-20)
{
	// Set the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechObstacle");
	HR(mFx->SetTechnique(mhTech));

	// Spawn the cube at the right position.
	SetPosition(posX, posY, depth);
}

Obstacle::~Obstacle()
{

}

void Obstacle::Update()
{
	float dt = gTimer->GetDeltaTime();

	// Make sure to move the obstacle.
	MoveObstacle(dt);
}

void Obstacle::MoveObstacle(float dt)
{
	// Use delta time to make the cube moves smoothly.
	depth -= OBSTACLE_SPEED * dt;
	SetPosition(posX, posY, depth);

	// Check is the cube is out of screen to reset his position at another random position.
	if (depth <= resetZ)
	{
		ResetPosition();
	}
}

void Obstacle::ResetPosition()
{
	// Reset with a new position.
	posX = myRandom;
	posY = myRandom;
	depth = startingDepth;
}