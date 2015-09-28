
#ifndef SNAKE_HPP
# define SNAKE_HPP
# include "../../core/GameObject.hpp"
# include "../components/SnakePart.hpp"
# include <cstdlib>

# define SECOND		(1000000.0)


class Snake : public GameObject
{
public:
	// Snake( void );
	Snake( int posX, int posY, size_t nbPart );
	~Snake( void );
	Snake( Snake const & src );

	Snake &						operator=( Snake const & rhs );

	virtual int					update( ILib const * lib, double delta );
	virtual void				init( void );
	void						grow( void );
	bool						getInvincible( void );
	void						setInvincible( bool );
	double						getTime( void );
	void						setColour( int c );
	int 						getPoints( void );
	void						setNewControls( int );
	void						setBasicColor( int );
	int							getBasicColor( void );
	void						setPowerColor( int );
	int							getPowerColor( void );
	void						setHeadColor( int );
	int							getHeadColor( void );

private:
	Vec2i						_pos;
	Vec2i						_dir;
	size_t						_nbPart;
	bool						_invincible;
	double						_startFrame;
	double						_endFrame;
	double						_dt;
	int							_points;
	int							_setNewControls;
	int							_basicColor;
	int							_powerColor;
	int							_headColor;
};

#endif
