#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MapCollider.hpp"
#include "Animation.hpp"
#include "Global.hpp"

class Player
{
private:
	Position position;
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();
	
	void Update(float deltaTime, std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef);
	void Draw(sf::RenderWindow& window);
	Position getPosition() { return position; }
	void setPosition(float i_x, float i_y) {  this->position.x = i_x; this->position.y = i_y; }

	void move(float i_x, float i_y);

	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool facesRight;
};

