#include "SandApplication.h"
#include "SandwichInput.h"
#include "SandwichTime.h"

namespace Sandwich
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0
			, mWidth
			, mHeight, 0);

		ShowWindow(hwnd, true);

		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// 새로 생성한 백버퍼를 가리킬 DC 생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(mBackHdc, mBackBuffer));
		DeleteObject(oldBitmap);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		BitBlt(mHdc, 100, 100, mWidth - 100, mHeight - 100, mBackHdc, 0, 0, SRCCOPY);
	}
}
