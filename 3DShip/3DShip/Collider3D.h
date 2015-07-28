#pragma once
#include <vector>
#include "Utils.h"
#include <math.h>
#include <iostream>
#include "Component.h"

enum Type
{
	BOX,
	SPHERE
};

class Collider3D :
	public Component
{
public:
	Collider3D();
	Collider3D(Component* gameObject, Type type, float x, float y, float z);
	virtual ~Collider3D();

	//Getters
	D3DXVECTOR3 GetPosition() { return mPosition; }

	const Type GetType() { return type; }

	Component* GetGameObject() { return gameObject; }
	void SetEnabled(bool isEnabled) { this->isEnabled = isEnabled; }

	//Setters
	void SetPosition(const float x, const float y, const float z);


	//Checks if a point is contained within the collider
	virtual bool Contains(const float x, const float y, const float z) = 0;


	//Checks collision with another collider
	virtual bool CheckCollision(Collider3D* const collider3D) = 0;

	//Returns the current colliding colliders as a vector
	std::vector<Collider3D*> LookForCollisions();

protected:
	D3DXVECTOR3 mPosition;

private:
	//Holds a pointer to the object that own this collider. It's the most crucial part.
	Component* gameObject;

	//Collider type, see enum
	Type type;

	//Will trigger collisions or not. true by default.
	bool isEnabled;

	//Holds a list of the colliders currently colliding
	std::vector<Collider3D*> collidees;

	//Every colliders currently existing
	static std::vector<Collider3D*> colliders;


};

