#pragma once
#include "PrimitiveModel.h"

class Ship :
	public PrimitiveModel
{
public:
	Ship();
	~Ship();

	void Update();

private:
	void HandleInput(float dt);
	void Move(D3DXVECTOR2 dir, float dt);
	void OnCollision();
	void SetDirection(D3DXVECTOR2 dir);

	const int SHIP_SPEED;

	D3DXVECTOR2 mDirection;
};

