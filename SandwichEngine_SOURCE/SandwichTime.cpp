#include "SandwichTime.h"

namespace Sandwich
{
	LARGE_INTEGER Time:: CpuFrequency = {};
	LARGE_INTEGER Time:: PrevFrequency = {};
	LARGE_INTEGER Time:: CurrentFrequency = {};
	float Time:: DeltaTimeValue = 0.0f;

	void Time::Initialize()
	{
		// cpu 고유진동수
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작 했을 때 현재 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltaTimeValue = static_cast<float>(differenceFrequency / CpuFrequency.QuadPart);

		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"FPS : %d", (int)fps);

		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}
