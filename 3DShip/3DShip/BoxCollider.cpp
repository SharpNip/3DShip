#include "BoxCollider.h"

//Default Constructor, everything's set to zero.
BoxCollider::BoxCollider()
	:Collider3D(nullptr, Type::BOX, 0, 0, 0)
	, width(0)
	, height(0)
	, depth(0)
{
}

//Default deconstructor
BoxCollider::~BoxCollider()
{
}


// Basically copied from Pier-Luc's 2D colliders, and simply adding in a 3rd dimension -> depth.
// This is probably not the most "optimal" way for doing it as it's going to check all of the colliders in the scene instead of checking all of 
// the ones that are within a certain raycast length.
BoxCollider::BoxCollider(Component* caller, float x, float y, float z, float width, float height, float depth)
	: Collider3D(caller, Type::BOX, x, y, z)
	, width(abs(width))
	, height(abs(height))
	, depth(abs(depth))
{
}

//BoxCollider::BoxCollider(Component* caller, D3DXVECTOR3 position, D3DXVECTOR3 dimensions)
//	: Collider3D(caller, Type::BOX, position.x, position.y, position.z)
//	, width(abs(dimensions.x))
//	, height(abs(dimensions.y))
//	, depth(abs(dimensions.z))
//{
//
//}

// Simple check to determine if a point is within coords
// Basically the same as in rectangle, it will check if the xyz coords are touching.
bool BoxCollider::Contains(const float x, const float y, const float z)
{
	return (x >= this->GetPosition().x && x <= (this->GetPosition().x + this->GetWidth()) &&
		y >= this->GetPosition().y && y <= (this->GetPosition().y + this->GetHeight()) &&
		z >= this->GetPosition().z && z <= (this->GetPosition().z + this->GetDepth()));
}


// Modifies the height, width and depth of the colliders
void BoxCollider::SetSize(float w, float h, float d)
{
	this->width = w;
	this->height = h;
	this->depth = d;
}

void BoxCollider::SetSize(D3DXVECTOR3 v)
{
	this->width = v.x;
	this->height = v.y;
	this->depth = v.z;
}


// Copied from Pierluc's Rectangle algorithm.
// 
// But changed it for a 3 dimensional shape instead.

bool BoxCollider::CollidesWith(BoxCollider* const box)
{
	bool areColliding = false;
	if (this->GetPosition().x < (box->GetPosition().x + box->GetWidth()) && (this->GetPosition().x + this->GetWidth()) > box->GetPosition().x &&
		this->GetPosition().y < (box->GetPosition().y + box->GetHeight()) && (this->GetPosition().y + this->GetHeight())> box->GetPosition().y &&
		this->GetPosition().z < (box->GetPosition().z + box->GetDepth()) && (this->GetPosition().z + this->GetDepth())> box->GetPosition().z)
	{
		areColliding = true;
	}
	return areColliding;
}

// Based on the tested collider, we'll look for a rectangle-circle collision or a rectangle-rectangle collision.
bool BoxCollider::CheckCollision(Collider3D* collider)
{
	bool isColliding = false;
	if (collider->GetType() == Type::BOX)
	{
		isColliding = CollidesWith(static_cast<BoxCollider*>(collider));
	}
	return isColliding;
}
