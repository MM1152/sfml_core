#pragma once

typedef sf::Keyboard::Key Key;
typedef sf::Keyboard KeyBoard;

class InputMgr
{
private:
	//이번 프레임에 눌린 키 관리 리스트
	//이번 프레임에 놓은 키 관리 리스트
	//이번 프레임에 누르고있는 키 관리 리스트
	static std::list<Key> downKeys;
	static std::list<Key> holdKeys;
	static std::list<Key> upKeys;
public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(Key key);
	static bool GetKeyUp(Key key);
	static bool GetKey(Key key);

	static bool Contains(const std::list<Key>& list, Key key);
	static void Remove(std::list<Key>& list, Key key);
};

