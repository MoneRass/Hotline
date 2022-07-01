#include<iostream>
#include<SFML/Graphics.hpp>
#include<math.h>

class control
{
	sf::Event event;
public:
	void playerMove(char key) {
		if (key == sf::Keyboard::W) {
			printf("W");
		}
		if (key == sf::Keyboard::A) {
			printf("A");
		}
		if (key == sf::Keyboard::S) {
			printf("S");
		}
		if (key == sf::Keyboard::D) {
			printf("D");
		}
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "title");
	
	window.setFramerateLimit(60);

	sf::Event event;

	sf::CircleShape center(20);
	//center.setOrigin(0.f, 0.f);
	center.setFillColor(sf::Color::Red);
	center.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

	sf::Vector2f playerSize(50.f, 50.f);
	sf::RectangleShape player(playerSize);
	player.setOrigin(playerSize.x / 2.f, playerSize.y / 2.f);
	player.setPosition(400, 300);

	sf::CircleShape spinner(80, 3);
	spinner.setPosition(300, 300);

	control Player;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) window.close();
			
			if (event.type == sf::Event::KeyPressed) 
			{
				Player.playerMove(event.key.code);
			}
			if (event.type == sf::Event::MouseMoved) 
			{
				//std::cout << "X : " << event.mouseMove.x << std::endl;
				//std::cout << "Y : " << event.mouseMove.y << std::endl;
				//sf::Vector2f lookdir;
				float lookdirX = event.mouseMove.x - player.getPosition().x;
				float lookdirY = event.mouseMove.y - player.getPosition().y;
				float angle = atan2(lookdirY,lookdirX) * 57.29578;
				player.setRotation(angle);

			}
			
			
		}
	//Update
		

	//Renderer
	window.clear();
	window.draw(player);
	//window.draw(center);
	window.draw(spinner);
	window.display();
	}
	return 0;
}