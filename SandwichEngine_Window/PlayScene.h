#pragma once
#include "Player.h"
#include "../SandwichEngine_SOURCE/Scene.h"

namespace Sandwich
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void OnEnter() override;
		void OnExit() override;

	private:
		Player* bg;
	};
}

