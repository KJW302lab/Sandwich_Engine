#pragma once
#include "../SandwichEngine_SOURCE/Scene.h"

namespace Sandwich
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene() override;

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}

