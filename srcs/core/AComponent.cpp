/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AComponent.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:47:51 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:47:59 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AComponent.hpp"


void		AComponent::setPos( Vec2i pos )
{
	this->_pos = pos;
	return ;
}

Vec2i		AComponent::getPos(void)
{
	return this->_pos;
}

void		AComponent::setPos2( Vec2i pos2 )
{
	this->_pos2 = pos2;
	return ;
}

Vec2i		AComponent::getPos2(void)
{
	return this->_pos2;
}
