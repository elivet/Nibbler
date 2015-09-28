/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:49:48 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:49:51 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_ENGINE_HPP
# define CORE_ENGINE_HPP
# include <iostream>
# include <sys/time.h>
# include <unistd.h>
# include "AGame.hpp"

# define SECOND		(1000000.0)

class CoreEngine
{
public:
	CoreEngine( float fps, int lib );
	CoreEngine( CoreEngine const & src );
	~CoreEngine( void );

	CoreEngine &			operator=( CoreEngine const & rhs );

	bool					start( void );
	bool					stop( void );

	/*
	**	GETTER
	*/
	ILib *					getRenderLib( void ) const;

	/*
	**	SETTER
	*/
	void					setrenderLib( ILib * renderLib );
	void					setGame( AGame * game );
	void					setFPS( int fps );
private:
	CoreEngine( void );
	double					getTime( void );
	void					loadLib( std::string lib );
	void					switchLib( void );

	void *					_handle;
	float					_fps;
	ILib *					_renderLib;
	AGame *					_game;
	bool					_isRunning;
	int						_lib;
};

#endif
