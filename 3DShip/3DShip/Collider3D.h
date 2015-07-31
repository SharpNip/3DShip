#pragma once
#include <vector>
#include "Utils.h"
#include <math.h>
#include <iostream>
#include "Component.h"

////////////////////////////////////////////////////////////////////////
// Collider3D Class:
//		-> Adapted from the 2D Collider version from Pier Luc
//			this class allows the user to created 3D colliders.
//				Current use is only for the box collider. Sphere is a WIP
////////////////////////////////////////////////////////////////////////

enum Type
{
	BOX,
	SPHERE
};

class Collider3D :
	public Component
{
public:
	// Default constructor
	Collider3D();

	// Parametrized cosntructors for each construct type
	Collider3D(Component* gameObject, Type type, float x, float y, float z);
	Collider3D(Component* gameObject, Type type, D3DXVECTOR3 position);
	virtual ~Collider3D();

	// Getter
	D3DXVECTOR3 GetPosition() { return mPosition; }
	const Type GetType() { return type; }
	Component* GetGameObject() { return gameObject; }
	
	void SetEnabled(bool isEnabled) { this->isEnabled = isEnabled; }

	// Setter
	void SetPosition(const float x, const float y, const float z);
	void SetPosition(const D3DXVECTOR3 v);

	// Checks if the points of another collider is found inside this one
	virtual bool Contains(const float x, const float y, const float z) = 0;

	// Checks collision with another collider
	virtual bool CheckCollision(Collider3D* const collider3D) = 0;

	// Returns the current colliding colliders as a vector
	std::vector<Collider3D*> LookForCollisions();

protected:
	D3DXVECTOR3 mPosition;

private:
	// Holds a pointer to the object that own this collider. It's the most crucial part.
	Component* gameObject;

	// Collider types
	Type type;

	// Will trigger collisions or not. true by default.
	bool isEnabled;

	// Vector of collided colliders if several are touching
	std::vector<Collider3D*> collidees;

	// Vector of all exisiting colliders in game
	static std::vector<Collider3D*> colliders;


};

