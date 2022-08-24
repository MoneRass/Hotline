#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class Bullet
{
public:
	Bullet(float radius = 5.f)
		:bulletVelo(0.f, 0.f), maxSpeed(15.f)
	{
		bulletShape.setRadius(radius);
		bulletShape.setFillColor(sf::Color::Red);
		
	}
private:
	sf::CircleShape bulletShape;
	sf::Vector2f bulletVelo;

	std::vector<Bullet> bullets;

	float maxSpeed;
};