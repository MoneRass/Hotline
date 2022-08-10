#pragma once
#include<SFML/Graphics.hpp>
#include"map.h"
#include<vector>

#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld
{
public:
	std::vector<std::vector<gameTile*> > tiles;
	int gridLength;
	GameWorld();
private:
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> enemyPosition;
	
	void setUpIns();
	void setUpEnpos();
	void setUptile();
};

#endif // !GAMEWORLD_H