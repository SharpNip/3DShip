
#include "Obstacle.h"

Obstacle::Obstacle()
	: PrimitiveModel(PrimitiveModel_Type::CUBE)
	//, mPos(x, y, z)
	, x(rand() % 10 - 5)
	, y(rand() % 10 - 5)
	, z(0)
{
	SetPosition(x, y, z);
}

Obstacle::~Obstacle()
{

}

void Obstacle::Update()
{

}

void Obstacle::MoveObstacle()
{

}