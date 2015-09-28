
#include "Wall.hpp"

Wall::Wall( float x1, float y1, float x2, float y2 )
{
	static int t = 0;

	t++;
	if (t % 2)
	{
		int save = (int)(rand()%(int)(x2-x1 + 1) + x1 + 1);
		setPos( Vec2i( save, (int)(rand()%(int)(y2-y1 + 1) + y1 + 1) ) );
		setPos2( Vec2i( save, (int)(rand()%(int)(y2-y1 + 1) + y1 + 1) ) );
	}
	else
	{
		int save = (int)(rand()%(int)(y2-y1 + 1) + y1 + 1);
		setPos( Vec2i( (int)(rand()%(int)(x2-x1 + 1) + x1 + 1), save ) );
		setPos2( Vec2i( (int)(rand()%(int)(x2-x1 + 1) + x1 + 1), save ) );
	}
	return ;
}

Wall::~Wall( void )
{
	return ;
}

Wall::Wall( Wall const & src )
{
	*this = src;
}

Wall &	Wall::operator=( Wall const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

int			Wall::update( ILib const * lib, double delta )
{
	(void)lib;
	(void)delta;
	return ( true );
}

int			Wall::render( ILib const * lib ) const
{
	lib->drawLine( this->_pos.getX(), this->_pos.getY(), this->_pos2.getX(), this->_pos2.getY(), 0x9933FF );
	return ( true );
}
