#include<SFML/Graphics.hpp>

#define JUMP_SPEED 5.f
#define JUMP_TIME 4

class Hunter
{
public:

	Hunter();
	virtual ~Hunter();
	void draw(sf::RenderWindow& window);
	void update();


private:
	int attackCount=0;
	int jumpTimer;
	
	float jumpSpeed;

	bool move;
	bool moveRight;
	bool moveLeft;
	bool couching;
	bool attack;
	bool jump;
	
	
	void idle();
	void animation();
	void updateAmination();
	void playerSprite();
	void playerAttack();
	void initVariable();
	void playerRunRight();
	void playerRunLeft();
	void couch();
	void dash();
	void jumpFunc();
	void movement();
	
	
	sf::Sprite sprite;
	sf::Texture texture;
		
	sf::IntRect idleFrame;
	sf::IntRect attackFrame;
	sf::IntRect currentFrame;

	sf::Clock animationTimer;
	sf::Clock attackDelay;
};