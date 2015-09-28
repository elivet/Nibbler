#ifndef POTIONELEMENT_HPP
# define POTIONELEMENT_HPP
# include "../../core/AComponent.hpp"
# include "../../utils/vec.hpp"
# include <sys/time.h>

# define SECOND		(1000000.0)


class PotionElement : public AComponent
{
public:
	// PotionElement( void );
	PotionElement( Vec2i const & pos);
	PotionElement( void );
	~PotionElement( void );
	PotionElement( PotionElement const & src );

	PotionElement &				operator=( PotionElement const & rhs );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;
	double						getTime( void );

private:
	double		_startFrame;
	double		_endFrame;
	double		_dt;
	Vec2i		_savePos;
};

#endif
