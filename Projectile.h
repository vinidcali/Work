/**
 * \class Projectile
 * \brief Inheriting from GameObject, represents the projectiles (shot by the Player) in the game.
 * \author Vinícius de Carli
 * \date January 29, 2015
 */

#pragma once

#include "GameObject.h"


class Projectile : public GameObject {

public:
	/**
	 * \fn		void Projectile::Initialize()
	 * \brief	Function inherited from GameObject. It is used to set initial values and run initalizing routines
	 *			before the object is used elsewhere.
	 */
	void Initialize();

	/**
	 * \fn		void Projectile::Update(float dt)
	 * \brief	Function inherited from GameObject. It is used to update the object in every new game loop.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Update(float dt);

	/**
	 * \fn		void Projectile::Draw(SDL_Renderer *renderer, float dt)
	 * \brief	Function inherited from GameObject. It defines how the object is draw to the screen.
	 * \param	renderer	The SDL renderer used to draw the object.
	 * \param	dt			The time in fractions of a second since the last pass.
	 */
	void Draw(SDL_Renderer *renderer, float dt);

	/**
	* \fn		void Projectile::Projectile()
	* \brief	Standard constructor for Projectile.
	*/
	Projectile();

	/**
	* \fn		void Projectile::~Projectile()
	* \brief	Standard deconstructor for Projectile.
	*/
	~Projectile();

	/**
	 * \fn		void Projectile::setPlayerPos(float x, float y)
	 * \brief	Configures the player location, so that the projectiles are originated from that place.
	 * \param	x			Value of player's x-axis.
	 * \param	y			Value of player's y-axis.
	 */
	void setPlayerPos(float x, float y);

};