#include "Limit.hpp"
#include <cstdlib>

Limit::Limit( float width, float height ) :
	_width( width ), _height( height )
{

	return ;
}

Limit::~Limit( void )
{
	return ;
}

Limit::Limit( Limit const & src ): GameObject( )
{
	*this = src;
}

Limit &	Limit::operator=( Limit const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void			Limit::init( void )
{
	addComponent( new LimitSide( Vec2i(0, 0), Vec2i(this->_width, 0) ) );
	addComponent( new LimitSide( Vec2i(this->_width, 0), Vec2i(this->_width, this->_height) ) );
	addComponent( new LimitSide( Vec2i(this->_width, this->_height), Vec2i(0, this->_height) ) );
	addComponent( new LimitSide( Vec2i(0, this->_height), Vec2i(0, 0) ) );
}
