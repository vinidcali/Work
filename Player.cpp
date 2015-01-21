#include "Player.h"
#include <SDL.h>

void Player::Initialize() {

}

void Player::Update(float dt) {

}

void Player::Draw(SDL_Renderer *renderer, float dt) {
	SDL_RenderDrawLine(renderer, 200, 200, 400, 500);
}


Player::Player() : GameObject() {}