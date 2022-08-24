#include"Hunter.h"

void Hunter::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Hunter::movement()
{
	move = false;
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
		move = true;
	}
}

Hunter::~Hunter()
{

}

Hunter::Hunter()
{
	this->playerSprite();
	this->update();
}

void Hunter::playerSprite()
{
	texture.loadFromFile("images/playerSprite1/_Idle.png");
	sprite.setTexture(texture);
	sprite.setScale(1.f, 1.f);
	idleFrame = sf::IntRect(0, 0, 120, 80);
	sprite.setTextureRect(sf::IntRect(idleFrame));

}

void Hunter::idle()
{
}

void Hunter::update()
{
	this->movement();
	this->animation();
}

void Hunter::animation()
{
	if (move == false)//IDLE
	{
		this->idleFrame.left += 120.f;
		if (this->idleFrame.left >= 1200.f)
			this->idleFrame.left = 0;
	}
	this->sprite.setTextureRect(this->idleFrame);
}