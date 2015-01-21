#pragma once

#include "GameObject.h"


class Player : GameObject {

public:
	void Initialize();
	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);


	Player();

};
