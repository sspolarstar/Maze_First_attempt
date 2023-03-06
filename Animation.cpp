#include "Animation.hpp"
#include<iostream>


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);


}

void Animation::Update(int row, sf::Vector2u rowLocator, float deltaTime, bool facesRight)
{
//	int rotation = 3; //rowLocator.x - rowLocator.y;
	currentImage.y = row;
	

	if (currentImage.x + rowLocator.x >= rowLocator.y) 
	{
		currentImage.x = 0;
	}

	totalTime += deltaTime;
	
	if (totalTime > switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		
		uvRect.top = currentImage.y * uvRect.height;
		if (facesRight) 
		{
			uvRect.left = (currentImage.x + rowLocator.x) * uvRect.width;
			uvRect.width = abs(uvRect.width);
		}
		else 
		{
			uvRect.left = (currentImage.x + rowLocator.x + 1) * abs(uvRect.width);
			uvRect.width = -abs(uvRect.width);
		}

	}
}
