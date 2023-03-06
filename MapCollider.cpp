#include "MapCollider.hpp"

collided map_collision(float i_x, float i_y, const std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& mapRef) {
	collided output;

	float distance = ceil(CELL_SIZE / 2.0f);
	//Getting the position.
	short x = static_cast<short>((i_x - distance) / CELL_SIZE);
	short y = static_cast<short>(i_y / CELL_SIZE);

	if (0 <= x && 0 <= y && MAP_HEIGHT >= y && MAP_WIDTH >= x) {
		if (Cell::Wall == mapRef[x][y]) {
			output.left = true;
		}
		x = x + 1;
		if(Cell::Wall == mapRef[x][y]){
			output.right = true;
		}
		x = static_cast<short>(i_x / CELL_SIZE);
		y = static_cast<short>(static_cast<float>(i_y / CELL_SIZE) - 0.5f);
		if (Cell::Wall == mapRef[x][y]) {
			output.up = true;
		}
		y = static_cast<short>(static_cast<float>(i_y / CELL_SIZE) + 0.5f);
		if (Cell::Wall == mapRef[x][y]) {
			output.down = true;
		}
		if (Cell::Next_Area == mapRef[x][y]) {
			output.up = true;
		}
	}

		// Now, let us check all the values so that we can give the collider a function!
		//first, we need this not to break on the edge of the screen, eh?
	return output;
}

