#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Update(int row, sf::Vector2u rowLocator, float deltaTime, bool facesRight);

public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};

