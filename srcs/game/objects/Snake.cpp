
#include "Snake.hpp"
#include "../Nibbler.hpp"
#include <stdlib.h>
#include <stdio.h>

Snake::Snake( int posX, int posY, size_t nbPart) :
	_pos( posX, posY ),
	_nbPart( nbPart ),
	_invincible( false ),
	_points( 0 ),
	_setNewControls(0),
	_basicColor( 0x99CC00 ),
	_powerColor( 0xFFFFFF ), 
	_headColor( 0xCC00CC )
{
	return ;
}

Snake::~Snake( void )
{
	return ;
}

Snake::Snake( Snake const & src ): GameObject( )
{
	*this = src;
}

Snake &	Snake::operator=( Snake const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

int			Snake::update( ILib const * lib, double delta )
{
	static ILib::e_key keys[][4] = {
		{ILib::DOWN, ILib::UP, ILib::LEFT, ILib::RIGHT},
		{ILib::S, ILib::W, ILib::A, ILib::D}
	};

	if (lib->isKeyPressed(keys[_setNewControls][0]) && this->_dir != Vec2i(0, -1))
		this->_dir = Vec2i(0, 1);
	else if (lib->isKeyPressed(keys[_setNewControls][1]) && this->_dir != Vec2i(0, 1))
		this->_dir = Vec2i(0, -1);
	else if (lib->isKeyPressed(keys[_setNewControls][2]) && this->_dir != Vec2i(1, 0))
		this->_dir = Vec2i(-1, 0);
	else if (lib->isKeyPressed(keys[_setNewControls][3]) && this->_dir != Vec2i(-1, 0))
		this->_dir = Vec2i(1, 0);

	for ( size_t i = this->_components.size() - 1; i > 0; i-- )
		this->_components[i]->update( lib, delta );
	this->_components[0]->setPos(this->_components[0]->getPos() + this->_dir);
	return ( true );
}

void						Snake::init( void )
{
	addComponent( new SnakePart( Vec2i( this->_pos.getX(), this->_pos.getY() ), 1, NULL, _headColor ) );
	for ( size_t i = 1; i < this->_nbPart; i++ )
	{
		addComponent( new SnakePart( Vec2i( this->_pos.getX() - i, this->_pos.getY() ), 1, static_cast<SnakePart*>(getComponents()[i - 1] ), _basicColor) );
	}
	this->_dir = Vec2i(0, 1);
}


void		Snake::grow( void )
{
	SnakePart *parent = static_cast<SnakePart*>(this->getComponents()[this->getComponents().size() - 1]);
	addComponent( new SnakePart( parent->getPos() , 1, static_cast<SnakePart*>(parent), _basicColor ) );
	this->_nbPart++;
	if (this->_invincible)
		setColour( _powerColor );
	_points++;
}

bool						Snake::getInvincible( void )
{
	this->_endFrame = this->getTime();
	this->_dt = (this->_endFrame - this->_startFrame);
	if (this->_dt >= 5)
	{
		this->_invincible = false;
		setColour( _basicColor );
	}
	return _invincible;
}

void						Snake::setInvincible( bool a )
{
	this->_startFrame = getTime();
	this->_invincible = a;
	return ;
}

double						Snake::getTime( void )
{
	struct timeval		tv;

	gettimeofday( &tv, NULL );
	return ( tv.tv_sec + (double)tv.tv_usec / SECOND );
}


void						Snake::setColour( int c )
{
	for (int i = 1; i < (int)this->getComponents().size(); i++)
		static_cast<SnakePart*>(this->getComponents()[i])->setColour(c);
	return ;
}

int 						Snake::getPoints( void )
{
	return this->_points;
}

void						Snake::setNewControls( int isNewControl )
{
	_setNewControls = isNewControl;
}

void						Snake::setBasicColor( int c )
{
	_basicColor = c;
}
int							Snake::getBasicColor( void )
{
	return _basicColor;
}
void						Snake::setPowerColor( int c )
{
	_powerColor = c;
}
int							Snake::getPowerColor( void )
{
	return _powerColor;
}

void						Snake::setHeadColor( int c )
{
	_headColor = c;
}
int							Snake::getHeadColor( void )
{
	return _headColor;
}












