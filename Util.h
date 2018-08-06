#pragma once

float toRad(float);
DirectX::XMMATRIX getWorldMatrix(float, float, float, float, float, float, float, float, float);
DirectX::XMMATRIX getViewMatrix(float, float, float, float, float, float, float, float, float);
DirectX::XMMATRIX getProjectionMatrix(float, UINT, UINT,float, float);
void __vectorcall updateConstBuff(DirectX::XMFLOAT4X4*, DirectX::XMFLOAT4X4*, DirectX::XMFLOAT4X4*, DirectX::XMMATRIX, DirectX::XMMATRIX, DirectX::XMMATRIX);