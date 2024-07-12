#include "SandApplication.h"
#include "SandwichInput.h"

namespace Sandwich
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
	{
		Input::Initialize();
	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
	}
}
