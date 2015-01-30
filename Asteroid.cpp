#include "Asteroid.h"
#include <SDL.h>
#include <stdlib.h>
#include <time.h>


Asteroid::Asteroid() : GameObject() {
	
}

Asteroid::~Asteroid() {
}

void Asteroid::Initialize() {
	 srand(time(NULL));
	_transform.position.x = ((float(rand()) / float(RAND_MAX)) * (640 - -640)) + -640;
	_transform.position.y = ((float(rand()) / float(RAND_MAX)) * (640 - -640)) + -640;
}

void Asteroid::Update(float dt) {
//So here we got a whole bunch of random craziness because I was trying something and I think it worked!
//Basically, the asteroids can change their minds midflight and go another way. Isn't that SUPER?!
//However, they seem to be stuck to the same diagonal path, they just come and go that specific way.
//I think it has to do with how random works (or the way I used it).
	srand(time(NULL));
	int r1, r2, rFinal;
	int posOrNeg = rand() % 2 == 0 ? 1 : -1;
	
	r1 = ((float(rand()) / float(RAND_MAX)) * (300 - -300)) + -300;
	r2 = ((float(rand()) / float(RAND_MAX)) * (r1 - r1)) + r1;
	rFinal = ((float(rand()) / float(RAND_MAX)) * (r2 - r2)) + r2;

	_transform.position.x += _transform.position.x >= 640 ? -640 : rFinal * posOrNeg * dt;

	rFinal = ((float(rand()) / float(RAND_MAX)) * (rFinal - rFinal)) + rFinal;
	_transform.position.y += _transform.position.y >= 640 ? -640 : rFinal * posOrNeg * dt;
}

void Asteroid::Draw(SDL_Renderer *renderer, float dt) {
	SDL_Rect *asteroid = new SDL_Rect;
	asteroid -> x = _transform.position.x; asteroid -> y = _transform.position.y;
	asteroid -> h = 20; asteroid -> w = 20;
	SDL_RenderDrawRect(renderer, asteroid);
}
