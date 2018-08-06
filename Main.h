#pragma once

// Window
constexpr UINT WINDOW_WIDTH = 800;
constexpr UINT WINDOW_HEIGHT = 600;
constexpr LPCWSTR WINCLASS_NAME = L"winClass";

HWND g_hWnd;
WinFW::IPtr<WinFW::Window> window;
WinFW::IPtr<WinFW::WinClass> winClass;

void initWindow();
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// DirectX
using Microsoft::WRL::ComPtr;
using DXHelper::Initializer;
using DXHelper::Suit;
using DXHelper::Util;

constexpr UINT BUFFER_COUNT = 2;

ComPtr<ID3D12Device> device;
ComPtr<ID3D12CommandQueue> comQueue;
ComPtr<IDXGISwapChain3> swapChain;
ComPtr<ID3D12Resource> renderTargets[BUFFER_COUNT];
ComPtr<ID3D12DescriptorHeap> rtvHeap;
ComPtr<ID3D12CommandAllocator> comAlloc;
ComPtr<ID3D12GraphicsCommandList> comList;
D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle;
ComPtr<ID3D12Resource> dephStencil;
ComPtr<ID3D12DescriptorHeap> dsvHeap;
D3D12_CPU_DESCRIPTOR_HANDLE dsHandle;
ComPtr<ID3D12Fence> fence;
HANDLE fenceHandle;
UINT64 fenceValue = 0;
D3D12::DESCRIPTOR::HANDLE::Size handleIncSize;

ComPtr<ID3D12RootSignature> rootSig;
ComPtr<ID3D12PipelineState> pipeline;
ComPtr<ID3D12Resource> vertexResource;
ComPtr<ID3D12Resource> indexResource;
D3D12_VERTEX_BUFFER_VIEW vbView[1];
D3D12_INDEX_BUFFER_VIEW ibView[1];
D3D12_RECT scissorRect[1];
D3D12_VIEWPORT viewPort[1];

ComPtr<ID3D12Resource> cBuffer;
ComPtr<ID3D12DescriptorHeap> cbvHeap;
UINT8 *cBuffData;
D3D12_GPU_DESCRIPTOR_HANDLE cbvHandle;
size_t rtIndex;

void initDirectX();
void loadAssets();
void destroy();
void loadGraphicsPipeline();
void loadResources();
void record();
void render();
void syn();

struct Vertex {
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT3 color;
	DirectX::XMFLOAT3 normal;
};

constexpr unsigned int NUM_LIGHTS = 1;

struct Light {
	DirectX::XMFLOAT4 color;
	DirectX::XMFLOAT3 pos;
	DirectX::XMFLOAT3 dir;
	float fallOff;
};

struct ConstBuff {
	DirectX::XMFLOAT4X4 world;
	DirectX::XMFLOAT4X4 worldInvTranpose;
	DirectX::XMFLOAT4X4 worldViewProj;
	DirectX::XMFLOAT4 eyePos;
	DirectX::XMFLOAT4 lightPos;
};

