#pragma once
#include<SFML/Graphics.hpp>
#include<stdbool.h>

#define MAX_ITEM 3

class Menu
{
public:
	Menu(float width, float heigth);
	~Menu();

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void header(float width, float heigth);
	void menuClear(sf::RenderWindow& window);

	int getPressed() { return selectItem; };

	bool onMenu;

private:
	int selectItem;
	sf::Font font;
	sf::Text menu[MAX_ITEM];
	sf::Text head;
};
