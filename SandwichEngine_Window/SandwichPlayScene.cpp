#include "SandwichPlayScene.h"
#include "SandwichGameObject.h"

namespace Sandwich
{
	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		for (int i = 0; i < 10; ++i)
		{
			GameObject* obj = new GameObject();

			obj->SetPosition(rand() % 1600, rand() % 900);

			AddGameObject(obj);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}
