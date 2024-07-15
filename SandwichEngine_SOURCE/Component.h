#pragma once
#include "Entity.h"

namespace Sandwich
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(GameObject* owner) { mGo = owner; }
		GameObject* GetOwner() { return mGo; }

	private:
		GameObject* mGo;
	};
}

