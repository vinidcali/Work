/**
 * \class Game
 * \brief Inheriting from GameEngine, represents the game environment.
 * \author Vinícius de Carli
 * \date January 29, 2015
 */

#pragma once

#include "GameEngine.h"

class Game: public GameEngine {

	friend class GameEngine;

protected:
	/**
	* \fn		void Game::Game()
	* \brief	Standard constructor for Game.
	*/
	Game();

	/**
	 * \fn		void Game::InitializeImpl()
	 * \brief	The virtual function inherited from GameEngine. It is used to set initial
	 *			values and run initalizing routines.
	 */
	void InitializeImpl();

	/**
	 * \fn		void Game::UpdateImpl(float dt)
	 * \brief	The virtual function inherited from GameEngine. It is used to update the
	 *			objects in the game while the program is running.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void UpdateImpl(float dt);

	/**
	 * \fn		void Game::DrawImpl(SDL_Renderer *renderer, float dt)
	 * \brief	The virtual function inherited from GameEngine. It is used to define how
	 *			the objects in the game will be draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void DrawImpl(SDL_Renderer *renderer, float dt);


	Player _player;
	Asteroid _asteroid;
	Projectile _projectile;

	Vector2 pos, endPointOffset;
	float speed, rotationSpeed;

};