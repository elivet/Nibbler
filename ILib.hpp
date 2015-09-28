/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ILib.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:58:58 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:59:00 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef I_LIB_HPP
# define I_LIB_HPP
# include <iostream>
# include "srcs/utils/vec.hpp"

class ILib
{
public:

	enum e_key
	{
		ESC,
		RIGHT,
		LEFT,
		UP,
		DOWN,
		F1,
		F2,
		F3,
		D,
		A,
		W,
		S,
		SIZEOF
	};

	virtual bool		isCloseRequest( void ) const = 0;
	virtual bool		createWindow( int height, int width, std::string title) = 0;
	virtual bool		refreshWindow( void ) = 0;
	virtual bool		destroyWindow( void ) = 0;
	virtual bool		clearWindow( void ) = 0;
	virtual void		updateKeys( void ) = 0;
	virtual	bool		isKeyPressed( e_key ) const = 0;
	virtual void		drawSquare( int posX, int posY, int size, int color ) const = 0;
	virtual void		drawLine( float x1, float y1, float x2, float y2, int color ) const = 0;
};

#endif
