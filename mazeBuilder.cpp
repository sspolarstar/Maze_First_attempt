#include "mazeBuilder.hpp"



void DrawMap(sf::RenderWindow& window, const std::array<std::array< Cell, MAP_HEIGHT>, MAP_WIDTH> MapSketch)
{
	sf::Sprite wallSprite, next_areaSprite;
	sf::Texture wallTexture, next_areaTexture, texture;

	wallTexture.loadFromFile("img/graySquare.png");
	wallSprite.setTexture(wallTexture);

	next_areaTexture.loadFromFile("img/next_area.png");

	next_areaSprite.setTexture( next_areaTexture );


	for (unsigned char a = 0; a < MAP_WIDTH; a++)
	{
		for (unsigned char b = 0; b < MAP_HEIGHT; b++)
		{
			
			switch (MapSketch[a][b])
			{
			case Cell::Wall:
				wallSprite.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
				wallSprite.setTextureRect(sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
				window.draw(wallSprite);
				break;
			case Cell::Boulder:
				//window.draw(sprite);
				break;
			case Cell::Next_Area:
				next_areaSprite.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
				next_areaSprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
				window.draw(next_areaSprite);
				break;
			}


		}
	}
	//window.draw(body);
} //end DrawMap function

std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> convertSketch(const std::array<std::string, MAP_HEIGHT>& i_map_sketch, Player& player)
{
	std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> output_map{};
	for (unsigned char a = 0; a < (MAP_HEIGHT ); a++) {
		for (unsigned char b = 0; b < (MAP_WIDTH ); b++) {
			output_map[b][a] = Cell::Empty;
			switch (i_map_sketch[a][b])
			{
				case '*': 
					//this is the walls
					output_map[b][a] = Cell::Wall;
					break;
			
				case 'p': 
					player.body.setPosition(b*CELL_SIZE, a*CELL_SIZE);
					break;
			
				case 'c': 
					//this will be a chest!
					output_map[b][a] = Cell::Chest;
					break;
			
				case 'b': 
					//boulder time
					output_map[b][a] = Cell::Boulder;
					break;
				case 'n':
					//NPC
					output_map[b][a] = Cell::NPC;
					break;
				case 'q':
					//NPC
					output_map[b][a] = Cell::Next_Area;
					break;
	

			} //end switch

		} //end for loop b

	}//end for loop a

	return output_map;
}

