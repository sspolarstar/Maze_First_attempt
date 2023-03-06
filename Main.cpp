
#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

#include "Animation.hpp"
#include "MapCollider.hpp"
#include "Player.hpp"
#include "mazeBuilder.hpp" 
#include "Global.hpp"

int main()
{
    //set the window to build this guy.
    sf::RenderWindow window(sf::VideoMode(MAP_WIDTH * CELL_SIZE * SCREEN_RESIZE, (TEXT_HEIGHT + MAP_HEIGHT * CELL_SIZE) * SCREEN_RESIZE), "MazeGame", sf::Style::Close);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("img/characters.png");
    //texture, image count, switch time, and speed
    Player player(&playerTexture, sf::Vector2u(23,4), 0.2f, 50.0f);

    //window.setFramerateLimit(60);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, TEXT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    //std::cout << "Test Space";
    std::array<std::string, MAP_HEIGHT> mapSketch = {
        "*****************q**************",
        "*                              *", //h 18 w 32
        "*     *                        *",
        "*      *      *                *",
        "*       *     *                *",
        "*        * ** *    *    *      *",
        "*        *   **    *    *      *",
        "*  ******  *  *    *    *      *",
        "*  *       * ***   *    *      *",
        "*  *  *  * *  *                *",
        "*  *  ********************     *",
        "****                *          *",
        "*      *****        *   ********",
        "*   ****       *    *   *   *  *",
        "*   *    **** ***   *   *   *  *",
        "*   * *  *  * * *   *   *   *  *",
        "*   * *     * *           p    *",
        "********************************",
    };
    std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH> map{};

    float deltaTime = 0.0f;
    sf::Clock clock;

    map = convertSketch(mapSketch, player);

    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, TEXT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)   window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        player.Update(deltaTime, map);
        window.clear();
        DrawMap(window, map);
        player.Draw(window);
        window.display();
    }


    return 0;
}
