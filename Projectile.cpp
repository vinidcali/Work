#include "Projectile.h"
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
//#include <stdio.h>


Projectile::Projectile() : GameObject() {

}

Projectile::~Projectile() {
	
}

void Projectile::Initialize() {
	_transform.position.x = 0; _transform.position.y = 0; _transform.position.z = 0.0f; 
	
}

void Projectile::Update(float dt) {
	_transform.position.x += _transform.position.x >= 640 ? -640 : 250 * dt;
	_transform.position.y += _transform.position.y >= 640 ? -640 : 250 * dt;
}

void Projectile::Draw(SDL_Renderer *renderer, float dt) {
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y);
}

void Projectile::setPlayerPos(float x, float y) {
	_transform.position.x = x; _transform.position.y = y; _transform.position.z = 0.0f; 
}

void Projectile::move(float dt) {
	while ((250*dt) < 1000) {
		Projectile::Update(dt);
	}
}