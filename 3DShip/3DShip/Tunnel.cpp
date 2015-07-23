
#include "Tunnel.h"

Tunnel::Tunnel()
	: Radius1(10.f)
	, Radius2(10.f)
	, Length(100.f)
	, Slices(10)
	, Stacks(4)
{
	HR(D3DXCreateCylinder(gD3DDevice, Radius1, Radius2, Length, Slices, Stacks, &mCylinder, 0));
}

Tunnel::~Tunnel()
{
	ReleaseCOM(mCylinder);
}

void Tunnel::Start()
{

}

void Tunnel::Update()
{

}

void Tunnel::Draw()
{
	D3DXMATRIX T, R;
	D3DXMatrixRotationX(&R, D3DX_PI);

	D3DXMatrixTranslation(&T, -10.f, 3.f, 0);
	HR(mFx->SetMatrix(mhWVP, &(R * T * gEngine->GetCamera()->GetView() * gEngine->GetCamera()->GetProj())));
	HR(mFx->CommitChanges());
	HR(mCylinder->DrawSubset(0));
}

void Tunnel::Stop()
{

}

int Tunnel::GetNumFaces()
{
	return 0;
}

int Tunnel::GetNumVertices()
{
	return 0;
}