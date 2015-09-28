# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elivet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 13:58:42 by elivet            #+#    #+#              #
#    Updated: 2015/03/17 13:58:44 by elivet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#DEV, BUID
MODE			=	BUILD

ifeq ($(MODE), DEV)
	CPPFLAGS	=	-Wall -Wextra -ansi -O3 -DDEBUG
else
	CPPFLAGS	=	-Wall -Wextra -Werror -ansi -O3
endif

CC				=	g++

NAME			=	nibbler

SRCS_DIR		=	srcs

FILES			=	$(NAME).cpp						\
					core/CoreEngine.cpp				\
					core/GameObject.cpp				\
					core/AGame.cpp					\
					core/AComponent.cpp				\
					\
					game/Nibbler.cpp				\
					game/components/SnakePart.cpp	\
					game/objects/Snake.cpp			\
					game/components/FoodElement.cpp	\
					game/components/PotionElement.cpp	\
					game/objects/Food.cpp			\
					game/components/LimitSide.cpp	\
					game/objects/Limit.cpp			\
					game/components/Wall.cpp		\
					game/objects/Labyrinthe.cpp		\


SRCS			=	$(addprefix $(SRCS_DIR)/, $(FILES))

OBJS			=	$(SRCS:.cpp=.o)

HEADS			=	$(SRCS:.cpp=.hpp)

all:			$(NAME)

$(NAME):		$(OBJS)
	@make re -C ./libs/ncurses_lib/
	@make re -C ./libs/opengl_lib/
	@make re -C ./libs/sdl_lib/
	@$(CC) -o $(NAME) $(OBJS)
	@printf "\033[33mCompilation of %-40s \033[34m[\033[32m✔\033[34m]\033[0m\n" $(NAME)

$(OBJS):		$(HEADS)

%.o:			%.cpp
	@printf "\t\033[36m-> %-45s\033[34m[\033[32m✔\033[34m]\033[0m\n" $<
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@printf "\033[31mRemove %s objects\033[0m\n" $(NAME)
	@rm -rf $(OBJS)

fclean:			clean
	@printf "\033[31mRemove binary\033[0m\n"
	@rm -rf $(NAME)

lib:
	@make -C ./libs/ncurses_lib/
	@make -C ./libs/opengl_lib/
	@make -C ./libs/sdl_lib/

re-lib:
	@make re -C ./libs/ncurses_lib/
	@make re -C ./libs/opengl_lib/
	@make re -C ./libs/sdl_lib/

clean-lib:
	@make clean -C ./libs/ncurses_lib/
	@make clean -C ./libs/opengl_lib/
	@make clean -C ./libs/sdl_lib/

fclean-lib:
	@make fclean -C ./libs/ncurses_lib/
	@make fclean -C ./libs/opengl_lib/
	@make fclean -C ./libs/sdl_lib/

install-lib:
	@make install -C ./libs/opengl_lib/
	@make install -C ./libs/sdl_lib/

re:				fclean all

.PHONY: all, clean, fclean, re

