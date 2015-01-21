#include <iostream>
#include "Game.h"

using namespace std;

/* // A structure to hold two floats. Similar to SDL_Point (though it contains ints).
struct Vector2D {
  float x;
  float y;
};
*/


int main(int argc, char** argv) {

/*	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);

	SDL_Window *window = SDL_CreateWindow("Vini's firstborn", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, SDL_WINDOW_SHOWN);

//	system("pause");						//freezes the whole shit and asks to press a any key to continue

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//two ways to render: accelerated (hardware) and software (and hardware doesnt sup a feature)

	Vector2D pos = { 100.0f, 100.0f };			//x and y
	Vector2D endPointOffset = { 10.0f, 0.0f };	//using offsets simplifies math for rotating
	float oldTime, currentTime, deltaTime;
	float speed = 50.0f, rotationSpeed = 120.0f;

	oldTime = SDL_GetTicks();				//get time at the beginning of game loop, so we can track the elapsed difference
	currentTime = oldTime;

	while(true) {							//main loop (or game loop), beginning point of everything, its what god made first
		SDL_Event evt;
		SDL_PollEvent(&evt);				//captures events from the window

		oldTime = currentTime;
		currentTime = SDL_GetTicks();
		deltaTime = (currentTime - oldTime) / 1000;	 //calculates time difference since last loop (ms > s)

		static float rotationDegrees = 10.0f;
	//	rotationDegrees += (rotationSpeed * deltaTime);
		rotationDegrees += rotationDegrees >= 360.0f ? -360.0f : 0;		//well, cant have more than 360 degrees, right?

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
					rotationDegrees += (rotationSpeed * deltaTime);
					break;
				case SDLK_RIGHT:
					rotationDegrees -= (rotationSpeed * deltaTime);
					break;
				default:
					break;
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);	
		SDL_RenderClear(renderer);								//clear the renderer/screen with the current draw color (0, white)
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);	//choose black for drawing everything else
		
	//	SDL_RenderDrawPoint(renderer, posX, posY);
		
		//magical stuff (aka math) takes place, so we can rotate, like the woooooooorld
		float degreesToRadians = 3.1415926535f / 180.0f;
		float radiansToDegrees = 180.0f / 3.1415926535f;
		float rotationRadians = rotationDegrees * degreesToRadians;

		Vector2D rotatedOffset = {
			endPointOffset.x * cosf(rotationRadians) + endPointOffset.y * sinf(rotationRadians),
			endPointOffset.x * sinf(rotationRadians) - endPointOffset.y * cosf(rotationRadians)
		};
		Vector2D transformedEndPoint = {pos.x + rotatedOffset.x, pos.y + rotatedOffset.y };
		
		SDL_RenderDrawLine(renderer, pos.x, pos.y, transformedEndPoint.x, transformedEndPoint.y);
		
//		int x=200, y=200;
//		SDL_Rect couldabeenasquare = {x, y, 50, 75};
//		SDL_RenderDrawRect(renderer, &couldabeenasquare);

	//	SDL_Point spaceMotherFuckingShip[] = { {transformedEndPoint.x,transformedEndPoint.y}, {transformedEndPoint.x-50, transformedEndPoint.y-50}, {transformedEndPoint.x+50,transformedEndPoint.y-50}, {transformedEndPoint.x, transformedEndPoint.y}};
	//	SDL_RenderDrawLines(renderer, spaceMotherFuckingShip, 4);


//		posY = posY < 640 ? posY + 1 : posY;	//makes a line with the points, because its y++

		SDL_RenderPresent(renderer);			//actually show everything
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
*/
	
	GameEngine *engine = GameEngine::CreateInstance();
	
	engine->Initialize();

	while(true) {
		engine->Update();
		engine->Draw();
	}

	engine->Shutdown();


	return 0;

}