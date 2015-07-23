#pragma once
#include "CustomModel.h"
class Ship :
	public CustomModel
{
public:
	Ship();
	~Ship();

private:
	ID3DXMesh *mShip;
};

