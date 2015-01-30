/**
 * \class Asteroid
 * \brief Inheriting from GameObject, represents the asteroids in the game.
 * \author Vinícius de Carli
 * \date January 29, 2015
 */

#pragma once

#include "GameObject.h"


class Asteroid : public GameObject {

public:
	/**
	 * \fn		void Asteroid::Initialize()
	 * \brief	Function inherited from GameObject. It is used to set initial values and run initalizing routines
	 *			before the object is used elsewhere.
	 */
	void Initialize();

	/**
	 * \fn		void Asteroid::Update(float dt)
	 * \brief	Function inherited from GameObject. It is used to update the object in every new game loop.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Update(float dt);

	/**
	 * \fn		void Asteroid::Draw(SDL_Renderer *renderer, float dt)
	 * \brief	Function inherited from GameObject. It defines how the object is draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Draw(SDL_Renderer *renderer, float dt);

	/**
	* \fn		void Asteroid::Asteroid()
	* \brief	Standard constructor for Asteroid.
	*/
	Asteroid();


protected:
	/**
	* \fn		void Asteroid::~Asteroid()
	* \brief	Standard deconstructor for Asteroid.
	*/
	~Asteroid();

};