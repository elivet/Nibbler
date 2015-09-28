/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:56:00 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:56:02 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPENGL_LIB_HPP
# define OPENGL_LIB_HPP
# include "../../ILib.hpp"
# include <GLFW/glfw3.h>

# define SCREEN 30

class OpenglLib : public ILib
{
public:
	OpenglLib( void );
	~OpenglLib( void );

	bool		isCloseRequest( void );

	virtual bool		isCloseRequest( void ) const;
	virtual bool		createWindow( int height, int width, std::string title);
	virtual bool		refreshWindow( void );
	virtual bool		destroyWindow( void );
	virtual bool		clearWindow( void );
	virtual void		updateKeys( void );
	virtual	bool		isKeyPressed( e_key ) const;
	virtual void		drawSquare( int posX, int posY, int size, int color ) const;
	virtual void		drawLine( float x1, float y1, float x2, float y2, int color ) const;

	static void			key_callback( GLFWwindow * window, int key, int scancode, int action, int mods );
	static bool			keys[ILib::SIZEOF];
private:
	GLFWwindow *		_window;
};

#endif
