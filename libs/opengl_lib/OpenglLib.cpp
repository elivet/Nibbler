/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpenglLib.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:55:46 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:55:49 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenglLib.hpp"

bool				OpenglLib::keys[ILib::SIZEOF] = {0};

static void	error_callback( int error, const char * description )
{
	std::cerr << "error[code: "<< error << "]: " << description << std::endl;
}

void		OpenglLib::key_callback( GLFWwindow * window, int key, int scancode, int action, int mods )
{
	(void)scancode;
	(void)mods;
	static int keyLink[][2] =
	{
		{ESC, GLFW_KEY_ESCAPE},
		{RIGHT, GLFW_KEY_RIGHT},
		{LEFT, GLFW_KEY_LEFT},
		{UP, GLFW_KEY_UP},
		{DOWN, GLFW_KEY_DOWN},
		{F1, GLFW_KEY_1},
		{F2, GLFW_KEY_2},
		{F3, GLFW_KEY_3},
		{D, GLFW_KEY_D},
		{A, GLFW_KEY_A},
		{W, GLFW_KEY_W},
		{S, GLFW_KEY_S}
	};

	if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
		glfwSetWindowShouldClose( window, GL_TRUE );
	for (int i = 0; i < SIZEOF; i++)
	{
		if ( key == keyLink[i][1] && action == GLFW_PRESS )
			OpenglLib::keys[i] = true;
		// else if ( key == keyLink[i][1] && action == GLFW_RELEASE )
		// 	OpenglLib::keys[i] = false;
	}
}
OpenglLib::OpenglLib( void )
{
	glfwSetErrorCallback( error_callback );
	if ( ! glfwInit() )
		std::cerr << "error: failed instanciate OpenglLib !" << std::endl;
	return ;
}

OpenglLib::~OpenglLib( void )
{
	return ;
}

bool		OpenglLib::isCloseRequest( void ) const
{
	return ( glfwWindowShouldClose( this->_window ) );
}

bool		OpenglLib::createWindow( int height, int width, std::string title)
{
	this->_window = glfwCreateWindow( height, width, title.c_str(), NULL, NULL );
	if ( ! this->_window )
	{
		std::cerr << "error: glfwCreateWindow" << std::endl;
		glfwTerminate();
		return ( false );
	}
	glClearColor( 0.2f, 0.2f, 0.2f, 1.f );
	glfwMakeContextCurrent( this->_window );
	glfwSwapInterval(1);
	glfwSetKeyCallback( this->_window, OpenglLib::key_callback );
	return ( true );
}

bool		OpenglLib::refreshWindow( void )
{
	glfwSwapBuffers( this->_window );
	return ( true );
}

bool		OpenglLib::destroyWindow( void )
{
	glfwDestroyWindow( this->_window );
	glfwTerminate();
	return ( true );
}

bool		OpenglLib::clearWindow( void )
{
	glClear( GL_COLOR_BUFFER_BIT );
	glClearColor( 0.2f, 0.2f, 0.2f, 1.f );
	return ( true );
}

void		OpenglLib::updateKeys( void )
{
	for (int i = 0; i < SIZEOF; i++)
		OpenglLib::keys[i] = false;
	glfwPollEvents();
	return ;
}

bool		OpenglLib::isKeyPressed( e_key key ) const
{
	return ( OpenglLib::keys[key] );
}

void		OpenglLib::drawSquare( int posX, int posY, int size, int color ) const
{
	(void)size;
	float ratio;
	int width, height;
	float r, g, b;
	r = (float)( (color & 0xFF0000) >> 16 ) / 255.f;
	g = (float)( (color & 0x00FF00) >> 8 ) / 255.f;
	b = (float)( (color & 0x0000FF) ) / 255.f;
	glfwGetFramebufferSize( this->_window, &width, &height );
	ratio = width / (float) height;
	glViewport( 0, 0, width, height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( -ratio, ratio, -1.f, 1.f, 1.f, -1.f );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glBegin( GL_TRIANGLES );
	glColor3f( r, g, b );
	ratio *= 20.0;
	glVertex3f( (-0.f + posX - SCREEN) / ratio, -(-0.f + posY - SCREEN) / ratio, 0.f );
	glVertex3f( (-0.f + posX - SCREEN) / ratio, -(+1.f + posY - SCREEN) / ratio, 0.f );
	glVertex3f( (+1.f + posX - SCREEN) / ratio, -(+1.f + posY - SCREEN) / ratio, 0.f );
	glVertex3f( (-0.f + posX - SCREEN) / ratio, -(-0.f + posY - SCREEN) / ratio, 0.f );
	glVertex3f( (+1.f + posX - SCREEN) / ratio, -(-0.f + posY - SCREEN) / ratio, 0.f );
	glVertex3f( (+1.f + posX - SCREEN) / ratio, -(+1.f + posY - SCREEN) / ratio, 0.f );
	glEnd();
	return ;
}

void		OpenglLib::drawLine( float x1, float y1, float x2, float y2, int color ) const
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
