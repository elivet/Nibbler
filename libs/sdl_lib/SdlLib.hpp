/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SdlLib.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:57:14 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:57:16 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_LIB_HPP
# define SDL_LIB_HPP
# include "../../ILib.hpp"
# include <SDL2/SDL.h>

class SdlLib : public ILib
{
public:
	SdlLib( void );
	~SdlLib( void );

	bool		isCloseRequest( void ) const;
	bool		createWindow( int height, int width, std::string title);
	bool		refreshWindow( void );
	bool		destroyWindow( void );
	bool		clearWindow( void );
	void		updateKeys( void );
	bool		isKeyPressed( e_key ) const;
	void		drawSquare( int posX, int posY, int size, int color ) const;
	void		drawLine( float x1, float y1, float x2, float y2, int color ) const;

	static bool			keys[ILib::SIZEOF];
private:
	SDL_Window *	_window;
	SDL_Renderer *	_render;
	SDL_Event		_event;
};

#endif
