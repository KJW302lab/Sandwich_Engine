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
		// �Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ(SelectObject() �޼���� ���� ������Ʈ�� ��ȯ�Ѵ�.)
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
