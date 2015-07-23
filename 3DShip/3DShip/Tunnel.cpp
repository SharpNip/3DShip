
#include "Tunnel.h"

Tunnel::Tunnel()
	: Radius1(100.f)
	, Radius2(100.f)
	, Length(1000.f)
	, Slices(4)
	, Stacks(4)
{
	HR(D3DXCreateCylinder(gD3DDevice, Radius1, Radius2, Length, Slices, Stacks, &mCylinder, 0));
	HR(mCylinder->DrawSubset(0));
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

	for (int z = -30; z <= 30; z += 10)
	{
		D3DXMatrixTranslation(&T, -10.f, 3.f, (float)z);
		HR(mFx->SetMatrix(mhWVP, &(R * T * gEngine->GetCamera()->GetView() * gEngine->GetCamera()->GetProj())));
		HR(mFx->CommitChanges());
		HR(mCylinder->DrawSubset(0));

		D3DXMatrixTranslation(&T, 10.f, 3.f, (float)z);
		HR(mFx->SetMatrix(mhWVP, &(R * T * gEngine->GetCamera()->GetView() * gEngine->GetCamera()->GetProj())));
		HR(mFx->CommitChanges());
		HR(mCylinder->DrawSubset(0));
	}
}

void Tunnel::Stop()
{

}