#include "Obstacle.h"

// This class creates an obstacle that moves towards the camera. If the player collides with it, he must restart the game

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
	// Sets the ID for the obstacle (for collision)
	this->SetID(Components::ID::OBSTACLE);

	// Sets a "custom" technique for the obstacle's color
	mhTech = mFx->GetTechniqueByName("TransformTechObstacle");
	HR(mFx->SetTechnique(mhTech));

	// Spawn the cube at the right position.
	SetNewPosition(myRandom);
	// Resizes the cube so it covers 1/2 of the screen
	SetScale(size, size, 2.f);
	// Creates the collider around the object
	mCollider = new BoxCollider(this, this->GetPosition().x, this->GetPosition().y, this->GetPosition().z, this->size, this->size, this->size);
}

// Destroys the collider when the game is closed
Obstacle::~Obstacle()
{
	delete mCollider;
	mCollider = nullptr;
}
// Inherited method from Primitive Model
void Obstacle::Update()
{
	float dt = gTimer->GetDeltaTime();
	// Moves the obstacle toward the camera
	MoveObstacle(dt);
}
// Sets a new position for the cube, using a random int
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
// Moves the obstacle smoothly toward the camera
void Obstacle::MoveObstacle(float dt)
{
	// Using the obstacle's depth, we move the obstacle toward the camera
	depth -= OBSTACLE_SPEED * dt;
	SetPosition(posX, posY, depth);

	// Checks if the cube is out of screen to reset his position at another random position.
	if (depth <= resetZ)
	{
		ResetPosition();
	}
	// Moves the collider with the object
	mCollider->SetPosition(this->GetPosition().x - (size / 2), this->GetPosition().y - (size / 2), this->GetPosition().z);
}
// Creates a random position and relocates the object to that new position
void Obstacle::ResetPosition()
{
	// Reset with a new position.
	myRandom = rand() % 4;
	depth = startingDepth;
	SetNewPosition(myRandom);
	mCollider->SetPosition(this->GetPosition().x - (size / 2), this->GetPosition().y - (size / 2), this->GetPosition().z);
}
// Used when the game is "paused"
void Obstacle::Kill()
{
	ResetPosition();
	SetActive(false);
}
// Called when the game is started or "unpaused"
void Obstacle::Activate()
{
	SetActive(true);
}
