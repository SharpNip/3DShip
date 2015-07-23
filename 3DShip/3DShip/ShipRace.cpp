#include "ShipRace.h"
#include "ResourceIDs.h"

ShipRace::ShipRace()
{
	triGrid = new TriGrid(100.f, 100.f, 1.0f);
	triGrid->SetPosition(0.f, 0.f, 0.f);
}

ShipRace::~ShipRace()
{
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