/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AGame.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:49:16 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:49:21 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_GAME_HPP
# define A_GAME_HPP
# include <vector>
# include <iostream>

# include "../../ILib.hpp"

class CoreEngine;
class GameObject;
class AGame
{
public:
	virtual ~AGame( void ) {};

	virtual int					init( void ) = 0;
	virtual int					addObject( GameObject * object );
	virtual int					update( ILib const * lib, double delta );
	virtual int					render( ILib const * lib ) const;
	virtual int					isRunnig( void );
	virtual int					setRunnig( int state );
	void						setCore( CoreEngine *core );
	CoreEngine*					getCore( void );
	virtual int					getPoints( void );
	virtual int					getPoints2( void );
	virtual int					getLevel( void );

protected:
	int							_isRunning;
	std::vector<GameObject *>	_objects;
	CoreEngine*					_core;
	int 						_points;
	int 						_level;
};

#endif
