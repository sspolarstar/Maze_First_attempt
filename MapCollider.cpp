#include "MapCollider.hpp"

collided map_collision(float i_x, float i_y, const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef) {
	collided output;

	float distance = ceil(CELL_SIZE / 2.0f);
	//Getting the position.
	short x = static_cast<short>((i_x - distance) / CELL_SIZE);
	short y = static_cast<short>(i_y / CELL_SIZE);
	if (0 <= x && 0 <= y && MAP_HEIGHT >= y && MAP_WIDTH >= x) {	
		for (int a = 0; a < 4; a++) {
			switch (a) {
			case 0:
				x = static_cast<short>((i_x - distance) / CELL_SIZE);
				y = static_cast<short>(i_y / CELL_SIZE);
				break;
			case 1:
				/*x = static_cast<short>((i_x - distance) / CELL_SIZE);
				y = static_cast<short>(i_y / CELL_SIZE);*/
				x = x + 1;
				break;
			case 2:
				x = static_cast<short>(i_x / CELL_SIZE);
				y = static_cast<short>(static_cast<float>(i_y / CELL_SIZE) - 0.5f);
				break;
			case 3:
				y = static_cast<short>(static_cast<float>(i_y / CELL_SIZE) + 0.5f);
				break;
			}
			output.wall[a] = Cell::Wall == mapRef[x][y];
			output.boulder[a] = Cell::Boulder == mapRef[x][y];
			output.nextArea[a] = Cell::Next_Area == mapRef[x][y];
		}

	}	
	return output;
}

/*
	if (0 <= x && 0 <= y && MAP_HEIGHT >= y && MAP_WIDTH >= x) {
		output.left = Cell::Wall == mapRef[x][y];
		output.boulderLeft = Cell::Boulder == mapRef[x][y];
		output.nextAreaLeft = Cell::Next_Area == mapRef[x][y];
		//look right
		x = x + 1;
		output.right = Cell::Wall == mapRef[x][y];
		output.boulderRight= Cell::Boulder == mapRef[x][y];
		//look middle and up
		x = static_cast<short>(i_x / CELL_SIZE);
		y = static_cast<short>(static_cast<float>(i_y / CELL_SIZE) - 0.5f);
		output.up = Cell::Wall == mapRef[x][y];
		output.boulderUp = Cell::Boulder == mapRef[x][y];
		//look down
		y = static_cast<short>(static_cast<float>(i_y / CELL_SIZE) + 0.5f);
		output.down = Cell::Wall == mapRef[x][y];
		output.boulderDown = Cell::Boulder == mapRef[x][y];

	}*/