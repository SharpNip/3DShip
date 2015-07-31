#include "Collider3D.h"
#include <iostream>
// Static redeclaration of the collider vector
std::vector<Collider3D*> Collider3D::colliders;

// Base 
Collider3D::Collider3D()
	:isEnabled(true)
{
	isEnabled = true;
	colliders.push_back(this);
}
// Parametrized constructor that takes 3 floats
Collider3D::Collider3D(Component* gameObject, Type type, float x, float y, float z)
	:	type(type)
	, gameObject(gameObject)
	, mPosition(x, y, z)
	, isEnabled(true)
{

	colliders.push_back(this);
}
// Parametrized constructor that takes a vector
Collider3D::Collider3D(Component* gameObject, Type type, D3DXVECTOR3 position)
	: type(type)
	, gameObject(gameObject)
	, mPosition(position)
	, isEnabled(true)
{

	colliders.push_back(this);
}

// Destructor that parses through the member vector and erases each component
Collider3D::~Collider3D()
{
	auto it = collidees.begin();
	while (it != collidees.end())
	{
		it = collidees.erase(it);
	}
}
// Sets the position using a bunch of floats
void Collider3D::SetPosition(const float x, const float y, const float z)
{
	this->mPosition.x = x;
	this->mPosition.y = y;
	this->mPosition.z = z;
}
// Sets the position using a vector
void Collider3D::SetPosition(const D3DXVECTOR3 v)
{
	this->mPosition.x = v.x;
	this->mPosition.y = v.y;
	this->mPosition.z = v.z;
}
// Iterates through each collider found inside the static vector
std::vector<Collider3D*> Collider3D::LookForCollisions()
{
	collidees.clear();
	for each (Collider3D* col in Collider3D::colliders)
	{
		if (col != this && CheckCollision(col) && col->isEnabled)
		{
			collidees.push_back(col);
		}
	}
	return collidees;
}
