#include "stdafx.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "SceneGame.h"
int main() 
{	
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Timber");

	TEXTURE_MGR.Load("player.png");
	FONT_MGR.Load("KOMIKAP_.ttf");
	SceneGame scGame;
	scGame.Init();
	scGame.Enter();

	while (window.isOpen()) {
		sf::Event event;

		InputMgr::Clear();

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			InputMgr::UpdateEvent(event);
		}

		//Update
		InputMgr::Update(0);
		scGame.Update(0);
		//Draw
		window.clear();
		scGame.Draw(window);
		window.display();
	}

	scGame.Release();

	return 0;
}