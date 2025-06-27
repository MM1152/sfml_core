#pragma once
#include "GameObject.h"
class TextGo :
    public GameObject
{
protected:
    sf::Text text;
    sf::String TextId;

    sf::Vector2f origin;
    Origins originPreset;
public:
    TextGo(const sf::String text = "" , const sf::String name = "");
    virtual ~TextGo() = default;
    
    void Modify(const sf::String text);
    void setColor(const sf::Color& color);
    void setSize(int size);

    // GameObject을(를) 통해 상속됨
    void Init() override;
    void Release() override;
    void Reset() override;
    void Update(float dt) override;
    void Draw(sf::RenderWindow& window) override;

    void SetRotation(float roatation) override;
    void SetPostion(sf::Vector2f position)override;
    void SetScale(sf::Vector2f scale)override;
    void SetOrigin(sf::Vector2f origin)override;
    void SetOrigin(Origins originPreset)override;


};

