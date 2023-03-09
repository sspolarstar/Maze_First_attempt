#include "Player.hpp"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	facesRight = true;

	body.setSize(sf::Vector2f((float)CELL_SIZE, (float)CELL_SIZE));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
	body.setPosition(6*CELL_SIZE + 1.0f, 6 * CELL_SIZE + 1.0f);
	body.setTexture(texture);


}

Player::~Player()
{
	//do nothing
	//or kill the player
	//but they're important.
	//if they go bye, where's the game?
}

void Player::Update(float deltaTime, std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef){
	//std::cout << "1";
	collided collision_direction = map_collision(body.getPosition().x, body.getPosition().y, mapRef);
	//Player animations
	sf::Vector2u walkRight(1, 5);
	sf::Vector2u walkUp(17, 21);
	sf::Vector2u walkDown(10, 12);
	sf::Vector2u holdStill(6, 8);
	//player movements
	//sf::Vector2f movement(0.0f, 0.0f);
	Position movement;
	movement.x = 0;
	movement.y = 0;
	
	sf::Vector2u rowLocator;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		if (collision_direction.wall[LEFT]) {
		
		}
		else {
			movement.x -= speed * deltaTime;
			if (collision_direction.boulder[LEFT]) {
				movement.x = movement.x / 3;
			}
			rowLocator = walkRight; //actually left!
		}
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		if (collision_direction.wall[RIGHT]) {}
		else {
			movement.x += speed * deltaTime;
			if (collision_direction.boulder[RIGHT]) {
				movement.x = movement.x / 3;
			}
			rowLocator = walkRight;
		}		
	}
	if (movement.x == 0) {
		//row = 0;
		rowLocator = holdStill;
	}
	else {
		//let's rewrite this later. but I don't think we use this much.
		facesRight = movement.x > 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		if (collision_direction.wall[UP]) {}
		else {
			movement.y -= speed * deltaTime;
			rowLocator = walkUp;
		}
		if (collision_direction.boulder[UP]) {
			movement.y = movement.y / 3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		if (collision_direction.wall[DOWN]) {
		}
		else {
			movement.y += speed * deltaTime;
			rowLocator = walkDown;
		}
		if (collision_direction.boulder[DOWN]) {
			movement.y = movement.y / 3;
		}
	}
	//end player movements
	animation.Update(row, rowLocator, deltaTime, facesRight);
	body.setTextureRect(animation.uvRect);
	
	move(movement.x, movement.y);
}

void Player::Draw(sf::RenderWindow& window){
	window.draw(body);
}

void Player::move(float i_x, float i_y){
	body.setPosition(body.getPosition().x + i_x, body.getPosition().y + i_y);
}
