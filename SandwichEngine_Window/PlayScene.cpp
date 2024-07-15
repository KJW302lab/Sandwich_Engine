#include "PlayScene.h"
#include "Player.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"
#include "Input.h"
#include "SceneManager.h"

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
		Scene::Initialize();

		{
			bg = new Player();
			Transform* tr
				= bg->AddComponent<Transform>();
			tr->SetPos(Vector2(0, 0));

			tr->SetName(L"TR");

			SpriteRenderer* sr
				= bg->AddComponent<SpriteRenderer>();

			sr->SetName(L"SR");
			sr->ImageLoad(L"C:\\Users\\haroo\\source\\repos\\SandwichEngine\\Resources\\CloudOcean.png");

			AddGameObject(bg, eLayerType::BackGround);
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
			SceneManager::LoadScene(L"TitleScene");
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit();

		bg->GetComponent<Transform>()->SetPos(Vector2(0, 0));
	}
}
