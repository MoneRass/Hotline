#include"Hunter.h"

void Hunter::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Hunter::movement()
{
	move = false;
	couching = false;
	jump = false;
	moveRight = false;
	moveLeft = false;
	if(sprite.getPosition().y <= 200.f)sprite.move(0, 2.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//sprite.move(0, -5.f);
		jump = true;
		jumpFunc();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-2.f, 0);
		move = true;
		moveLeft = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		couching = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(2.f, 0);
		move = true;
		moveRight = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		attack = true;
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
	this->sprite.setScale(1.5f, 1.5f);
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

	this->texture.loadFromFile("images/playerSprite1/_Attack.png");
	this->sprite.setTexture(texture);
	this->currentFrame.left += 120.f;

	if (this->currentFrame.left >= 480)
	{
		this->currentFrame.left = 0;
	}
	printf("attack");
	this->sprite.setTextureRect(this->currentFrame);
	this->animationTimer.restart();
	attack = false;
}

void Hunter::playerRunRight()
{
	this->texture.loadFromFile("images/playerSprite1/_Run.png");
	this->sprite.setTexture(texture);
	this->currentFrame.left += 120.f;

	if (this->currentFrame.left >= 1200)
	{
		this->currentFrame.left = 0;
	}
	this->animationTimer.restart();
	this->sprite.setTextureRect(this->currentFrame);
}

void Hunter::couch()
{
	this->move = false;
	this->texture.loadFromFile("images/playerSprite1/_Crouch.png");
	this->sprite.setTexture(texture);
	this->currentFrame.left = 0.f;
	this->sprite.setTextureRect(this->currentFrame);
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
		if (move == true && jump == false)
		{
			this->playerRunRight();
		}
		if (attack == true)
		{
			this->playerAttack();
			
		}
		if (move == false)
		{
			this->idle();
		}
	}
	else if (move == false && couching == true)
	{
		this->couch();
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

void Hunter::jumpFunc()
{
		if (jump == true && moveRight == true)
		{
			sprite.move(1.f, -5.f);
			printf("jump");
		}
		else if (jump == true && moveLeft == true)
		{
			sprite.move(-1.f, -5.f);
		}
		else if (jump == true)
		{
			sprite.move(0, -5.f);
		}
		jump = false;
		animationTimer.restart();

}

//help