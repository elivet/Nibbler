#include "Labyrinthe.hpp"

Labyrinthe::Labyrinthe( float width, float height, int nbr ) :
	_width( width ), _height( height ), _nbr( nbr )
{
	return ;
}

Labyrinthe::~Labyrinthe( void )
{
	return ;
}

Labyrinthe::Labyrinthe( Labyrinthe const & src ): GameObject( )
{
	*this = src;
}

Labyrinthe &	Labyrinthe::operator=( Labyrinthe const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void	Labyrinthe::init( void )
{
	for ( int i = 0; i < this->_nbr; i++ )
	{
		for ( int j = 0; j < this->_nbr; j++ )
			addComponent( new Wall( ((this->_width / this->_nbr) * i), ((this->_height / this->_nbr) * j), ((this->_width / this->_nbr) * i + 1), ((this->_height / this->_nbr) * j + 1) ) );
	}
}

void	Labyrinthe::addWalls( int nbr )
{
	this->_nbr += nbr;
	for ( int i = 0; i < this->_nbr; i++ )
	{
		for ( int j = 0; j < this->_nbr; j++ )
			addComponent( new Wall( ((this->_width / this->_nbr) * i), ((this->_height / this->_nbr) * j), ((this->_width / this->_nbr) * i + 1), ((this->_height / this->_nbr) * j + 1) ) );
	}
}
