#pragma once
#include "..//SandwichEngine_SOURCE/SandwichSceneManager.h"

#include "SandwichPlayScene.h"

//#ifdef _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\SandwichEngine_Window.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\SandwichEngine_Window.lib")
//#endif


namespace Sandwich
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
