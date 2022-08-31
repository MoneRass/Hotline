#include<SFML/Graphics.hpp>

#define JUMP_SPEED 5.f
#define JUMP_TIME 4

class Hunter
{
public:

	Hunter();
	~Hunter();
	void draw(sf::RenderWindow& window);
	void update();
	void setPos(float x, float y);
	void attackColli();

private:
	int attackCount = 0;
	int jumpTimer;

	float jumpSpeed;
	float x;
	float y;

	bool move;
	bool moveRight;
	bool moveLeft;
	bool couching;
	bool attack;
	bool jump;
	bool dashing;
	bool flip;


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
	void leanBack();


	sf::Sprite sprite;
	sf::Texture texture;

	sf::IntRect idleFrame;
	sf::IntRect attackFrame;
	sf::IntRect currentFrame;

	sf::Clock animationTimer;
	sf::Clock attackDelay;
};