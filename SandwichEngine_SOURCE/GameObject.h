#pragma once
#include "CommonInclude.h"
#include "Component.h"

namespace Sandwich
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			comp->Initialize();
			mComponents.push_back(comp);

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (comp)
					break;
			}

			return component;
		}

	private:
		std::vector<Component*> mComponents;
	};
}

