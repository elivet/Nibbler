#ifndef LIMIT_HPP
# define LIMIT_HPP
# include "../../core/GameObject.hpp"
# include "../components/LimitSide.hpp"

class Limit : public GameObject
{
public:
	// Limit( void );
	Limit( float width, float height );
	~Limit( void );
	Limit( Limit const & src );

	Limit &						operator=( Limit const & rhs );

	virtual void				init( void );

private:
	float						_width;
	float						_height;
};

#endif
