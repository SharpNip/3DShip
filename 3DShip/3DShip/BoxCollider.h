#ifndef BoxCollider_HPP
#define BoxCollider_HPP

#include "Collider3D.h"
//#include "CCircle.h" -> This is to be replaced with SphereCollider once it's been made

class BoxCollider
	: public Collider3D
{
public:
	//Our defaults.
	BoxCollider();
	~BoxCollider();

	//Our 'specials' constructors.
	BoxCollider(Component* caller, float x, float y, float z, float width, float height, float depth);

	//Wheter or not a point is contained within a rectangle, considers points ON the rectangle as part of the rectangle.
	bool Contains(const float x, const float y, const float z);

	//Getters
	float GetWidth()  const { return width;  }
	float GetHeight() const { return height; }
	float GetDepth()  const { return depth;  }

	//Setters
	void SetSize(const float w, const float h, const float d);

	//Determines if a rectangle collides with another rectangle.
	bool CollidesWith(BoxCollider* const box);
	bool CheckCollision(Collider3D* const collider);

private:

	//Rectangle's width and height.
	float width;
	float height;
	float depth;
};

#endif
