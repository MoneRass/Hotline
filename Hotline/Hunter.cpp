#include"Hunter.h"

void Hunter::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Hunter::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, -1.f);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-1.f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(1.f, 0);
	}
}

Hunter::~Hunter()
{

}

Hunter::Hunter()
{
	texture.loadFromFile("images/playerSprite1/_Idle.png");
	sprite.setTexture(texture);
	

}

void Hunter::idle()
{
	sf::IntRect rect;
}