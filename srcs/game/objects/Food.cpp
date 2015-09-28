#include "Food.hpp"

Food::Food( int nbr ) :
	_nbr( nbr )
{
	return ;
}

Food::~Food( void )
{
	return ;
}

Food::Food( Food const & src ): GameObject( )
{
	*this = src;
}

Food &	Food::operator=( Food const & rhs )
{
	if ( this != &rhs )
	{

	}
	return ( *this );
}

void		Food::init( void )
{
	for ( size_t i = 0; i < this->_nbr; i++ )
	{
		addComponent( new FoodElement( Vec2i( rand() % 10 , rand() % 10 ) ) );
	}
	addComponent( new PotionElement( Vec2i( -1 , -1 ) ) );
}
