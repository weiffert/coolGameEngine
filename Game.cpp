#include "stdafx.h"

#include <string>

#include "SFML\Window.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Graphics.hpp"

#include "Game.h"
#include "BaseState.h"
#include "SystemManager.h"
#include "AssetManager.h"


Game::Game(int width, int height, std::string name)
{
	windowResolution.x = width;
	windowResolution.y = height;
	gameName = name;
	systemManager = new SystemManager();
	assetManager = new AssetManager();
}

Game::~Game()
{

}


int Game::run()
{
	state = new StateLoading* (systemManager, assetManager);
	systemManager->add(state);
	exitCode = gameLoop();
	//cleanup
	return exitCode;
}


int Game::gameLoop()
{
	bool running = true;
	int changeStateFlag = 1;
	//initialize time keepers
	double totalTime = 0.0;
	double frameRate = 0.01;

	double lag = 0.0;
	double currentTime = time(NULL);

	while(gameWindow.isOpen())
	{
		//initialize current time keepers
		double newTime = time(NULL);
		double frameTime = newTime - currentTime;
		
		if (frameTime > 0.25)
			frameTime = 0.25;

		currentTime = newTime;

		lag += frameTime;
		//process input
		while (lag >= frameRate)
		{
			//update
			changeStateFlag = state->update(totalTime, &gameWindow);
			//decrement current time keepers
			totalTime += frameRate;
			lag -= frameRate;
		}
		//render with parameters.
		state->render(lag/frameRate, &gameWindow);
	}
	return exitCode;
}
