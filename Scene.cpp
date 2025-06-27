#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds id)
	:Id(id)
{
}

void Scene::Init()
{
	for (GameObject* obj : gameObjects) {
		obj->Init();
	}
}

void Scene::Release()
{
	for (GameObject* obj : gameObjects) {
		obj->Release();
		delete obj;
	}
	gameObjects.clear();
}

void Scene::Enter()
{
	for (GameObject* obj : gameObjects) {
		obj->Reset();
	}
}

void Scene::Exit()
{
}

void Scene::Update(float dt)
{
	for (GameObject* go : gameObjects) {
		go->Update(dt);
	}
}

void Scene::Draw(sf::RenderWindow& window)
{
	for (GameObject* go : gameObjects) {
		go->Draw(window);
	}
}

void Scene::AddGameObject(GameObject* go)
{

	if (std::find(gameObjects.begin(), gameObjects.end(), go) == gameObjects.end()) {
		gameObjects.push_back(go);
	}
}

void Scene::RemoveGameObject(GameObject* go)
{
	gameObjects.remove(go);
}

GameObject* Scene::FindGameObject(const std::string& name)
{
	for (GameObject* go : gameObjects) {
		if (go->GetName() == name) {
			return go;
		}
	}
	return nullptr;
}
