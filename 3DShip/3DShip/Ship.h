#pragma once
#include "PrimitiveModel.h"
#include "BoxCollider.h"
#include "ResourceIDs.h"
#include "Score.h"

// All the define for the ship
#define START_SCALE_X 2.f
#define START_SCALE_Y 1.f
#define START_SCALE_Z 1.f
#define START_SPEED 30
#define BOUNDARIES 7.f

///////////////////////////////////////////////////////////
// Ship Class:
//		-> Contains a box collider and a Cone geomesh. Used to
//			handle the ship, it's movement and collision are all checked here. 
//			
/////////////////////////////////////////////////////////////////
class Ship :
	public PrimitiveModel
{
public:
	// Ctor/Dtor
	Ship();
	~Ship();

	// Heritage methods
	void Update();

	// Death Getter
	bool GetIsDead() { return mIsDead; }

	// Inherited methods
	void Kill();
	void Activate();

private:
	// Methods to be used only by the ship
	void HandleInput(float dt);
	void Move(float dt);
	void CheckCollison();
	void InceaseScore(float distanceTraveled);

	// The ship Speed
	int mShipSpeed;
	bool mIsDead;

	// The ship's "traveled distance"
	float currentScore;

	// The position in x, y of the last frame inside our boudaries
	D3DXVECTOR2 mLastFramePos;

	// Differents vector for the ship
	D3DXVECTOR2 mDirection;
	D3DXVECTOR3 mStartPos;
	D3DXVECTOR3 mShipSize;

	// The collider
	BoxCollider* mCollider;
	
	// The score
	Score* scoreboard;
};

