/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SdlLib.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:57:02 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:57:04 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SdlLib.hpp"

bool				SdlLib::keys[ILib::SIZEOF] = {0};

SdlLib::SdlLib( void )
{
	SDL_Init( SDL_INIT_EVERYTHING );
	return ;
}

SdlLib::~SdlLib( void )
{
	return ;
}

bool		SdlLib::isCloseRequest( void ) const
{
	return ( this->_event.type == SDL_QUIT || ( this->_event.key.keysym.sym == SDLK_ESCAPE && this->_event.type == SDL_KEYDOWN ) );
}

bool		SdlLib::createWindow( int height, int width, std::string title)
{
	this->_window = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_OPENGL );
	if ( this->_window == NULL )
	{
		std::cerr << "error: SDL_CreateWindow" << std::endl;
		return ( false );
	}
	this->_render = SDL_CreateRenderer( this->_window, -1, SDL_RENDERER_ACCELERATED );
	SDL_Delay( 1 );
	return ( true );
}

bool		SdlLib::refreshWindow( void )
{
	SDL_RenderPresent( this->_render );
	return (false);
}

bool		SdlLib::destroyWindow( void )
{
	SDL_DestroyWindow( this->_window );
	SDL_Quit();
	return (false);
}

bool		SdlLib::clearWindow( void )
{
	SDL_SetRenderDrawColor( this->_render, 0x33, 0x33, 0x33, 0xFF );
	SDL_RenderClear( this->_render );
	return (false);
}

void		SdlLib::updateKeys( void )
{
	static int keyLink[][2] =
	{
		{ESC, SDLK_ESCAPE},
		{RIGHT, SDLK_RIGHT},
		{LEFT, SDLK_LEFT},
		{UP, SDLK_UP},
		{DOWN, SDLK_DOWN},
		{F1, SDLK_1},
		{F2, SDLK_2},
		{F3, SDLK_3},
		{D, SDLK_d},
		{A, SDLK_a},
		{W, SDLK_w},
		{S, SDLK_s}
	};

	for (int i = 0; i < SIZEOF; i++)
		SdlLib::keys[i] = false;
	while ( SDL_PollEvent( &this->_event ) )
	{
		for (int i = 0; i < SIZEOF; i++)
		{
			if ( this->_event.key.keysym.sym == keyLink[i][1] && this->_event.type == SDL_KEYDOWN )
				SdlLib::keys[i] = true;
		}
	}
	return ;
}

bool		SdlLib::isKeyPressed( e_key key ) const
{
	return (SdlLib::keys[key]);
}

#define SIZE 9

void		SdlLib::drawSquare( int posX, int posY, int size, int color ) const
{
	int r, g, b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0x00FF00) >> 8;
	b = (color & 0x0000FF);
	SDL_Rect fillRect = { posX * SIZE, posY * SIZE, size * SIZE, size * SIZE };
	SDL_SetRenderDrawColor( this->_render, r, g, b, 0xFF );
	SDL_RenderFillRect( this->_render, &fillRect );
	return ;
}

void		SdlLib::drawLine( float x1, float y1, float x2, float y2, int color ) const
{
	float tmp;

	if (x2 < x1)
	{
		tmp = x2;
		x2 = x1;
		x1 = tmp;
	}
	if (y2 < y1)
	{
		tmp = y2;
		y2 = y1;
		y1 = tmp;
	}
	if (y1 == y2)
	{
		for (int x = x1; x <= x2; x++)
		{
			this->drawSquare(x, y1, 1, color);
		}
	}
	else
	{
		for (int y = y1; y <= y2; y++)
		{
			this->drawSquare(x1, y, 1, color);
		}
	}
	return ;
}
