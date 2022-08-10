#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdbool.h>

#ifndef GAMETILE_H
#define GAMETILE_H


class gameTile
{
public:
	void draw(sf::RenderWindow& window);
	bool setUpSprite(std::string);
	gameTile(std::string, float , float , bool , bool);
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f pos;
	
	bool isPass;
	bool isExit;
private:
};

#endif