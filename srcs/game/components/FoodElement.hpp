#ifndef FOODELEMENT_PART_HPP
# define FOODELEMENT_PART_HPP
# include "../../core/AComponent.hpp"
# include "../../utils/vec.hpp"

class FoodElement : public AComponent
{
public:
	// FoodElement( void );
	FoodElement( Vec2i const & pos);
	~FoodElement( void );
	FoodElement( FoodElement const & src );

	FoodElement &				operator=( FoodElement const & rhs );

	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;
};

#endif
