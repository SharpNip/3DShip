#pragma once

#include "ResourceIDs.h"
#include "TriGrid.h"
#include "Tunnel.h"
#include "Ship.h"
#include "Score.h"
#include "Obstacle.h"

class ShipRace
{
public:
	ShipRace();
	~ShipRace();

	void Start();
	void Update();
	void Draw();
	void Stop();

private:
	//TriGrid* triGrid;
	Tunnel* tunnel;
	Ship* ship;
	Score* score;
	Obstacle* obstacle;
};

