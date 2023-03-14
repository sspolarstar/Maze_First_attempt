#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

constexpr unsigned char CELL_SIZE = 16;
constexpr unsigned char MAP_HEIGHT = 18;
constexpr unsigned char TEXT_HEIGHT = 16;
constexpr unsigned char MAP_WIDTH = 32;
constexpr unsigned char SCREEN_RESIZE = 2;

constexpr unsigned char LEFT = 0;
constexpr unsigned char RIGHT = 1;
constexpr unsigned char UP = 2;
constexpr unsigned char DOWN = 3;



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
	bool wall[4] = { 0,0,0,0 };
	bool boulder[4] = { 0,0,0,0 };
	bool nextArea[4] = { 0,0,0,0 };

};

struct Position {
	float x;
	float y;

	bool operator==(const Position& i_position) {
		return this->x == i_position.x && this->y == i_position.y;
	}
};