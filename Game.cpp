#include "Game.h"


GameEngine* GameEngine::_instance = nullptr;		//initializing static member pointer

GameEngine* GameEngine::CreateInstance() {
  
	if (_instance == nullptr)
		_instance = new GameEngine();

	return _instance;

}

Game::Game() : GameEngine() {

}