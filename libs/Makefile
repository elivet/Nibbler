# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elivet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 13:58:27 by elivet            #+#    #+#              #
#    Updated: 2015/03/17 13:58:28 by elivet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -ansi -O3

CC				=	g++

NAME			=	tests

all:
	@printf "\033[31musage: sdl_tests, ncurses_tests, opengl_tests\033[0n\n"

sdl_tests:
	@(cd ./sdl_lib && $(MAKE) re)
	@g++ -DLIB='"./sdl_lib/libsdl.dylib"' tests.cpp -o sdl$(NAME)
	@printf "\n\033[31m_______________________\033[32m \
	MLX TESTS \033[31m_______________________\033[0m\n"
	@./sdl$(NAME)

ncurses_tests:
	@(cd ./ncurses_lib && $(MAKE) re)
	@g++ -lncurses -DLIB='"./ncurses_lib/libncurses.dylib"' tests.cpp -o ncurses$(NAME)
	@printf "\n\033[31m_____________________\033[32m \
	NCURSES TESTS \033[31m_____________________\033[0m\n"
	@./ncurses$(NAME)

opengl_tests:
	@(cd ./opengl_lib && $(MAKE) re)
	@g++ -DLIB='"./opengl_lib/libopengl.dylib"' tests.cpp -o opengl$(NAME)
	@printf "\n\033[31m_____________________\033[32m \
	OPENGL TESTS \033[31m______________________\033[0m\n"
	@./opengl$(NAME)

all_tests: sdl_tests ncurses_tests opengl_tests

