#pragma once
#include "CustomModel.h"
class Ship :
	public CustomModel
{
public:
	Ship();
	~Ship();

	void Draw();

	int GetNumFaces(){ return 0; }
	int GetNumVertices(){ return 0; }

private:
	ID3DXMesh *mShip;
	IDirect3DVertexDeclaration9 *decl;
	D3DVERTEXELEMENT9 *declArray;
};

