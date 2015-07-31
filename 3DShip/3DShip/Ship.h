#pragma once
#include "PrimitiveModel.h"
#include "BoxCollider.h"
#include "ResourceIDs.h"
#include "Score.h"

#define START_SCALE_X 2.f
#define START_SCALE_Y 1.f
#define START_SCALE_Z 1.f
#define START_SPEED 30
#define BOUNDARIES 5.f

class Ship :
	public PrimitiveModel
{
public:
	// Ctor/Dtor
	Ship();
	~Ship();

	// Heritage methods
	void Update();

	bool GetIsDead() { return mIsDead; }

	void Kill();
	void Activate();

	Score* scoreboard;
private:
	// Methods to be used only by the ship
	void HandleInput(float dt);
	void Move(float dt);
	void CheckCollison();
	void FancyName(float distanceTraveled);

	// The ship Speed
	int mShipSpeed;
	bool mIsDead;

	// The ship's "traveled distance"
	float currentScore;

	// The position in x, y of the last frame inside our boudaries
	D3DXVECTOR2 mLastFramePos;

	// Direction of the ship
	D3DXVECTOR2 mDirection;
	D3DXVECTOR3 mStartPos;

	BoxCollider* mCollider;
};

