#include "ShipRace.h"

ShipRace::ShipRace()
{
	//triGrid = new TriGrid(100.f, 100.f, 1.0f);
	//triGrid->SetPosition(0.f, 0.f, 0.f);

	ship = new Ship();
	tunnel = new Tunnel();
	score = new Score();
	
}

ShipRace::~ShipRace()
{
	//delete triGrid;
	delete tunnel;
	delete score;
	delete ship;
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