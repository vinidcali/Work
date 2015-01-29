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
	// Using the default member-wise initializer for our new struct.
//	pos =  { 100.0f, 100.0f };
	pos.x = 100.0f; pos.y = 100.0f;
//	endPointOffset = { 10.0f, 0.0f };
	endPointOffset.x = 10.0f; endPointOffset.y = 0.0f;
	speed = 5000.0f;
	rotationSpeed = 3000.0f;

	_player.Initialize();
	_asteroid.Initialize();
	
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
			//	pos.y -= (speed * dt);
				break;
			case SDLK_DOWN:
				_player._transform.position.y += (speed * dt);
			//	pos.y += (speed * dt);
				break;
			case SDLK_LEFT:
				_player._transform.rotation.z += (rotationSpeed * dt);
		//		rotationDegrees += (rotationSpeed * dt);
				break;
			case SDLK_RIGHT:
				_player._transform.rotation.z -= (rotationSpeed * dt);
			//	rotationDegrees -= (rotationSpeed * dt);
				break;
			case SDLK_SPACE:
				_projectile.setPlayerPos(_player._transform.rotation.x, _player._transform.rotation.y);
				_projectile.Update(dt);
			default:
				break;
		}
	}
	_asteroid.Update(dt);


	//player x: 200, player y: 50
	//player rx: 210, player ry: 40

	if (
		(	(_asteroid._transform.position.x >= _player._transform.position.x) &&
			(_asteroid._transform.position.x <= _player._transform.rotation.x) ) &&
			
		(	(_asteroid._transform.position.y >= _player._transform.position.y) &&
			(_asteroid._transform.position.y <= _player._transform.rotation.y) )	 

	) {
		printf("arroz!");
	}
}

void Game::DrawImpl(SDL_Renderer *renderer, float dt) {

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	
		
/*	static float rotationDegrees = 10.0f;
	rotationDegrees += (rotationSpeed * dt);
	rotationDegrees += rotationDegrees >= 360.0f ? -360.0f : 0;		//well, cant have more than 360 degrees, right?

	//magical stuff (aka math) takes place, so we can rotate, like the woooooooorld
	float rotationRadians = MathUtils::ToRadians(rotationDegrees);

	Vector2 rotatedOffset = {
		endPointOffset.x * cosf(rotationRadians) + endPointOffset.y * sinf(rotationRadians),
		endPointOffset.x * sinf(rotationRadians) - endPointOffset.y * cosf(rotationRadians)
	};
	Vector2 transformedEndPoint = {pos.x + rotatedOffset.x, pos.y + rotatedOffset.y };
	_player._transform.rotation.x = transformedEndPoint.x; _player._transform.rotation.y = transformedEndPoint.y; 
*/	
	_player.Draw(renderer, dt);
	_asteroid.Draw(renderer, dt);
	_projectile.Draw(renderer, dt);
	
//	SDL_RenderDrawLine(renderer, pos.x, pos.y, transformedEndPoint.x, transformedEndPoint.y);

}