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
	this->SetID(Components::ID::OBSTACLE);
	// Set the right Technique on th .fx file
	mhTech = mFx->GetTechniqueByName("TransformTechObstacle");
	HR(mFx->SetTechnique(mhTech));

	// Spawn the cube at the right position.
	SetNewPosition(myRandom);
	SetScale(size, size, 0.1f);
	mCollider = new BoxCollider(this, this->GetPosition().x, this->GetPosition().y, this->GetPosition().z, this->size, this->size, 1.f);
	
}

Obstacle::~Obstacle()
{
	delete mCollider;
	mCollider = nullptr;
}

void Obstacle::Update()
{
	float dt = gTimer->GetDeltaTime();
	if (gDInput->keyPressed(DIK_C))
	{
		std::cout << "X full: " << mCollider->GetPosition().x + this->size << std::endl;
		std::cout << "Y full: " << mCollider->GetPosition().y + this->size << std::endl;
		std::cout << "Z: " << mCollider->GetPosition().z << std::endl;
	}
	
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

	mCollider->SetPosition(this->GetPosition().x, this->GetPosition().y, this->GetPosition().z);
}

void Obstacle::ResetPosition()
{
	// Reset with a new position.
	myRandom = rand() % 4;
	depth = startingDepth;
	SetNewPosition(myRandom);
}