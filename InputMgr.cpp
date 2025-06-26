#include "InputMgr.h"
#include <algorithm>

std::list <sf::Keyboard::Key> InputMgr::downKeys;
std::list <sf::Keyboard::Key> InputMgr::holdKeys;
std::list <sf::Keyboard::Key> InputMgr::upKeys;

void InputMgr::Init()
{

}

void InputMgr::Clear()
{
	downKeys.clear();
	upKeys.clear();
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	if (ev.type == sf::Event::KeyPressed) {
		if (!Contains(holdKeys, ev.key.code)) {
			downKeys.push_back(ev.key.code);
			holdKeys.push_back(ev.key.code);
		}
	}
	else if (ev.type == sf::Event::KeyReleased) {
		Remove(holdKeys, ev.key.code);
		upKeys.push_back(ev.key.code);
	}
}

void InputMgr::Update(float dt)
{
}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return Contains(downKeys, key);
}

bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return Contains(upKeys, key);
}

bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return Contains(holdKeys, key);
}

bool InputMgr::Contains(const std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	return std::find(list.begin(), list.end(), key) != list.end();
}

void InputMgr::Remove(std::list<sf::Keyboard::Key>& list, sf::Keyboard::Key key)
{
	list.remove(key);
}
