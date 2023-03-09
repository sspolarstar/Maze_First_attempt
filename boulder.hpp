#pragma once

#include "Global.hpp"
#include "Animation.hpp"
class boulder
{
private:
	Position position;
public:
	boulder();
	void Update();
	void Draw();
	void setPosition(float i_x, float i_y) { this->position.x = i_x; this->position.y = i_y; }
	void push(char direction, float speed);

	sf::RectangleShape body;
	Animation animation;

	Position getPosition() { return this->position; };
	//self stuffs
	

};

