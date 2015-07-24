#pragma once
#include "PrimitiveModel.h"

class Ship :
	public PrimitiveModel
{
public:
	Ship();
	~Ship();

private:
	void HandleInput();
	void Move();
	void OnCollision();
};

