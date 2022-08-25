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
		sprite.move(0, -5.f);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-5.f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, 5.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(5.f, 0);
		move = true;
	}
}

Hunter::~Hunter()
{

}

Hunter::Hunter()
{
	
	this->animation();
	this->update();
	this->playerSprite();
}

void Hunter::playerSprite()
{
	this->currentFrame = sf::IntRect(0, 0, 120, 80);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(5.5f, 5.5f);
}

void Hunter::idle()
{
	this->texture.loadFromFile("images/playerSprite1/_Idle.png");
	this->sprite.setTexture(texture);
	
	this->currentFrame.left += 120.f;
	
	if (this->currentFrame.left >= 1200)
	{
		this->currentFrame.left = 0;
	}
	this->animationTimer.restart();
	this->sprite.setTextureRect(this->currentFrame);
}

void Hunter::playerAttack()
{
	this->texture.loadFromFile("images/playerSprite1/_Attack");
	this->sprite.setTexture(texture);
	
	this->animationTimer.restart();
}

void Hunter::update()
{
	this->movement();
	this->animation();
}

void Hunter::animation()
{
	if (this->animationTimer.getElapsedTime().asMilliseconds() / 100 >= 0.5f)
	{
		if (move == false)
		{
			this->idle();
			printf("r");
		}
		

	}
}

void Hunter::updateAmination()
{
	this->animationTimer.restart();
}

void Hunter::initVariable()
{
	this->move = false;
}