#include<iostream>
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Bullet.h"
#include"Menu.h"
#include"gameWorld.h"
#include"map.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "title");

	window.setFramerateLimit(360);

	Menu menu(window.getSize().x, window.getSize().y);

	Bullet bull;
	
	GameWorld gameWorld = GameWorld();

	sf::Texture texture;
	if (!texture.loadFromFile("images/sliced-tileset/wall.png"))return 0;
	sf::Sprite sprite;
	sprite.setTexture(texture);


	while (window.isOpen())
	{
		sf::Event event;
			
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
				window.close();
			
			//Player.playerLook(window);
			//Player.playerLook2();
			
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

		

		window.clear();

		if(menu.onMenu==true)menu.draw(window);
		for (int i = 0; i < gameWorld.gridLength; i++)
		{
			for (int j = 0; j < gameWorld.gridLength; j++)
			{
				window.draw(gameWorld.tiles[i][j]->sprite);
			}
		}
		window.draw(sprite);
		window.display();


	}
	return 0;
}