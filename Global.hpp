#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char MAP_HEIGHT = 18;
constexpr unsigned char TEXT_HEIGHT = 16;
constexpr unsigned char MAP_WIDTH = 32;
constexpr unsigned char SCREEN_RESIZE = 2;





enum class Cell
{
	Wall,
	Empty,
	Chest,
	NPC,
	Boulder,
	Next_Area

};
struct collided {
	bool up = 0;
	bool right = 0;
	bool left = 0;
	bool down = 0;
};
struct Position {
	float x;
	float y;

	bool operator==(const Position& i_position) {
		return this->x == i_position.x && this->y == i_position.y;
	}
};