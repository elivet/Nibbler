/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:53:48 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:53:51 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NcursesLib.hpp"

std::map<int, int>	NcursesLib::_colors;

NcursesLib::NcursesLib( void )
{
	return ;
}

NcursesLib::~NcursesLib( void )
{
	return ;
}

bool		NcursesLib::isCloseRequest( void ) const
{
	return ( this->_keys[ESC] );
}

bool		NcursesLib::createWindow( int height, int width, std::string title)
{
	this->_title = title;

	initscr();
	start_color();
	cbreak();
	nodelay( stdscr, true );
	keypad( stdscr, true );
	noecho();
	curs_set( 0 );
	this->_window = newwin( height, width, 0, 0 );
	wrefresh(this->_window);
	return ( true );
}

bool		NcursesLib::refreshWindow( void )
{
	wrefresh( this->_window );
	return ( true );
}

bool		NcursesLib::destroyWindow( void )
{
	delwin( this->_window );
	endwin( );
	use_default_colors();
	return ( true );
}

bool		NcursesLib::clearWindow( void )
{
	wclear(this->_window); //seems to be too slow
	clear( );
	return ( true );
}

void		NcursesLib::updateKeys( void )
{
	static int keyLink[][2] =
	{
		{ESC, 27},
		{RIGHT, KEY_RIGHT},
		{LEFT, KEY_LEFT},
		{UP, KEY_UP},
		{DOWN, KEY_DOWN},
		{F1, '1'},
		{F2, '2'},
		{F3, '3'},
		{D, 100},
		{A, 97},
		{W, 119},
		{S, 115}
	};

	int ch;
	ch = getch();
	for (int i = 0; i < SIZEOF; i++)
	{
		this->_keys[i] = (keyLink[i][1] == ch);
	}
}

bool		NcursesLib::isKeyPressed( e_key key ) const
{
	return (this->_keys[key]);
}

void		NcursesLib::drawSquare( int posX, int posY, int size, int color ) const
{
	int		r, g, b;
	int		c;
	std::map<int,int>::const_iterator it;

	if ( (it = NcursesLib::_colors.find( color ) ) == NcursesLib::_colors.end() )
	{
		c = NcursesLib::_colors.size() + 1;
		r = ( (color & 0xFF0000) >> 16 ) * 3.5;
		g = ( (color & 0x00FF00) >> 8 ) * 3.5;
		b = ( (color & 0x0000FF) ) * 3.5;
		init_color( c + 100, r, g, b );
		init_pair( c, c + 100, c + 100 );
		NcursesLib::_colors.insert( std::pair<int,int>( color, c ) );
	}
	else
		c = it->second;
	wattron(this->_window, COLOR_PAIR(c));
	for (int x = 0; x < size; x++)
	{
			for (int y = 0; y < size; y++)
			{
				mvwprintw( this->_window, posY + y, (posX + x) * 2, "  ");
			}
	}
	wattroff(this->_window, COLOR_PAIR(c));
}

void		NcursesLib::drawLine( float x1, float y1, float x2, float y2, int color ) const
{
	(void)color;

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
			this->drawSquare( x, y1, 1, color );
		}
	}
	else
	{
		for (int y = y1; y <= y2; y++)
		{
			this->drawSquare( x1, y, 1, color );
		}
	}

}
