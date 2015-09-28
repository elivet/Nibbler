/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elivet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 13:52:56 by elivet            #+#    #+#             */
/*   Updated: 2015/03/17 13:52:59 by elivet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/CoreEngine.hpp"
#include "game/Nibbler.hpp"

int checkParams(int ac, char const *av[])
{
	int x;
	int y;
	if (ac == 3 || ac == 4)
	{
		x = atoi(av[1]);
		y = atoi(av[2]);
		if (x <= 60 && y <= 60 && x > 14 && y > 14)
		{
			return 1;
		}
	}
	printf("Game Size must be betwwen x/y 15 and x/y 60\n");
	return 0;
}

int		main(int argc, char const *argv[])
{
	CoreEngine *	core;
	Nibbler *		nibbler;

	srand(time(NULL));
	if (!checkParams(argc, argv))
		return 0;

	core = new CoreEngine( 8, 1 );
	if (argc == 4)
		nibbler = new Nibbler( atoi(argv[1]), atoi(argv[2]), 1 );
	else
		nibbler = new Nibbler( atoi(argv[1]), atoi(argv[2]), 0 );

	core->setGame( nibbler );
	core->start();
	return ( 0 );
}
