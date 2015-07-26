
#include "Obstacle.h"

Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, posX(rand() % 10 - 5)
	, posY(rand() % 10 - 5)
	, depth(20)
	, OBSTACLE_SPEED(10)
	, resetZ(-20)
{
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
	posX = rand() % 10 - 5;
	posY = rand() % 10 - 5;
	depth = 20;
}