#pragma once
#include "GameObject.h"
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo(const std::string& textureId = "" ,const std::string name = "");
	virtual ~SpriteGo() = default;

	const std::string& GetTextureId() const { return textureId; };
	void SetTextureId(const std::string& textureId) { this->textureId = textureId; };

	void SetRotation(float roatation) override;
	void SetActive(bool active) override;
	void SetPostion(sf::Vector2f position) override;
	void SetScale(sf::Vector2f scale) override;
	void SetOrigin(sf::Vector2f origin) override;
	void SetOrigin(Origins originPreset) override;

	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

