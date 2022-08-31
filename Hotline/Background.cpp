#include"Background.h"

void Background::draw(sf::RenderWindow& window)
{
	window.draw(this->sprite);
}

void Background::update()
{

}

Background::Background()
{
	this->texture.loadFromFile("images/middleground.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(5.f, 5.f);
}

Background::~Background()
{

}