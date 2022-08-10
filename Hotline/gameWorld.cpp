#include "gameWorld.h"

GameWorld::GameWorld()
{
	gridLength = 8;
	setUpIns();
}

void GameWorld::setUpIns()
{
	exitPos = sf::Vector2i(1, 0);
	playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
	setUpEnpos();
	setUptile();
}

void GameWorld::setUpEnpos()
{
	enemyPosition.clear();
	enemyPosition.push_back(sf::Vector2i(0, 2));
	enemyPosition.push_back(sf::Vector2i(6, 0));
	enemyPosition.push_back(sf::Vector2i(2, 7));
}

void GameWorld::setUptile()
{
	tiles.clear();
	std::vector<gameTile*>firstRow;
	firstRow.push_back(new gameTile("images/sliced-tileset/wall.png", 0, 0, false, false));
	firstRow.push_back(new gameTile("images/sliced-tileset/wall.png", 50, 0, true, true));
	firstRow.push_back(new gameTile("images/sliced-tileset/wall.png", 100, 0, false, false));
	firstRow.push_back(new gameTile("images/sliced-tileset/wall.png", 150, 0, true, true));
	firstRow.push_back(new gameTile("images/sliced-tileset/wall.png", 200, 0, false, false));
	tiles.push_back(firstRow);

	std::vector<gameTile*> secondRow;
	secondRow.push_back(new gameTile("images/sliced-tileset/wall.png", 0, 50, false, false));
	secondRow.push_back(new gameTile("images/sliced-tileset/wall.png", 50, 50, true, true));
	secondRow.push_back(new gameTile("images/sliced-tileset/wall.png", 100, 50, false, false));
	secondRow.push_back(new gameTile("images/sliced-tileset/wall.png", 150, 50, true, true));
	secondRow.push_back(new gameTile("images/sliced-tileset/wall.png", 200, 50, false, false));
	tiles.push_back(secondRow);
}