#include<SFML/Graphics.hpp>

class Hunter
{
public:

	Hunter();
	virtual ~Hunter();
	void draw(sf::RenderWindow& window);

	void idle();
	void update();
	void animation();
	void playerSprite();

private:
	
	bool move;
	void movement();
	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect idleFrame;
	sf::Clock animationTimer;
};