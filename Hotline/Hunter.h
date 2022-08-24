#include<SFML/Graphics.hpp>

class Hunter
{
public:

	Hunter();
	virtual ~Hunter();
	void draw(sf::RenderWindow& window);

	void idle();
	void update();

private:
	
	void movement();
	sf::Sprite sprite;
	sf::Texture texture;

};