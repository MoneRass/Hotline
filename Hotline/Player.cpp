#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include<math.h>



/*void player::playerLook2()
{
	float lookdirX = event.mouseMove.x - playerBody.getPosition().x;
	float lookdirY = event.mouseMove.y - playerBody.getPosition().y;
	float angle = atan2(lookdirY, lookdirX) * 57.29578;
	playerBody.setRotation(angle);

}

void player::playerLook(sf::RenderWindow &window)
{
	playerCenter = sf::Vector2f(playerBody.getPosition());
	mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePos - playerCenter;
	aimDirNorm = aimDir / (aimDirNorm.x+aimDirNorm.y);

	float PI = 3.14159265f;

	/*float lookdirX = event.mouseMove.x - playerBody.getPosition().x;
	float lookdirY = event.mouseMove.y - playerBody.getPosition().y;
	
	float angle = atan2(aimDirNorm.y, aimDirNorm.x) * 180/PI;
	playerBody.setRotation(angle + 90);

	

}

void player::playerShoot()
{
	
}

void player::drawTo(sf::RenderWindow& window)
{
	window.draw(playerBody);
}

void player::setPos(sf::Vector2f newPos)
{
	playerBody.setPosition(newPos);
}

player::player(sf::Vector2f size)
{
	playerBody.setSize(size);
	playerBody.setOrigin(playerBody.getSize().x / 2, playerBody.getSize().y / 2);
	playerCenter = sf::Vector2f(playerBody.getPosition());
	
}

void player::playerUpdate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		playerBody.move(-10.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		playerBody.move(10.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		playerBody.move(0.f, -10.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		playerBody.move(0.f, 10.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))printf("B");

}*/
