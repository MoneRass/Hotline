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

private:
	
	bool move;
	bool attack;
	void movement();
	sf::Sprite sprite;
	sf::Texture texture;
		
	sf::IntRect idleFrame;
	sf::IntRect attackFrame;
	sf::IntRect currentFrame;

	sf::Clock animationTimer;
};