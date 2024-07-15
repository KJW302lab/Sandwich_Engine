#pragma once
#include "Scene.h"

namespace Sandwich
{
	class SceneManager
	{
	public:

		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			scene->Initialize();

			mScenes.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator iter = mScenes.find(name);

			if (iter == mScenes.end())
				return nullptr;

			mActiveScene = iter->second;

			return mActiveScene;
		}

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		//static std::vector<Scene*> mScenes;
		static std::map<std::wstring, Scene*> mScenes;
		static Scene* mActiveScene;
	};
}
