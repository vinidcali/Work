#include "Player.h"
#include <SDL.h>
#include <math.h>
//#include <stdio.h>


Player::Player() : GameObject() {
//	 _transform.position = { 400.0f, 400.0f, 0.0f };
	
}

Player::~Player() {

}

void Player::Initialize() {
	 _transform.position.x = 100.0f; _transform.position.y = 100.0f; _transform.position.z = 0.0f; 
	 _transform.rotation.x = 30.0f; _transform.rotation.y = 0.0f; _transform.rotation.z = 10.0f; 
}

void Player::Update(float dt) {

}

void Player::Draw(SDL_Renderer *renderer, float dt) {
//	static float rotationDegrees = 10.0f;
	 //rotationdegrees = _transform.rotation.z
//	rotationDegrees += (360 * dt);
	_transform.rotation.z += _transform.rotation.z >= 360.0f ? -360.0f : 0;		//well, cant have more than 360 degrees, right?
	_transform.position.x += _transform.position.x >= 640 ? -640 : (_transform.position.x <= 0 ? 640 : 0);
	_transform.position.y += _transform.position.y >= 640 ? -640 : (_transform.position.y <= 0 ? 640 : 0);

	//magical stuff (aka math) takes place, so we can rotate, like the woooooooorld
	float rotationRadians = MathUtils::ToRadians(_transform.rotation.z);

	Vector2 rotatedOffset = {
		_transform.rotation.x * cosf(rotationRadians) + _transform.rotation.y * sinf(rotationRadians),
		_transform.rotation.x * sinf(rotationRadians) - _transform.rotation.y * cosf(rotationRadians)
	};
	Vector2 transformedEndPoint = {_transform.position.x + rotatedOffset.x, _transform.position.y + rotatedOffset.y };
	
	//	printf("x:%f  y:%f\nendx:%f  endy:%f\n\n\n", _transform.position.x, _transform.position.y, _transform.rotation.x, _transform.rotation.y);
// 	scanf("%f", &_transform.rotation.x);

	
	SDL_RenderDrawLine(renderer,
		_transform.position.x,
		_transform.position.y,
		transformedEndPoint.x,
		transformedEndPoint.y);
}


void Player::Shoot(SDL_Renderer *renderer, float dt) {
//	printf("%f\n", dt);
}