#pragma once

#include "ResourceIDs.h"
#include "TriGrid.h"
#include "Tunnel.h"
#include "Ship.h"

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
	TriGrid* triGrid;
	Tunnel* tunnel;
	Ship* ship;
};

