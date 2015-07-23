#include "Ship.h"


Ship::Ship()
{
	HR(D3DXCreateCylinder(gD3DDevice, 1.f, 0.f, 6.f, 20, 20, &mShip, 0));

	//SetPosition(gEngine->GetCamera()->GetCamPos().x + 10, gEngine->GetCamera()->GetCamPos().y + 100, gEngine->GetCamera()->GetCamPos().z - 1000);
}


Ship::~Ship()
{
	ReleaseCOM(mShip);
}

void Ship::Draw()
{
	HR(mShip->GetVertexBuffer(&mVB));
	HR(mShip->GetIndexBuffer(&mIB));

	HR(gD3DDevice->SetStreamSource(0, mVB, 0, sizeof(VertexPosCol)));
	//HR(gD3DDevice->SetVertexDeclaration(VertexPosCol::decl));

	HR(gD3DDevice->SetIndices(mIB));


	gD3DDevice->SetFVF(mShip->GetFVF());
	
	D3DXMATRIX world;
	D3DXMATRIX trans;
	D3DXMATRIX rot;
	D3DXMatrixIdentity(&world);

	D3DXMatrixRotationY(&rot, currentRotation);
	D3DXMatrixTranslation(&trans, mPosition.x, mPosition.y, mPosition.z);
	world = rot * trans;

	HR(mFx->SetMatrix(mhWVP, &(world * gEngine->GetCamera()->GetView() * gEngine->GetCamera()->GetProj())));
	HR(mFx->CommitChanges());

	UINT numPasses = 0;
	HR(mFx->Begin(&numPasses, 0));
	for (UINT i = 0; i < numPasses; i++)
	{
		HR(mFx->BeginPass(i));
		HR(gD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0,
			0, mShip->GetNumVertices(), 0, mShip->GetNumFaces()));
		HR(mFx->EndPass());
	}
	HR(mFx->End());

	//HR(mShip->DrawSubset(0));
}


