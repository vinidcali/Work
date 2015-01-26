#pragma once

#include "GameObject.h"


class Player : public GameObject {

public:
	void Initialize();
	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);


	Player();
	~Player();

};
