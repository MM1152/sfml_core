#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const sf::String text , const sf::String name)
	:TextId(text) , GameObject(name)
{
}

void TextGo::Modify(const sf::String text)
{
	this->text.setString(text);
		
	SetOrigin(this->originPreset);

}

void TextGo::setColor(const sf::Color& color)
{
	text.setFillColor(color);

}

void TextGo::setSize(int size)
{
	
	text.setScale(size, size);
}


void TextGo::Init()
{
}

void TextGo::Release()
{
}

void TextGo::Reset()
{
	text.setFont(FONT_MGR.Get(TextId));
	
	//TODO : 초기 오리진값
	SetOrigin(this->originPreset);
}

void TextGo::Update(float dt)
{ 
	if (InputMgr::GetKeyDown(sf::Keyboard::B))
	{
		setColor(sf::Color::Blue);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::R))
	{
		setColor(sf::Color::Red);
	}
}


void TextGo::Draw(sf::RenderWindow& window)
{
	if (active) {
		window.draw(text);
	}
}
void TextGo::SetRotation(float roatation) {
	this->roataion = roatation;
	text.setRotation(this->roataion);
}
void TextGo::SetPostion(sf::Vector2f position) {
	this->position = position;
	text.setPosition(this->position);
}
void TextGo::SetScale(sf::Vector2f scale) {
	this->scale = scale;
	text.setScale(this->scale);
}
void TextGo::SetOrigin(sf::Vector2f origin) {
	this->originPreset = Origins::Custom;
	this->origin = origin;
	text.setOrigin(this->origin);
}
void TextGo::SetOrigin(Origins originPreset) {
	this->originPreset = originPreset;

	if (originPreset != Origins::Custom) {
		this->origin = Utils::SetOrigin(text, this->originPreset);
	}
}


