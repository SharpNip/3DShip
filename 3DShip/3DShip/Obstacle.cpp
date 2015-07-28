#include "Obstacle.h"

Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	, startingDepth(40)
	, myRandom(rand() % 4)
	, posX(0)
	, posY(0)
	, depth(startingDepth)
	, size(10.f)
	, OBSTACLE_SPEED(50)
	, resetZ(-20)
	, distanceFromCenter(5.f)
{
	// Set the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechObstacle");
	HR(mFx->SetTechnique(mhTech));

	// Spawn the cube at the right position.
	SetNewPosition(myRandom);
	SetScale(size, size, 0.1f);
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

void Obstacle::SetNewPosition(int random)
{
	switch (random)
	{
	case 0:
		SetPosition(-distanceFromCenter, 0.f, depth);
		posX = -distanceFromCenter;
		posY = 0.f;
		break;
	case 1:
		SetPosition(distanceFromCenter, 0.f, depth);
		posX = distanceFromCenter;
		posY = 0.f;
		break;
	case 2:
		SetPosition(0.f, -distanceFromCenter, depth);
		posX = 0.f;
		posY = -distanceFromCenter;
		break;
	case 3:
		SetPosition(0.f, distanceFromCenter, depth);
		posX = 0.f;
		posY = distanceFromCenter;
		break;
	default:
		break;
	}
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
	myRandom = rand() % 4;
	depth = startingDepth;
	SetNewPosition(myRandom);
}