#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& textureId, const std::string name)
	:textureId(textureId)
	,GameObject(name)
{
	
}

void SpriteGo::SetRotation(float roatation)
{
	this->roataion = roatation;
	sprite.setRotation(this->roataion);
}

void SpriteGo::SetActive(bool active)
{
	this->active = active;
}

void SpriteGo::SetPostion(sf::Vector2f position)
{
	this->position = position;
	sprite.setPosition(this->position);
}

void SpriteGo::SetScale(sf::Vector2f scale)
{
	this->scale = scale;
	sprite.setScale(this->scale);
}

void SpriteGo::SetOrigin(sf::Vector2f origin)
{
	originPreset = Origins::Custom;
	this->origin = origin;
	sprite.setOrigin(origin);
}

void SpriteGo::SetOrigin(Origins originPreset)
{
	this->originPreset = originPreset;
	if (originPreset != Origins::Custom) {
		Utils::SetOrigin(sprite, originPreset);
	}
}

void SpriteGo::Init()
{
}

void SpriteGo::Release()
{
}

void SpriteGo::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(this->textureId));
	Utils::SetOrigin(sprite, originPreset);
}

void SpriteGo::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Left)) {
		SetPostion({ 0.f , 0.f });
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right)) {
		SetPostion({ 500.f , 0.f });
	}
}

void SpriteGo::Draw(sf::RenderWindow& window)
{
	if (active) {
		window.draw(sprite);
	}
}
