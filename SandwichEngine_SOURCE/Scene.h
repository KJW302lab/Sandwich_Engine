#pragma once
#include "Layer.h"

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

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, eLayerType type);

	private:
		std::vector<Layer*> mLayers;
	};
}
