#pragma once
#include "GameObject.h"

namespace Sandwich
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene() override;

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}
