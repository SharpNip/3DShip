#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	//triangle = new Triangle();
	//cube = new Cube();
	triGrid = new TriGrid(100.f, 100.f, 1.0f);
	triGrid->SetPosition(0.f, 0.f, 0.f);
}

ShipRace::~ShipRace()
{
	//delete triangle;
	//delete cube;
	delete triGrid;
}

void ShipRace::Start()
{

}

void ShipRace::Update()
{

}

void ShipRace::Draw()
{

}

void ShipRace::Stop()
{

}