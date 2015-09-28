/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CoreEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:49:33 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:49:36 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <dlfcn.h>
#include "CoreEngine.hpp"

CoreEngine::CoreEngine( float fps, int lib ) :
	_fps( fps ),
	_game( NULL ),
	_isRunning( false ),
	_lib( lib )
{
	loadLib( "./libs/ncurses_lib/libncurses.dylib" );
	return ;
}

CoreEngine::CoreEngine( CoreEngine const & src )
{
	*this = src;
	return ;
}

CoreEngine::~CoreEngine( void )
{
	return ;
}

CoreEngine &	CoreEngine::operator=( CoreEngine const & rhs )
{
	if ( this != &rhs )
	{
		this->_renderLib = rhs.getRenderLib();
	}
	return ( * this );
}

double			CoreEngine::getTime( void )
{
	struct timeval		tv;

	gettimeofday( &tv, NULL );
	return ( tv.tv_sec + (double)tv.tv_usec / SECOND );
}

void			CoreEngine::loadLib( std::string lib )
{
	char *			err;
	ILib *			(*f)( void );

	this->_handle = dlopen( lib.c_str(), RTLD_LAZY | RTLD_LOCAL );
	if ( (err = dlerror()) != NULL )
	{
		std::cerr << err << std::endl;
		exit( 0 );
		return ;
	}
	f = ( ILib *(*)() ) dlsym( this->_handle, "getInstance" );
	if ( (err = dlerror()) != NULL )
	{
		std::cerr << err << std::endl;
		return ;
	}
	this->_renderLib = f();
}

void			CoreEngine::switchLib( void )
{
	std::string lib;

	if ( this->_lib != 1 && this->_renderLib->isKeyPressed( ILib::F1 ) )
	{
		lib = "./libs/ncurses_lib/libncurses.dylib";
		this->_lib = 1;
	}
	else if ( this->_lib != 2 && this->_renderLib->isKeyPressed( ILib::F2 ) )
	{
		lib = "./libs/opengl_lib/libopengl.dylib";
		this->_lib = 2;
	}
	else if ( this->_lib != 3 && this->_renderLib->isKeyPressed( ILib::F3 ) )
	{
		lib = "./libs/sdl_lib/libsdl.dylib";
		this->_lib = 3;
	}
	else
		return ;
	this->_renderLib->destroyWindow();
	dlclose( this->_handle );
	loadLib( lib );

	if ( ! this->_renderLib->createWindow( 850, 550, "Test" ) )
	{
		std::cerr << "Failed to create window !" << std::endl;
		return ;
	}
	this->_renderLib->updateKeys();

	return ;
}

bool			CoreEngine::start( void )
{
	double		startFrame;
	double		endFrame;
	double		dt;
	int			sleep;

	if ( this->_isRunning == true )
	{
		std::cerr << "CoreEngine alrady running !" << std::endl;
		return ( false );
	}
	if ( this->_game == NULL )
	{
		std::cerr << "CoreEngine need a game !" << std::endl;
		return ( false );
	}
	if ( ! this->_renderLib->createWindow( 850, 550, "Test" ) )
	{
		std::cerr << "Failed to create window !" << std::endl;
		return ( false );
	}
	dt = 1 / this->_fps;
	this->_isRunning = true;
	this->_game->init();
	while ( this->_isRunning && this->_game->isRunnig())
	{
		startFrame = this->getTime();
		this->_renderLib->updateKeys();
		this->switchLib();
		this->_renderLib->clearWindow();
		if ( this->_renderLib->isCloseRequest())
		{
			this->stop();
			break ;
		}

		this->_game->update( this->_renderLib, dt );
		this->_game->render( this->_renderLib );

		this->_renderLib->refreshWindow();

		endFrame = this->getTime();
		dt = (endFrame - startFrame);
		sleep = (SECOND / this->_fps) - (dt * SECOND);
		if ( sleep > 0 )
			usleep( sleep );
		else
			usleep( 1 );
	}
	this->stop();
	if (this->_game->getPoints2() == -1)
		printf("***!! GAME OVER !!*** \n  SCORE: %d \n  LEVEL: %d\n", this->_game->getPoints(), this->_game->getLevel());
	else if (this->_game->getPoints2() != -1)
	{
		printf("***!! GAME OVER !!*** \n   LEVEL: %d\n", this->_game->getLevel());
		printf("// PLAYER1 // \n   SCORE: %d \n", this->_game->getPoints());
		printf("// PLAYER2 // \n   SCORE: %d \n", this->_game->getPoints2());
	}
	return ( true );
}

bool			CoreEngine::stop( void )
{
	if ( ! this->_isRunning )
		return ( false );
	this->_renderLib->destroyWindow();
	this->_isRunning = false;
	return ( true );
}

/*
**	GETTER
*/
ILib *			CoreEngine::getRenderLib( void ) const
{
	return ( this->_renderLib );
}

/*
**	SETTER
*/
void			CoreEngine::setrenderLib( ILib * renderLib )
{
	this->_renderLib = renderLib;
	return ;
}

void			CoreEngine::setFPS( int fps )
{
	this->_fps = fps;
}

void			CoreEngine::setGame( AGame * game )
{
	this->_game = game;
	this->_game->setCore(this);
	return ;
}
