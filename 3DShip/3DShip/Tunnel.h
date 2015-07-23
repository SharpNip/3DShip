#pragma once

#include "CustomModel.h"
#include "Engine.h"

class Tunnel :
	public CustomModel
{
public:
	Tunnel();
	~Tunnel();

	void Start();
	void Update();
	void Draw();
	void Stop();

	int GetNumFaces();
	int GetNumVertices();

private:
	ID3DXMesh* mCylinder;

	FLOAT Radius1;
	FLOAT Radius2;
	FLOAT Length;
	UINT Slices;
	UINT Stacks;
};

