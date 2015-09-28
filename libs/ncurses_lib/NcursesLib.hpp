/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NcursesLib.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:54:02 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:54:04 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_LIB_HPP
# define NCURSES_LIB_HPP
# include <ncurses.h>
# include <vector>
# include <map>
# include "../../ILib.hpp"
# include "../../srcs/utils/vec.hpp"

# define COLOR_SQUARE (1000)

class NcursesLib : public ILib
{
public:
	NcursesLib( void );
	~NcursesLib( void );

	bool				isCloseRequest( void ) const;
	bool				createWindow( int height, int width, std::string title );
	bool				refreshWindow( void );
	bool				destroyWindow( void );
	bool				clearWindow( void );
	bool				isKeyPressed( e_key ) const;
	void				updateKeys( void );
	void				drawSquare( int posX, int posY, int size, int color ) const;
	void				drawLine( float x1, float y1, float x2, float y2, int color ) const;

	static std::map<int, int>	_colors;
private:
	std::string 		_title;
	WINDOW*				_window;
	bool				_keys[SIZEOF];

};

#endif
