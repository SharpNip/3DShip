#include "Collider3D.h"
#include <iostream>

std::vector<Collider3D*> Collider3D::colliders;

Collider3D::Collider3D()
	:isEnabled(true)
{
	isEnabled = true;
	colliders.push_back(this);
}

Collider3D::Collider3D(Component* gameObject, Type type, float x, float y, float z)
	:	type(type)
	, gameObject(gameObject)
	, mPosition(x, y, z)
	, isEnabled(true)
{

	colliders.push_back(this);
}


Collider3D::~Collider3D()
{

}


void Collider3D::SetPosition(const float x, const float y, const float z)
{
	this->mPosition.x = x;
	this->mPosition.y = y;
	this->mPosition.z = z;
}

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
