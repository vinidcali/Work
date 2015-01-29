#include "Asteroid.h"
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
//#include <stdio.h>


Asteroid::Asteroid() : GameObject() {
//	 _transform.position = { 400.0f, 400.0f, 0.0f };
//	 _transform.position.x = 100.0f; _transform.position.y = 100.0f; _transform.position.z = 0.0f; 
	
}

Asteroid::~Asteroid() {
	//SDL_destroy
}

void Asteroid::Initialize() {
	 srand (time(NULL));
	_transform.position.x = rand() % 620 + 20;

//	srand (time(NULL));
	_transform.position.y = rand() % 620 + 20;


//	printf("x: %d, y: %d\n\n", _transform.position.x, _transform.position.y);
}

void Asteroid::Update(float dt) {
	 srand (time(NULL));
	int r = rand() % 620 + 20;
	_transform.position.x += _transform.position.x >= 640 ? -640 : 100 * dt;
	_transform.position.y += _transform.position.y >= 640 ? -640 : 100 * dt;
}

void Asteroid::Draw(SDL_Renderer *renderer, float dt) {
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y);
}
