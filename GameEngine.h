#pragma once				//ensures this header will only be included once (special for Windows)

/*	same as pragma once, but for all environments
#ifndef _GAME_ENGINE_H_
	#define _GAME_ENGINE_H_
#endif // _GAME_ENGINE_H_
*/

#include "MathUtils.h"

//Forward declarations. Because we are using pointers, the compiler knows the size
struct SDL_Renderer;
struct SDL_Window;

class GameEngine {

public:
	static GameEngine* CreateInstance();

	void Initialize();
	void Shutdown();

	void Update();
	void Draw();

	~GameEngine();


protected:
	GameEngine();

	static GameEngine *_instance;


	SDL_Window *window;
	SDL_Renderer *renderer;
	
	Vector2 pos;				//x and y
	Vector2 endPointOffset;	//using offsets simplifies math for rotating
	float oldTime, currentTime, deltaTime;
	float speed, rotationSpeed;
};