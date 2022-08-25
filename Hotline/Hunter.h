#include<SFML/Graphics.hpp>

#define FRAME 120


class Hunter
{
public:

	Hunter();
	virtual ~Hunter();
	void draw(sf::RenderWindow& window);

	void idle();
	void update();
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

private:
	int attackCount=0;
	bool move;
	bool moveRight;
	bool moveLeft;
	bool couching;
	bool attack;
	bool jump;
	void movement();
	sf::Sprite sprite;
	sf::Texture texture;
		
	sf::IntRect idleFrame;
	sf::IntRect attackFrame;
	sf::IntRect currentFrame;

	sf::Clock animationTimer;
	sf::Clock attackDelay;
};