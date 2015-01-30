#include "Game.h"
#include <SDL.h>
#include <math.h>
#include <stdio.h>


GameEngine* GameEngine::_instance = nullptr;		//initializing static member pointer

GameEngine* GameEngine::CreateInstance() {
  
	if (_instance == nullptr)
		_instance = new Game();

	return _instance;

}

Game::Game() : GameEngine() {

}

void Game::InitializeImpl() {
	pos.x = 100.0f; pos.y = 100.0f;
	endPointOffset.x = 10.0f; endPointOffset.y = 0.0f;
	speed = 5000.0f;
	rotationSpeed = 3000.0f;

	_player.Initialize();
	_asteroid.Initialize();
	_projectile.Initialize();
}

void Game::UpdateImpl(float dt) {
	SDL_Event evt;
	SDL_PollEvent(&evt);				//captures events from the window

	char* title = "Vini's Firstborn - Terrible Edition!           ~~~    0";
	SDL_SetWindowTitle(_window, title);
	if (evt.type == SDL_KEYDOWN) {
		SDL_KeyboardEvent &keyboardEvt = evt.key;
		SDL_Keycode &keyCode = keyboardEvt.keysym.sym;	//key symbols
		switch (keyCode) {
			case SDLK_UP:
				_player._transform.position.x -= (speed * dt);
				_player._transform.position.y -= (speed * dt);
				break;
			case SDLK_DOWN:
				_player._transform.position.y += (speed * dt);
				break;
			case SDLK_LEFT:
				_player._transform.rotation.z += (rotationSpeed * dt);
				break;
			case SDLK_RIGHT:
				_player._transform.rotation.z -= (rotationSpeed * dt);
				break;
			case SDLK_SPACE:
				_projectile.setPlayerPos(_player._transform.rotation.x, _player._transform.rotation.y);
				_projectile.move(dt);
			default:
				break;
		}
	}
	_asteroid.Update(dt);

}

void Game::DrawImpl(SDL_Renderer *renderer, float dt) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
		
	_player.Draw(renderer, dt);
	_asteroid.Draw(renderer, dt);
	_projectile.Draw(renderer, dt);
}