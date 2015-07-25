#pragma once
#include "PrimitiveModel.h"

#define START_SCALE_X 2.f
#define START_SCALE_Y 1.f
#define START_SCALE_Z 1.f
#define START_SPEED 30

class Ship :
	public PrimitiveModel
{
public:
	// Ctor/Dtor
	Ship();
	~Ship();

	// Heritage methods
	void Update();

private:
	// Methods to be used only by the ship
	void HandleInput(float dt);
	void Move(D3DXVECTOR2 dir, float dt);
	void OnCollision();

	// The ship Speed
	int mShipSpeed;

	// Direction of the ship
	D3DXVECTOR2 mDirection;
	D3DXVECTOR3 mStartPos;
};

