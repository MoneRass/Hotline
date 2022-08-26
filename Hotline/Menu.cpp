#include"Menu.h"

Menu::Menu(float width, float heigth)
{
	header(width, heigth);
	
	if (!font.loadFromFile("HelpMe.ttf"))
	{

	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, heigth / (MAX_ITEM + 1) * 1.5));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Score Board");
	menu[1].setPosition(sf::Vector2f(width / 2, heigth / (MAX_ITEM + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, heigth / (MAX_ITEM + 1) * 2.5));

	selectItem = 0;
	onMenu = true;
}

Menu::~Menu()
{
	delete menu;
}

void Menu::header(float width, float heigth)
{
	if (!font.loadFromFile("HelpMe.ttf"))
	{

	}
	head.setFont(font);
	
	head.setFillColor(sf::Color::White);
	head.setString("- THE HUNTER OF HERMES -");
	head.setScale(2, 1);
	head.setPosition(sf::Vector2f((width / 2) - (5), heigth / (MAX_ITEM + 1) * 0.5));
}

void Menu::draw(sf::RenderWindow& window)
{
	window.draw(head);
	for (int i = 0; i < MAX_ITEM; i++)
	{
		window.draw(menu[i]);
	}
}
//the project im working on right now is Game Developing
void Menu::moveUp()
{
	if (selectItem - 1 >= 0)
	{
		menu[selectItem].setFillColor(sf::Color::White);
		selectItem--;
		menu[selectItem].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectItem + 1 < MAX_ITEM)
	{
		menu[selectItem].setFillColor(sf::Color::White);
		selectItem++;
		menu[selectItem].setFillColor(sf::Color::Red);
	}
}

void Menu::menuClear(sf::RenderWindow& window)
{
	window.clear();
}