#pragma once
#include <array>

#include <string>

#include "mazeBuilder.hpp"
#include "Player.hpp"


void DrawMap(sf::RenderWindow& window, const std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH> MapSketch);

std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH> convertSketch(const std::array <std::string, MAP_HEIGHT>& i_map_sketch, Player& player);

