#include "pch.h"
#include "Main.h"
#include "Util.h"

Vertex vertices[] = {
	{ { -1.0f,  1.0f, -1.0f }, { 0.5f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ {  1.0f,  1.0f, -1.0f }, { 0.5f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ { -1.0f, -1.0f, -1.0f }, { 0.5f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ {  1.0f, -1.0f, -1.0f }, { 0.5f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ { -1.0f,  1.0f,  1.0f }, { 0.1f, 0.5f, 0.1f }, { 0.0f, 0.0f,  1.0f } },
	{ {  1.0f,  1.0f,  1.0f }, { 0.1f, 0.5f, 0.1f }, { 0.0f, 0.0f,  1.0f } },
	{ { -1.0f, -1.0f,  1.0f }, { 0.1f, 0.5f, 0.1f }, { 0.0f, 0.0f,  1.0f } },
	{ {  1.0f, -1.0f,  1.0f }, { 0.1f, 0.5f, 0.1f }, { 0.0f, 0.0f,  1.0f } },

	{ { -1.0f,  1.0f,  1.0f }, { 0.1f, 0.1f, 0.5f }, { -1.0f, 0.0f, 0.0f } },
	{ { -1.0f,  1.0f, -1.0f }, { 0.1f, 0.1f, 0.5f }, { -1.0f, 0.0f, 0.0f } },
	{ { -1.0f, -1.0f,  1.0f }, { 0.1f, 0.1f, 0.5f }, { -1.0f, 0.0f, 0.0f } },
	{ { -1.0f, -1.0f, -1.0f }, { 0.1f, 0.1f, 0.5f }, { -1.0f, 0.0f, 0.0f } },
	{ {  1.0f,  1.0f,  1.0f }, { 0.5f, 0.5f, 0.1f }, {  1.0f, 0.0f, 0.0f } },
	{ {  1.0f,  1.0f, -1.0f }, { 0.5f, 0.5f, 0.1f }, {  1.0f, 0.0f, 0.0f } },
	{ {  1.0f, -1.0f,  1.0f }, { 0.5f, 0.5f, 0.1f }, {  1.0f, 0.0f, 0.0f } },
	{ {  1.0f, -1.0f, -1.0f }, { 0.5f, 0.5f, 0.1f }, {  1.0f, 0.0f, 0.0f } },

	{ { -1.0f,  1.0f,  1.0f }, { 0.5f, 0.1f, 0.5f }, { 0.0f,  1.0f, 0.0f } },
	{ {  1.0f,  1.0f,  1.0f }, { 0.5f, 0.1f, 0.5f }, { 0.0f,  1.0f, 0.0f } },
	{ { -1.0f,  1.0f, -1.0f }, { 0.5f, 0.1f, 0.5f }, { 0.0f,  1.0f, 0.0f } },
	{ {  1.0f,  1.0f, -1.0f }, { 0.5f, 0.1f, 0.5f }, { 0.0f,  1.0f, 0.0f } },
	{ { -1.0f, -1.0f,  1.0f }, { 0.1f, 0.5f, 0.5f }, { 0.0f, -1.0f, 0.0f } },
	{ {  1.0f, -1.0f,  1.0f }, { 0.1f, 0.5f, 0.5f }, { 0.0f, -1.0f, 0.0f } },
	{ { -1.0f, -1.0f, -1.0f }, { 0.1f, 0.5f, 0.5f }, { 0.0f, -1.0f, 0.0f } },
	{ {  1.0f, -1.0f, -1.0f }, { 0.1f, 0.5f, 0.5f }, { 0.0f, -1.0f, 0.0f } }
};

UINT16 indices[] = {
	0, 1, 2,
	2, 1, 3,
	4, 6, 5,
	6, 7, 5,

	8, 9, 10,
	10, 9, 11,
	12, 14, 13,
	14, 15, 13,

	16, 17, 18,
	18, 17, 19,
	20, 22, 21, 
	22, 23, 21,
};

Vertex vertices2[] = {
/*	// Center
	{ { -1.0f,  1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ {  1.0f,  1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ { -1.0f, -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },
	{ {  1.0f, -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.0f, -1.0f } },

	// Left
	{ { -2.732f,  1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.0f, -0.866f } },
	{ { -1.0f,	  1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.0f, -0.866f } },
	{ { -2.732f, -1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.0f, -0.866f } },
	{ { -1.0f,   -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.0f, -0.866f } },

	// Right
	{ { 1.0f,    1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.0f, -0.866f } },
	{ { 2.732f,  1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.0f, -0.866f } },
	{ { 1.0f,   -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.0f, -0.866f } },
	{ { 2.732f, -1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.0f, -0.866f } },

	// Up
	{ { -1.0f, 2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.5f, -0.866f } },
	{ {  1.0f, 2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.5f, -0.866f } },
	{ { -1.0f, 1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.5f, -0.866f } },
	{ {  1.0f, 1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, 0.5f, -0.866f } },

	// Down
	{ { -1.0f, -1.0f, -1.0f },  { 0.7f, 0.1f, 0.1f }, { 0.0f, -0.5f, -0.866f } },
	{ {  1.0f, -1.0f, -1.0f },  { 0.7f, 0.1f, 0.1f }, { 0.0f, -0.5f, -0.866f } },
	{ { -1.0f, -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, -0.5f, -0.866f } },
	{ {  1.0f, -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.0f, -0.5f, -0.866f } },

	// Up Left
	{ { -1.0f,   2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.433f, -0.75f } },
	{ { -2.732f, 1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.433f, -0.75f } },
	{ { -1.0f,   1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, 0.433f, -0.75f } },

	// Up Right
	{ { 1.0f,   2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.433f, -0.75f } },
	{ { 1.0f,   1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.433f, -0.75f } },
	{ { 2.732f, 1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, 0.433f, -0.75f } },

	// Down Left
	{ { -2.732f, -1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, -0.433f, -0.75f } },
	{ { -1.0f,   -1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, -0.433f, -0.75f } },
	{ { -1.0f,   -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.5f, -0.433f, -0.75f } },

	// Down Right
	{ { 1.0f,   -1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, -0.433f, -0.75f } },
	{ { 2.732f, -1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, -0.433f, -0.75f } },
	{ { 1.0f,   -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.5f, -0.433f, -0.75f } }
	
	*/// Center
	{ { -1.0f,  1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f,  0.249f, -0.931f } },
	{ {  1.0f,  1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, {  0.267f,  0.249f, -0.931f } },
	{ { -1.0f, -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f, -0.249f, -0.931f } },
	{ {  1.0f, -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, {  0.267f, -0.249f, -0.931f } },

	// Left
	{ { -2.732f,  1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.735f,  0.233f, -0.637f } },
	{ { -1.0f,	  1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f,  0.249f, -0.931f } },
	{ { -2.732f, -1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.735f, -0.233f, -0.637f } },
	{ { -1.0f,   -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f, -0.249f, -0.931f } },

	// Right
	{ { 1.0f,    1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.267f,  0.249f, -0.931f } },
	{ { 2.732f,  1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.735f,  0.233f, -0.637f } },
	{ { 1.0f,   -1.0f, -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.267f, -0.249f, -0.931f } },
	{ { 2.732f, -1.0f,  0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.735f, -0.233f, -0.637f } },

	// Up
	{ { -1.0f, 2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.387f, 0.633f, -0.671f } },
	{ {  1.0f, 2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, {  0.387f, 0.633f, -0.671f } },
	{ { -1.0f, 1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f, 0.249f, -0.931f } },
	{ {  1.0f, 1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, {  0.267f, 0.249f, -0.931f } },

	// Down
	{ { -1.0f, -1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f, -0.249f, -0.931f } },
	{ {  1.0f, -1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, {  0.267f, -0.249f, -0.931f } },
	{ { -1.0f, -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.387f, -0.633f, -0.671f } },
	{ {  1.0f, -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, {  0.387f, -0.633f, -0.671f } },

	// Up Left
	{ { -1.0f,   2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.387f, 0.633f, -0.671f } },
	{ { -2.732f, 1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.735f, 0.233f, -0.637f } },
	{ { -1.0f,   1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f, 0.249f, -0.931f } },

	// Up Right
	{ { 1.0f,   2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.387f, 0.633f, -0.671f } },
	{ { 1.0f,   1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.267f, 0.249f, -0.931f } },
	{ { 2.732f, 1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.735f, 0.233f, -0.637f } },

	// Down Left
	{ { -2.732f, -1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.735f, -0.233f, -0.637f } },
	{ { -1.0f,   -1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { -0.267f, -0.249f, -0.931f } },
	{ { -1.0f,   -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { -0.387f, -0.633f, -0.671f } },

	// Down Right
	{ { 1.0f,   -1.0f,  -1.0f }, { 0.7f, 0.1f, 0.1f }, { 0.267f, -0.249f, -0.931f } },
	{ { 2.732f, -1.0f,   0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.735f, -0.233f, -0.637f } },
	{ { 1.0f,   -2.732f, 0.0f }, { 0.7f, 0.1f, 0.1f }, { 0.387f, -0.633f, -0.671f } }
};

UINT16 indices2[] = {
	0, 1, 2,
	2, 1, 3,

	4, 5, 6,
	6, 5, 7,

	8, 9, 10,
	10, 9, 11,

	12, 13, 14,
	14, 13, 15,

	16, 17, 18,
	18, 17, 19,

	21, 20, 22,
	24, 23, 25,
	26, 27, 28,
	29, 30, 31
};

FLOAT rtClearColor[] = { 0.0f, 0.0f, 0.0f, 1.0f };

int main(int, char*) {
	initWindow();
	initDirectX();
	
	ConstBuff constBuff;

	float rot[3] = { 20.0f, -20.0f, 0.0f };
	float trs[3] = { -0.3f, 0.0f, 4.0f };
	float spd = 0.1f;

	constBuff.lightPos.x = 2.0f;
	constBuff.lightPos.y = 3.0f;
	constBuff.lightPos.z = -3.0f;
	constBuff.lightPos.w = 0.0f;

	DirectX::XMMATRIX view = getViewMatrix(
		0.0f, 0.0f, -5.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	constBuff.eyePos.x = 0.0f;
	constBuff.eyePos.y = 0.0f;
	constBuff.eyePos.z = -5.0f;
	constBuff.eyePos.w = 1.0f;

	DirectX::XMMATRIX proj = getProjectionMatrix(
		60.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.1f, 100.0f);

	while (WinFW::EventLoop::isActive()) {
		if (WinFW::EventLoop::fps(30)) {
			DirectX::XMMATRIX world = getWorldMatrix(
				trs[0], trs[1], trs[2],
				rot[0], rot[1], rot[2],
				1.0f, 1.0f, 1.0f);
			
			updateConstBuff(&constBuff.world, &constBuff.worldInvTranpose, &constBuff.worldViewProj,
				world, view, proj);

			Util::memCopyConstBuffer(constBuff, cBuffData, swapChain->GetCurrentBackBufferIndex());
			render();

			if (WinFW::Keyboard::getKeyAction('R') == WinFW::KeyAction::PRESS) spd += 0.1f;
			if (WinFW::Keyboard::getKeyAction('F') == WinFW::KeyAction::PRESS) spd -= 0.1f;

			if (WinFW::Keyboard::isPress('Y')) rot[0] += spd * 20;
			if (WinFW::Keyboard::isPress('H')) rot[0] -= spd * 20;
			if (WinFW::Keyboard::isPress('G')) rot[1] += spd * 20;
			if (WinFW::Keyboard::isPress('J')) rot[1] -= spd * 20;
			if (WinFW::Keyboard::isPress('T')) rot[2] += spd * 20;
			if (WinFW::Keyboard::isPress('U')) rot[2] -= spd * 20;

			if (WinFW::Keyboard::isPress('W')) trs[1] += spd;
			if (WinFW::Keyboard::isPress('S')) trs[1] -= spd;
			if (WinFW::Keyboard::isPress('D')) trs[0] += spd;
			if (WinFW::Keyboard::isPress('A')) trs[0] -= spd;
			if (WinFW::Keyboard::isPress('E')) trs[2] += spd;
			if (WinFW::Keyboard::isPress('Q')) trs[2] -= spd;
		}
	}

	destroy();
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	WinFW::DefCloseWndProc(uMsg);
	WinFW::DefInputWndProc(uMsg, wParam, lParam);
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void destroy() {
	if (cBuffData) Suit::Apply(cBuffer.Get()).Unmap();
}

void initWindow() {
	WinFW::EventLoop::init();
	window = WinFW::Window::New();
	winClass = WinFW::WinClass::New();
	winClass->init(WINCLASS_NAME, WndProc);
	window->initClientSize(WINCLASS_NAME, WINDOW_WIDTH, WINDOW_HEIGHT);
	window->receiveRawInputMouse();
	g_hWnd = window->get();
	window->setTitle("App");
	window->show();
}

void initDirectX() {
	D3D12::Debug::EnableDebugLayer();

	ComPtr<ID3D12Device> dev;
	ComPtr<IDXGISwapChain1> sc;
	ID3D12Resource **reses[] = { &renderTargets[0], &renderTargets[1] };

	Initializer::InputMaterial(
		BUFFER_COUNT, WINDOW_WIDTH, WINDOW_HEIGHT, g_hWnd, &dev, &comQueue, &sc, &rtvHeap, reses)
		.SelectAdapterByVendorID(D3D_FEATURE_LEVEL_11_0,
			DXGI::ADAPTER::VendorID::MicrosoftBasicRenderDriver)
		.CreateDirectCommandQueue()
		.CreateSwapChain()
		.CreateDescriptorHeap()
		.CreateRenderTargetView();

	dev.As(&device);
	sc.As(&swapChain);

	D3D12_DESCRIPTOR_HEAP_DESC dhDesc;
	Suit::Apply(&dhDesc).set(D3D12_DESCRIPTOR_HEAP_TYPE_DSV, 1);
	Suit::Apply(device.Get()).CreateDescriptorHeap(dsvHeap, &dhDesc);

	D3D12_CLEAR_VALUE clearDepth;
	Suit::Apply(&clearDepth).setDepthStencil(DXGI_FORMAT_D32_FLOAT, 1.0f, 0);

	D3D12_HEAP_PROPERTIES hProp;
	Suit::Apply(&hProp).setDefaultHeap();

	D3D12_RESOURCE_DESC rDesc;
	Suit::Apply(&rDesc).setDepthStencil(static_cast<UINT>(WINDOW_WIDTH), static_cast<UINT>(WINDOW_HEIGHT));

	Suit::Apply(device.Get()).CreateCommittedResource(dephStencil,
		D3D12_RESOURCE_STATE_DEPTH_WRITE, &rDesc, &hProp, &clearDepth);
	dsHandle = dsvHeap->GetCPUDescriptorHandleForHeapStart();
	device->CreateDepthStencilView(dephStencil.Get(), nullptr, dsHandle);
	rtIndex = swapChain->GetCurrentBackBufferIndex();
	loadAssets();
}

void loadAssets() {
	auto dev = Suit::Apply(device.Get());

	fenceHandle = Util::createEvent();
	handleIncSize = dev.GetDescriptorHandleIncrementSize();
	dev.CreateFence(fence);
	dev.CreateDirectCommandAllocator(comAlloc);

	loadGraphicsPipeline();

	dev.CreateDirectCommandList(comList, comAlloc.Get(), pipeline.Get());

	loadResources();
	
	Suit::Apply(scissorRect).setFitScreen(WINDOW_WIDTH, WINDOW_HEIGHT);
	Suit::Apply(viewPort).setFitScreen(static_cast<FLOAT>(WINDOW_WIDTH),
		static_cast<FLOAT>(WINDOW_HEIGHT));
}

void loadGraphicsPipeline() {
	auto dev = Suit::Apply(device.Get());

	D3D12_DESCRIPTOR_RANGE1 range;
	Suit::Apply(&range).set(D3D12_DESCRIPTOR_RANGE_TYPE_CBV, 1);

	D3D12_ROOT_PARAMETER1 rtParam[1];
	Suit::Apply(rtParam).setDescriptorTable(D3D12_SHADER_VISIBILITY_ALL).set(range);

	ComPtr<ID3DBlob> sig;
	D3D12_VERSIONED_ROOT_SIGNATURE_DESC rootSigDesc;
	Suit::Apply(&rootSigDesc).setVersion1_1().setAllowIAInputLayout(rtParam);
	D3D12::SerializeVersionedRootSignature(&sig, &rootSigDesc);
	dev.CreateRootSignature(rootSig, sig.Get());

	ComPtr<ID3DBlob> vertexShader;
	ComPtr<ID3DBlob> pixelShader;
	HLSL::CompileFromFile(&vertexShader, L"Shader.hlsl", "VS", "vs_5_0");
	HLSL::CompileFromFile(&pixelShader, L"Shader.hlsl", "PS", "ps_5_0");

	D3D12_INPUT_ELEMENT_DESC inEle[3];
	Suit::Apply(&inEle[0]).setPerVertex("POS", DXGI_FORMAT_R32G32B32_FLOAT, 0);
	Suit::Apply(&inEle[1]).setPerVertex("COLOR", DXGI_FORMAT_R32G32B32_FLOAT, 12);
	Suit::Apply(&inEle[2]).setPerVertex("NORMAL", DXGI_FORMAT_R32G32B32_FLOAT, 24);

	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipelineDesc;
	auto plDescSuit = Suit::Apply(&pipelineDesc);
	plDescSuit
		.RootSignature(rootSig.Get())
		.setSingleRTV(DXGI_FORMAT_R8G8B8A8_UNORM)
		.DSVFormat(DXGI_FORMAT_D32_FLOAT)
		.PrimitiveTopologyType(D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE)
		.SampleMask()
		.NodeMask()
		.IBStripCutValue()
		.Flags();
	plDescSuit.InputLayout()
		.set(inEle);
	plDescSuit.VS()
		.set(vertexShader.Get());
	plDescSuit.PS()
		.set(pixelShader.Get());
	plDescSuit.DS()
		.set();
	plDescSuit.GS()
		.set();
	plDescSuit.HS()
		.set();
	plDescSuit.StreamOutput()
		.set();
	plDescSuit.CachedPSO()
		.set();
	plDescSuit.SampleDesc()
		.setMSAA_OFF();
	plDescSuit.BlendState()
		.setSingleRendertarget();
	plDescSuit.RasterizerState()
		.set();
	plDescSuit.DepthStencilState()
		.set();

	device->CreateGraphicsPipelineState(&pipelineDesc, IID_PPV_ARGS(&pipeline));
}

void loadResources() {
	auto dev = Suit::Apply(device.Get());
	auto comLst = Suit::Apply(comList.Get());

	D3D12_DESCRIPTOR_HEAP_DESC dhDesc;
	Suit::Apply(&dhDesc).set(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, BUFFER_COUNT,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE);
	dev.CreateDescriptorHeap(cbvHeap, &dhDesc);
	cbvHandle = cbvHeap->GetGPUDescriptorHandleForHeapStart();

	D3D12_HEAP_PROPERTIES heapProp;
	Suit::Apply(&heapProp).setUploadHeap();

	D3D12_RESOURCE_DESC resourceDesc;
	Suit::Apply(&resourceDesc).setBuffer(sizeof(vertices2));

	ComPtr<ID3D12Resource> uploadVertex;
	ComPtr<ID3D12Resource> uploadIndex;

	dev.CreateCommittedResource(uploadVertex, D3D12_RESOURCE_STATE_GENERIC_READ,
		&resourceDesc, &heapProp);

	Suit::Apply(&resourceDesc).setConstantBufferWidth(sizeof(ConstBuff), BUFFER_COUNT);
	dev.CreateCommittedResource(cBuffer, D3D12_RESOURCE_STATE_GENERIC_READ, &resourceDesc, &heapProp);

	resourceDesc.Width = sizeof(indices2);
	dev.CreateCommittedResource(uploadIndex, D3D12_RESOURCE_STATE_GENERIC_READ,
		&resourceDesc, &heapProp);

	auto uploadVertexSuit = Suit::Apply(uploadVertex.Get());
	auto uploadIndexSuit = Suit::Apply(uploadIndex.Get());

	UINT8 *data;
	uploadVertexSuit.Map(&data);
	Util::memCopy(vertices2, data);
	uploadVertexSuit.Unmap();

	uploadIndexSuit.Map(&data);
	Util::memCopy(indices2, data);
	uploadIndexSuit.Unmap();

	Suit::Apply(cBuffer.Get()).Map(&cBuffData);

	heapProp.Type = D3D12_HEAP_TYPE_DEFAULT;
	dev.CreateCommittedResource(indexResource, D3D12_RESOURCE_STATE_COPY_DEST,
		&resourceDesc, &heapProp);

	resourceDesc.Width = sizeof(vertices2);
	dev.CreateCommittedResource(vertexResource, D3D12_RESOURCE_STATE_COPY_DEST,
		&resourceDesc, &heapProp);

	comList->CopyResource(vertexResource.Get(), uploadVertex.Get());
	comList->CopyResource(indexResource.Get(), uploadIndex.Get());

	D3D12_RESOURCE_BARRIER rb[1];
	auto rbSuit = Suit::Apply(rb);
	rbSuit.setTransition().setBuffer(vertexResource.Get(),
		D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER);

	comLst.ResourceBarrier(rb);

	rbSuit.Transition().pResource(indexResource.Get()).StateAfter(D3D12_RESOURCE_STATE_INDEX_BUFFER);
	comLst.ResourceBarrier(rb);

	comList->Close();
	Suit::Apply(comQueue.Get()).ExecuteCommandLists(comList.Get());
	syn();

	Suit::Apply(vbView).set(vertexResource.Get(), sizeof(Vertex), sizeof(vertices2));
	Suit::Apply(ibView).set(indexResource.Get(), sizeof(indices2), DXGI_FORMAT_R16_UINT);

	D3D12_CPU_DESCRIPTOR_HANDLE cbvCPUHandle = cbvHeap->GetCPUDescriptorHandleForHeapStart();
	D3D12_GPU_VIRTUAL_ADDRESS vir = cBuffer->GetGPUVirtualAddress();
	D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc;
	for (UINT i = 0; i < BUFFER_COUNT; i++) {
		Suit::Apply(&cbvDesc).setConstBufferSize(vir, sizeof(ConstBuff), i);
		device->CreateConstantBufferView(&cbvDesc, cbvCPUHandle);
		Suit::Apply(&cbvCPUHandle).inc(handleIncSize.CBV_SRV_UAV);
	}
}

void record() {
	auto comLst = Suit::Apply(comList.Get());
	
	D3D12_CPU_DESCRIPTOR_HANDLE handle[1];
	Suit::Apply(handle).set(rtvHeap.Get(), rtIndex, handleIncSize.RTV);

	D3D12_GPU_DESCRIPTOR_HANDLE cbvHandleBuff;
	Suit::Apply(&cbvHandleBuff).set(cbvHandle.ptr, rtIndex, handleIncSize.CBV_SRV_UAV);

	comAlloc->Reset();
	comList->Reset(comAlloc.Get(), pipeline.Get());

	D3D12_RESOURCE_BARRIER rb[1];
	auto rbSuit = Suit::Apply(rb);
	rbSuit.setTransition().setBuffer(renderTargets[rtIndex].Get(),
		D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);

	comLst.ResourceBarrier(rb);

	ID3D12DescriptorHeap *dh[] = { cbvHeap.Get() };

	comList->SetGraphicsRootSignature(rootSig.Get());
	comList->SetDescriptorHeaps(1, dh);
	comList->SetGraphicsRootDescriptorTable(0, cbvHandleBuff);
	comList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	comLst.IASetVertexBuffers(vbView, 0);
	comList->IASetIndexBuffer(ibView);
	comLst.RSSetViewports(viewPort);
	comLst.RSSetScissorRects(scissorRect);
	comLst.OMSetRenderTargets(handle, FALSE, &dsHandle);

	comLst.ClearDepthView(dsHandle, 1.0f);
	comLst.ClearRenderTargetView(handle[0], rtClearColor);

	comLst.DrawIndex(0, 42);

	rbSuit.setTransition()
		.StateBefore(D3D12_RESOURCE_STATE_RENDER_TARGET)
		.StateAfter(D3D12_RESOURCE_STATE_PRESENT);
	comLst.ResourceBarrier(rb);

	comList->Close();
}

void render() {
	record();
	Suit::Apply(comQueue.Get()).ExecuteCommandLists(comList.Get());
	Suit::Apply(swapChain.Get()).Present();
	rtIndex = swapChain->GetCurrentBackBufferIndex();
	syn();
}

void syn() {
	comQueue->Signal(fence.Get(), ++fenceValue);
	fence->SetEventOnCompletion(fenceValue, fenceHandle);
	Util::waitForSingleObject(fenceHandle);
}
