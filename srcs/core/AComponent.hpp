/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AComponent.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:48:34 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:48:40 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_COMPONENT_HPP
# define A_COMPONENT_HPP
# include "../../ILib.hpp"
# include "../utils/vec.hpp"
class GameObject;

class AComponent
{
public:
	virtual int					update( ILib const * lib, double delta ) = 0;
	virtual int					render( ILib const * lib ) const = 0;

	/*
	**	SETTER
	*/

	void						setPos(Vec2i pos);
	Vec2i						getPos(void);
	void						setPos2(Vec2i pos2);
	Vec2i						getPos2(void);
	
protected:
	Vec2i 			_pos;
	Vec2i 			_pos2;

};

#endif
