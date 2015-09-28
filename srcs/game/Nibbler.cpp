/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:50:44 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:50:47 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../core/CoreEngine.hpp"
#include "Nibbler.hpp"

Nibbler::Nibbler( int sizex, int sizey, int otherPlayer ):
_width( sizex ), _height( sizey ), _level(0), _hasOtherPlayer( otherPlayer )
{
	return ;
}

Nibbler::~Nibbler( void )
{
	return ;
}

Nibbler::Nibbler( Nibbler const & src )
{
	*this = src;
}

Nibbler &	Nibbler::operator=( Nibbler const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

int				Nibbler::init( void )
{
	_limit = new Limit( _width, _height );
	_labyrinthe = new Labyrinthe( _width, _height, 0 );
	_food = new Food(5);
	_snake = new Snake( 10, 10, 5 );
	if (_hasOtherPlayer)
	{
		_snake2 = new Snake( 6, 6, 5 );
		_snake2->setNewControls(1);
		_snake2->setBasicColor( 0xCC00CC);
		_snake2->setHeadColor(0x99CC00);
	}
	else
	{
		_snake2 = NULL;	
	}
	addObject( _limit );
	addObject( _labyrinthe );
	addObject( _food );
	addObject( _snake );
	if (_hasOtherPlayer)
		addObject( _snake2 );

	//we pop food so it dosent collide with anything
	std::vector<AComponent *> foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		popFood(i, foodElements );
	}

	_isRunning = true;

	return ( true );
}

int				Nibbler::getWidth( void )
{
	return this->_width;
}

int				Nibbler::getHeight( void )
{
	return this->_height;
}

int			Nibbler::update( ILib const * lib, double delta )
{
	AGame::update(lib, delta);
	if (!_snake->getInvincible() && (this->checkBasicCollision(_snake->getComponents()[0])
		|| this->checkWallCollision(_snake->getComponents()[0]) ))
		this->setRunnig(false);
	if (_snake->getInvincible() && this->checkBasicCollision(_snake->getComponents()[0]))
		this->setRunnig(false);
	this->checkFoodCollision(_snake->getComponents()[0], _snake);

	if (_snake2 != NULL)
	{
		if (!_snake2->getInvincible() && (this->checkBasicCollision(_snake2->getComponents()[0])
			|| this->checkWallCollision(_snake2->getComponents()[0]) ))
			this->setRunnig(false);
		if (_snake2->getInvincible() && this->checkBasicCollision(_snake2->getComponents()[0]))
			this->setRunnig(false);
		this->checkFoodCollision(_snake2->getComponents()[0], _snake2);
	}

	this->checkLevel();
	return ( true );
}

void	Nibbler::checkLevel( void )
{
	if (this->_snake->getPoints() > 5 && this->_level == 0)
	{
		this->_level++;
		this->_labyrinthe->addWalls(3);
		this->getCore()->setFPS( 10 );
	}
	if (this->_snake->getPoints() > 10 && this->_level == 1)
	{
		this->_level++;
		this->_labyrinthe->addWalls(2);	
		this->getCore()->setFPS( 11 );
	}
	if (this->_snake->getPoints() > 15 && this->_level == 2)
	{
		this->_level++;
		this->_labyrinthe->addWalls(1);
		this->getCore()->setFPS( 8 );
	}
	if (this->_snake->getPoints() > 20 && this->_level == 3)
	{
		this->_level++;
		this->_labyrinthe->addWalls(1);
		this->getCore()->setFPS( 6 );
	}
	return ;
}

int			Nibbler::checkFoodCollision( AComponent *element, Snake* snake )
{
	std::vector<AComponent *> foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		if ( foodElements[i]->getPos() == element->getPos() && i == ((int)foodElements.size() - 1))
		{
			snake->setInvincible(true);
			popFood(i, foodElements );
			snake->setColour( snake->getPowerColor() );
			return true;
		}
		if ( foodElements[i]->getPos() == element->getPos())
		{
			snake->grow();
			popFood(i, foodElements );
						// snake->setColour( snake->getPowerColor() );

			return true;
		}
	}
	return false;
}

int			Nibbler::checkFoodCollision( AComponent *element, int j )
{
	std::vector<AComponent *> foodElements = _food->getComponents();
	for (int i = 0;  i < (int)foodElements.size() ; i++)
	{
		if ( foodElements[i]->getPos() == element->getPos() && j != i)
		{
			// _snake->grow();
			popFood(i, foodElements );
			return true;
		}
	}
	return false;
}

void		Nibbler::popFood( int i, std::vector<AComponent *> foodElements )
{
	int x = (rand() % (this->getWidth() - 1)+ 1);
	int y = (rand() % (this->getHeight() - 1) ) + 1;

	_food->getComponents()[i]->setPos(Vec2i( x,  y));
	if (checkBasicCollision(_food->getComponents()[i]) || checkWallCollision(_food->getComponents()[i]) || checkFoodCollision(_food->getComponents()[i], i))
		popFood(i, foodElements);
	return ;
}

int			Nibbler::checkBasicCollision( AComponent *element )
{

	std::vector<AComponent *> snake = _snake->getComponents();
	for (int k = 1;  k < (int)snake.size() ; k++)
	{

		if ( element->getPos() == snake[k]->getPos())
			return true;
		if ( _width <= snake[k]->getPos().getX() || _height <= snake[k]->getPos().getY()
				|| 0 >= snake[k]->getPos().getX() || 0 >= snake[k]->getPos().getY())
			return true;
	}
	if (_snake2 != NULL)
	{
		std::vector<AComponent *> snake = _snake2->getComponents();
		for (int k = 1;  k < (int)snake.size() ; k++)
		{

			if ( element->getPos() == snake[k]->getPos())
				return true;
			if ( _width <= snake[k]->getPos().getX() || _height <= snake[k]->getPos().getY()
					|| 0 >= snake[k]->getPos().getX() || 0 >= snake[k]->getPos().getY())
				return true;
		}
	}
	return false;
}

int			Nibbler::checkWallCollision( AComponent *element )
{
	// std::vector<AComponent *> snake = _snake->getComponents();
	std::vector<AComponent *> walls = _labyrinthe->getComponents();
	for (int m = 1;  m < (int)walls.size() ; m++)
	{
		if ( element->getPos().getX() == walls[m]->getPos().getX() && walls[m]->getPos().getX() == walls[m]->getPos2().getX())
		{
			if (walls[m]->getPos().getY() > walls[m]->getPos2().getY())
			{
				if (element->getPos().getY() <= walls[m]->getPos().getY() && element->getPos().getY() >= walls[m]->getPos2().getY())
					return true;
			}
			else
			{
				if (element->getPos().getY() >= walls[m]->getPos().getY() && element->getPos().getY() <= walls[m]->getPos2().getY())
					return true;
			}
		}
		else if ( element->getPos().getY() == walls[m]->getPos().getY() && walls[m]->getPos().getY() == walls[m]->getPos2().getY() )
		{
			if (walls[m]->getPos().getX() > walls[m]->getPos2().getX())
			{
				if (element->getPos().getX() <= walls[m]->getPos().getX() && element->getPos().getX() >= walls[m]->getPos2().getX())
					return true;
			}
			else
			{
				if (element->getPos().getX() >= walls[m]->getPos().getX() && element->getPos().getX() <= walls[m]->getPos2().getX())
					return true;
			}
		}
	}
	return false;
}

int			Nibbler::getPoints( void )
{
	return _snake->getPoints();
}

int			Nibbler::getPoints2( void )
{
	if (_snake2)
		return _snake2->getPoints();
	return -1;
}

int			Nibbler::getLevel( void )
{
	return _level;
}
