#include <iostream>
#include "InputMgr.h"
#include "SFML/Graphics.hpp"
#include "ResourceMgr.h"


int main() 
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Timber");
	ResourceMgr<sf::Texture>::instance().Load("player.png");
	sf::Sprite sp;
	sp.setTexture(ResourceMgr<sf::Texture>::instance().Get("player.png"));
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

		if (InputMgr::GetKeyDown(sf::Keyboard::A)) {
			std::cout << "Key Down: A" << std::endl;
		}
		if (InputMgr::GetKeyUp(sf::Keyboard::A)) {
			std::cout << "Key Up: A" << std::endl;
		}
		

		//Draw
		window.clear();
		window.draw(sp);
		window.display();
	}

	return 0;
}