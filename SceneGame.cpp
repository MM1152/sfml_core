#include "stdafx.h"
#include "SceneGame.h"
#include <SpriteGo.h>
#include <TextGo.h>

SceneGame::SceneGame()
	:Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	SpriteGo* spriteGo = new SpriteGo("player.png");
	spriteGo->SetOrigin(Origins::ML);

	TextGo* textGo = new TextGo("KOMIKAP_.ttf");
	textGo->Modify("ASDASDASD");
	textGo->SetOrigin(Origins::MC);
	textGo->SetPostion({ 1920 / 2 , 1080 / 2 });

	Scene::AddGameObject(spriteGo);
	Scene::AddGameObject(textGo);
	Scene::Init();
}
