#pragma once
#include<SFML/Graphics.hpp>

class Background
{
public:
	Background();
	virtual ~Background();
	void update();
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite sprite;
	sf::Texture texture;

};
