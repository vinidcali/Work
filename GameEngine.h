/**
 * \class GameEngine
 * \brief A generic class for creating all the games in the course.
 * \author Vin�cius de Carli
 * \date January 29, 2015
 */

#pragma once				//ensures this header will only be included once (special for Windows)

/*	same as pragma once, but for all environments
#ifndef _GAME_ENGINE_H_
	#define _GAME_ENGINE_H_
#endif // _GAME_ENGINE_H_
*/

#include "MathUtils.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"
#include "Timer.h"


//Forward declarations. Because we are using pointers, the compiler knows the size
struct SDL_Renderer;
struct SDL_Window;

class GameEngine {

public:
	/**
	 * \fn		static GameEngine* GameEngine::CreateInstance()
	 * \brief	A static method to get the single instance of this class.
	 * \return	The single GameEngine instance.
	 */
	static GameEngine* CreateInstance();

	/**
	 * \fn		void GameEngine::Initialize()
	 * \brief	Function used to set initial values and run initalizing routines.
	 */
	void Initialize();

	/**
	 * \fn		void GameEngine::Shutdown()
	 * \brief	Generic function used to clean everything once the game is finished running.
	 */
	void Shutdown();

	/**
	 * \fn		void GameEngine::Update
	 * \brief	Generic function used to update objects while the program is running.
	 */
	void Update();

	/**
	 * \fn		void GameEngine::Draw
	 * \brief	Generic function used to define how the objects are draw to the screen.
	 */
	void Draw();

	/**
	* \fn		void GameEngine::~GameEngine()
	* \brief	Standard deconstructor for GameEngine.
	*/
	~GameEngine();


protected:
	/**
	* \fn		void GameEngine::GameEngine()
	* \brief	Standard constructor for GameEngine.
	*/
	GameEngine();

	/**
	 * \fn		virtual void GameEngine::InitializeImpl() = 0
	 * \brief	The virtual function which will be inherited by other classes and used to
	 *			set initial values and run initalizing routines.
	 */
	virtual void InitializeImpl() = 0;

	/**
	 * \fn		virtual void GameEngine::UpdateImpl(float dt) = 0
	 * \brief	The virtual function which will be inherited by other classes and used to update these
	 *			objects while the program is running.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	virtual void UpdateImpl(float dt) = 0;

	/**
	 * \fn		virtual void GameEngine::DrawImpl(SDL_Renderer *renderer, float dt) = 0
	 * \brief	The virtual function which will be inherited by other classes and used to define how
	 *			these objects will be draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	virtual void DrawImpl(SDL_Renderer *renderer, float dt) = 0;
	

	static GameEngine *_instance;

	SDL_Window *_window;
	SDL_Renderer *_renderer;
	Timer _engineTimer;
	
	float _oldTime, _currentTime, _deltaTime;
};