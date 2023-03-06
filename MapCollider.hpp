#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include "Global.hpp"






//all I really need a collider to do is to check and make sure that the elements don't enter the map grid out of good movement local.
collided map_collision(float i_x, float i_y, const std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH>&mapRef);

//int x_collision(float i_x, float i_y, const std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef);