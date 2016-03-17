#include "stdafx.h"

#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"

#include "StateMenu.h"
#include "SystemManager.h"
#include "AssetManager.h"
#include "Property.h"
#include "Entity.h"
//include controllers.


StateMenu::StateMenu()
{
	//Sets defaults.
	id = "Menu";
	number = 2;
	systemManager = nullptr;
	assetManager = nullptr;
}

StateMenu::StateMenu(SystemManager *s, AssetManager *a)
{
	//Sets defaults.
	id = "Menu";
	number = 2;
	systemManager = s;
	assetManager = a;
}


StateMenu::~StateMenu()
{
}


//Polls for events and calls the PlayerInput controller accordingly.
//Takes in the total time elapsed and the window.
void StateMenu::update(double totalTime, sf::RenderWindow *window)
{
	//Check for arrow key and space bar events
	sf::Event event;
	while (window->pollEvent(event))
	{
		centerCoordinates.x = (window->getSize().x) / 2;
		centerCoordinates.y = (window->getSize().y) / 2;
		mouse.setPosition(centerCoordinates, *window);
		bool moveUp = false, moveDown = false, moveRight = false, moveLeft = false, spaceBarReleased = false;

		//Checks if trackball moved up
		if (mouse.getPosition.y > centerCoordinates.y)
			moveUp = true;
		//Checks if trackball moved down
		if (mouse.getPosition.y < centerCoordinates.y)
			moveDown = true;
		//Checks if trackball moved right
		if (mouse.getPosition.x > centerCoordinates.x)
			moveRight = true;
		//Checks if trackball moved left
		if (mouse.getPosition.x < centerCoordinates.x)
			moveLeft = true;
		//Checks if space bar released
		if ((event.type = sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Space))
		{
			spaceBarReleased = true;
		}
		//Checks if escape key pressed
		if ((event.type = sf::Event::KeyReleased) && (event.key.code == sf::Keyboard::Escape))
		{
			BaseState::changeState(this, "Pause");
		}
		if (event.type == sf::Event::Closed)
			window->close();
		//Run through the game controllers.
		//Example: Checking for collisions
		//systemManager->getController("PlayerInput")->control(moveUp, moveDown, moveRight, moveLeft, spaceBarReleased, &material);
	}
}