#include "pch.h"
#include "Util.h"

float toRad(float rad) {
	return rad * DirectX::XM_PI / 180.0f;
}

DirectX::XMMATRIX getWorldMatrix(
	float translateX = 0.0f, float translateY = 0.0f, float translateZ = 0.0f,
	float rotateX	 = 0.0f, float rotateY	  = 0.0f, float rotateZ	   = 0.0f,
	float scaleX	 = 1.0f, float scaleY	  = 1.0f, float scaleZ	   = 1.0f) {

	return
	DirectX::XMMatrixMultiply(
	DirectX::XMMatrixMultiply(
	DirectX::XMMatrixMultiply(
	DirectX::XMMatrixMultiply(
		DirectX::XMMatrixRotationX(toRad(rotateX)),
		DirectX::XMMatrixRotationY(toRad(rotateY))),
		DirectX::XMMatrixRotationZ(toRad(rotateZ))),
		DirectX::XMMatrixScaling(scaleX, scaleY, scaleZ)),
		DirectX::XMMatrixTranslation(translateX, translateY, translateZ));
}

DirectX::XMMATRIX getViewMatrix(
	float eyeX, float eyeY, float eyeZ,
	float atX,  float atY,  float atZ,
	float upX,  float upY,  float upZ) {

	DirectX::XMVECTORF32 eye = { eyeX, eyeY, eyeZ, 0.0f };
	DirectX::XMVECTORF32 at  = {  atX,  atY,  atZ, 0.0f };
	DirectX::XMVECTORF32 up  = {  upX,  upY,  upZ, 0.0f };

	return DirectX::XMMatrixLookAtLH(eye, at, up);
}

DirectX::XMMATRIX getProjectionMatrix(float fovAngleY, UINT width, UINT height, float nearZ, float farZ) {
	return DirectX::XMMatrixPerspectiveFovLH(
		toRad(fovAngleY), float(width) / float(height), nearZ, farZ);
}
void __vectorcall updateConstBuff(
	DirectX::XMFLOAT4X4 *pWorld,
	DirectX::XMFLOAT4X4 *pWorldInvTranpose,
	DirectX::XMFLOAT4X4 *pWorldViewProj,
	DirectX::XMMATRIX world,
	DirectX::XMMATRIX view,
	DirectX::XMMATRIX proj) {

	DirectX::XMMATRIX worldT = DirectX::XMMatrixTranspose(world);
	DirectX::XMMATRIX viewT = DirectX::XMMatrixTranspose(view);
	DirectX::XMMATRIX projT = DirectX::XMMatrixTranspose(proj);

	DirectX::XMStoreFloat4x4(pWorld, worldT);
	DirectX::XMStoreFloat4x4(pWorldInvTranpose, DirectX::XMMatrixInverse(nullptr, world));
	DirectX::XMStoreFloat4x4(pWorldViewProj,
		DirectX::XMMatrixMultiply(DirectX::XMMatrixMultiply(projT, viewT), worldT));
}