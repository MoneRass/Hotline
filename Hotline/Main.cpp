#include<iostream>
#include<SFML/Graphics.hpp>
#include"Hunter.h"
#include"Bullet.h"
#include"Menu.h"
#include"gameWorld.h"
#include"map.h"
#include"Background.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "title");

	window.setFramerateLimit(360);
	Hunter hunter;
	Menu menu(window.getSize().x, window.getSize().y);

	hunter.setPos(window.getSize().x / 2, window.getSize().y / 2);

	const int level[] =
	{

		7, 7, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
		28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
		28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
		28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28
	};


	TileMap map;
	if (!map.load("images/Platform/free.png", sf::Vector2u(16, 16), level, 40, 4))
		return -1;
	map.setScale(3.5f, 3.5f);
	map.setPosition(0, window.getSize().y / 1.5);

	Background bg;

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (menu.onMenu == true)
				{

					switch (event.key.code)
					{

					case sf::Keyboard::Up:
						menu.moveUp();
						printf("up");

						break;
					case sf::Keyboard::Down:
						menu.moveDown();
						break;
					case sf::Keyboard::Enter:
						switch (menu.getPressed())
						{
						case 0:printf("press play");
							menu.menuClear(window);
							menu.onMenu = false;
							std::cout << menu.onMenu;
							break;
						case 1:printf("press scb");

							break;
						case 2:printf("press exit");
							window.close();
							break;
						}
					default:
						break;

					}

				}
			}

		}

		hunter.update();

		window.clear();
		bg.draw(window);

		if (menu.onMenu == true)menu.draw(window);
		hunter.draw(window);
		window.draw(map);
		window.display();


	}
	return 0;
}