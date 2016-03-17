#pragma once
#include "BaseState.h"
#include "SystemManager.h"
#include "AssetManager.h"

class StateMenu :
	public BaseState
{
public:
	StateMenu();
	//Takes in Game's systemManager and assetManager.
	StateMenu(SystemManager *, AssetManager *);
	~StateMenu();

	//Update function. Overloads the pure virtual update function in BaseState.
	virtual void update(double, sf::RenderWindow *);
private:
	sf::Mouse mouse;
	sf::Vector2i centerCoordinates;
};

