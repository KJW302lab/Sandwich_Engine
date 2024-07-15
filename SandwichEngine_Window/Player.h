#pragma once
#include "../SandwichEngine_SOURCE/GameObject.h"

namespace Sandwich
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}