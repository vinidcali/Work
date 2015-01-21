#include "GameEngine.h"
#include <SDL.h>
#include <math.h>
#include "MathUtils.h"
#include "Player.h"


GameEngine::GameEngine() {

}

GameEngine::~GameEngine() {

}


void GameEngine::Initialize() {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	window = SDL_CreateWindow("Vini's firstborn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//two ways to render: accelerated (hardware) and software (and hardware doesnt sup a feature)
	
	pos.x = 100.0f; pos.y = 100.0f;
	endPointOffset.x = 10.0f; endPointOffset.y = 0.0f;
	speed = 10.0f;
	rotationSpeed = 360.0f;

	oldTime = SDL_GetTicks();				//get time at the beginning of game loop, so we can track the elapsed difference
	currentTime = oldTime;

}



void GameEngine::Update() {
	SDL_Event evt;
	SDL_PollEvent(&evt);				//captures events from the window

	oldTime = currentTime;
	currentTime = SDL_GetTicks();
	deltaTime = (currentTime - oldTime) / 1000;	 //calculates time difference since last loop (ms > s)

	
	if (evt.type == SDL_KEYDOWN) {
		SDL_KeyboardEvent &keyboardEvt = evt.key;
		SDL_Keycode &keyCode = keyboardEvt.keysym.sym;	//key symbols
		switch (keyCode) {
			case SDLK_UP:
				pos.y -= (speed * deltaTime);
				break;
			case SDLK_DOWN:
				pos.y += (speed * deltaTime);
				break;
			case SDLK_LEFT:
			//	rotationDegrees += (rotationSpeed * deltaTime);
				break;
			case SDLK_RIGHT:
			//	rotationDegrees -= (rotationSpeed * deltaTime);
				break;
			default:
				break;
		}
	}
}

void GameEngine::Draw() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);	
	SDL_RenderClear(renderer);								//clear the renderer/screen with the current draw color (0, white)
		
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	//choose black for drawing everything else
		
	static float rotationDegrees = 10.0f;
	rotationDegrees += (rotationSpeed * deltaTime);
	rotationDegrees += rotationDegrees >= 360.0f ? -360.0f : 0;		//well, cant have more than 360 degrees, right?


	//magical stuff (aka math) takes place, so we can rotate, like the woooooooorld
	float rotationRadians = MathUtils::ToRadians(rotationDegrees);

	Vector2 rotatedOffset = {
		endPointOffset.x * cosf(rotationRadians) + endPointOffset.y * sinf(rotationRadians),
		endPointOffset.x * sinf(rotationRadians) - endPointOffset.y * cosf(rotationRadians)
	};
	Vector2 transformedEndPoint = {pos.x + rotatedOffset.x, pos.y + rotatedOffset.y };
		
	SDL_RenderDrawLine(renderer, pos.x, pos.y, transformedEndPoint.x, transformedEndPoint.y);



	Player *p = new Player();
	p->Draw(renderer, deltaTime);




	SDL_RenderPresent(renderer);			//actually show everything
}


void GameEngine::Shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}