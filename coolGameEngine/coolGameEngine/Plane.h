#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

#include "SystemManager.h"
#include "Entity.h"

class Plane
{
private:
	int missilesLeft, totalMissiles, targetOne, targetTwo, targetThree;

public:
	Plane();
	Plane(int, int);
	~Plane();
	void setTargets();
	double setSlope(int, int);
	void setTotalMissiles(int);
	void setMissilesLeft(int);
	int getMissilesLeft();
	int getTotalMissiles();
	int launchMissiles(SystemManager*, Entity *, sf::RenderWindow *); //Returns 0 if it fails to launch, 1 if it successfully launches
	void update(sf::RenderWindow *, Entity *);

};