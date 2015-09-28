
#include "LimitSide.hpp"

LimitSide::LimitSide( Vec2i const & a, Vec2i const & b )
{
	setPos( a );
	setPos2( b );
	return ;
}

LimitSide::~LimitSide( void )
{
	return ;
}

LimitSide::LimitSide( LimitSide const & src )
{
	*this = src;
}

LimitSide &	LimitSide::operator=( LimitSide const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

int			LimitSide::update( ILib const * lib, double delta )
{
	(void)lib;
	(void)delta;
	return ( true );
}

int			LimitSide::render( ILib const * lib ) const
{
	lib->drawLine( this->_pos.getX(), this->_pos.getY(), this->_pos2.getX(), this->_pos2.getY(), 0xFFFF00 );
	return ( true );
}
