#include "GameEngine.h"
#include <SDL.h>
#include "MathUtils.h"


GameEngine::GameEngine() {

}

GameEngine::~GameEngine() {

}


void GameEngine::Initialize() {

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	_window = SDL_CreateWindow("Vini's Firstborn - Terrible Edition!           ~~~    0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	//two ways to render: accelerated (hardware) and software (and hardware doesnt sup a feature)
	
	InitializeImpl();

	_engineTimer.Start();					//get time at the beginning of game loop, so we can track the elapsed difference

}



void GameEngine::Update() {

	_engineTimer.Update();						 //calculates time difference since last loop (ms > s)

	UpdateImpl(_engineTimer.GetDeltaTime());	
	
}

void GameEngine::Draw() {
	
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);

	SDL_RenderClear(_renderer);

	DrawImpl(_renderer, _engineTimer.GetDeltaTime());

	SDL_RenderPresent(_renderer);			//actually show everything
}


void GameEngine::Shutdown() {
	_engineTimer.Stop();

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}