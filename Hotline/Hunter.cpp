#include"Hunter.h"

void Hunter::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Hunter::movement()
{
	this->move = false;
	this->couching = false;

	if (sprite.getPosition().y <= 200.f)sprite.move(0, 2.f);//Gravity
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
		flip = true;
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
		flip = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		dash();
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
	move = false;
	couching = false;
	jump = false;
	moveRight = false;
	moveLeft = false;
	dashing = false;
	flip = false;
	this->animation();
	this->update();
	this->playerSprite();

}

void Hunter::playerSprite()
{
	this->currentFrame = sf::IntRect(0, 0, 120, 80);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(1.5f, 1.5f);
	if (this->flip == true)
	{
		this->sprite.setScale(1.5f, -1.5f);
		printf("flip");
	}
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
	if (this->animationTimer.getElapsedTime().asMilliseconds() / 150 >= 0.5f)
	{
		if (move == false && couching == false)
		{
			this->idle();
		}
		if (move == true && jump == false)
		{
			this->playerRunRight();
		}
		if (attack == true)
		{
			this->playerAttack();

		}
		else if (dashing == true)this->dash();
	}
	else if (move == false && couching == true)
	{
		this->couch();
	}
	if (flip == true)
	{

	}
	else this->currentFrame = sf::IntRect(0, 0, 120, 80);
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
	//jumpTimer = JUMP_TIME;
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
	this->texture.loadFromFile("images/playerSprite1/_Jump.png");
	this->sprite.setTexture(texture);
	this->currentFrame.left += 120.f;

	if (this->currentFrame.left >= 360)
	{
		this->currentFrame.left = 0;
	}
	this->animationTimer.restart();
	this->sprite.setTextureRect(this->currentFrame);

}

void Hunter::dash()
{
	this->jump = false;
	this->attack = false;
	sprite.move(10.f, 0);
	this->texture.loadFromFile("images/playerSprite1/_Roll.png");
	this->sprite.setTexture(texture);
	this->currentFrame.left += 120.f;

	if (this->currentFrame.left >= 1440)
	{
		this->currentFrame.left = 0;
	}
	this->animationTimer.restart();
	this->sprite.setTextureRect(this->currentFrame);
}

void Hunter::setPos(float x, float y)
{
	sprite.setPosition(x, y);
}

void Hunter::attackColli()
{
	this->sprite.getGlobalBounds().width / 2.f;
	this->sprite.getGlobalBounds().height;
}