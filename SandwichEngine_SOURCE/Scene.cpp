#include "Scene.h"

namespace Sandwich
{
	Scene::Scene()
		: mLayers{}
	{
		mLayers.resize(static_cast<UINT>(eLayerType::Max));

		for (auto& m_layer : mLayers)
			m_layer = new Layer();
	}

	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}
}
