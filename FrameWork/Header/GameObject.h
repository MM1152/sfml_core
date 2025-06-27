#pragma once
class GameObject
{
protected:
	int instacneId;
	std::string name;
	bool active;

	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Vector2f origin;
	float roataion;

	Origins originPreset;
public:

	GameObject(const std::string& name = "GameObject");
	virtual ~GameObject();

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Reset() = 0;

	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	const std::string& GetName() const { return name; };
	const float GetRoatation() const { return roataion; };
	const bool GetActive() const { return active; };
	const sf::Vector2f GetPosition() const { return position; };
	const sf::Vector2f GetScale() const { return scale; };
	const sf::Vector2f GetOrigin() const { return origin; };

	virtual void SetName(std::string name) { this->name = name; };
	virtual void SetRotation(float roatation) { this->roataion = roatation;};
	virtual void SetActive(bool active) { this->active = active; };
	virtual void SetPostion(sf::Vector2f position) { this->position = position; };
	virtual void SetScale(sf::Vector2f scale) { this->scale = scale; };
	virtual void SetOrigin(sf::Vector2f origin) { this->origin = origin; };
	virtual void SetOrigin(Origins originPreset) { this->originPreset = originPreset; };
};

