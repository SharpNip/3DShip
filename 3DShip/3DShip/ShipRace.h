#pragma once

#include "ResourceIDs.h"
#include "TriGrid.h"

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
};

