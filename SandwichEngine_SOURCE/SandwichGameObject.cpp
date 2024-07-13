#include "SandwichGameObject.h"
#include "SandwichInput.h"
#include "SandwichTime.h"

namespace Sandwich
{
	GameObject::GameObject() : mX(0.0f), mY(0.0f)
	{

	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		const int speed = 200.0f;

		if (Input::GetKey(eKeyCode::Left))
			mX -= speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::Right))
			mX += speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::Up))
			mY -= speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::Down))
			mY += speed * Time::DeltaTime();
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환(SelectObject() 메서드는 이전 오브젝트를 반환한다.)
		HGDIOBJ oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX,  mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}
