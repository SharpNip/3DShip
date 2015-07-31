#ifndef BoxCollider_HPP
#define BoxCollider_HPP
#include "Collider3D.h"
//#include "SphereCollider.h" -> This is to be replaced with SphereCollider once it's been made

/////////////////////////////////////////////////////////////////////////////
// Box Collider Class:
//		-> This class is a 3D adaption of PierLuc's 2D collider class
//			It has the same type of behavior and collision detection as his
//////////////////////////////////////////////////////////////////////////////

class BoxCollider
	: public Collider3D
{
public:
	// Default constructors.
	BoxCollider();
	~BoxCollider();

	// Parametrized constructor that takes in a bunch of floats
	BoxCollider(Component* caller, float x, float y, float z, float width, float height, float depth);
	// Parametrized constructor that takes in 2 vectors
	BoxCollider(Component* caller, D3DXVECTOR3 position, D3DXVECTOR3 dimensions);

	// Determines if a point of another collider is on or within the bounds of this one
	bool Contains(const float x, const float y, const float z);

	// Getters
	float GetWidth()  const { return width;  }
	float GetHeight() const { return height; }
	float GetDepth()  const { return depth;  }

	// Setters
	void SetSize(const float w, const float h, const float d);
	void SetSize(const D3DXVECTOR3 v);

	// Determines if there's a collision between this box and another box.
	bool CollidesWith(BoxCollider* const box);
	bool CheckCollision(Collider3D* const collider);

private:
	// Variables for the width, height and depth of an instance of this collider.
	float width;
	float height;
	float depth;
};

#endif
