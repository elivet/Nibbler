# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elivet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/17 13:55:31 by elivet            #+#    #+#              #
#    Updated: 2015/03/17 13:55:33 by elivet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libopengl

CC			=	g++

CFLAGS		=	-Wall -Wextra -Werror -pedantic -ansi -O3

SRC_LIB		=	$(NAME).cpp		\
				OpenglLib.cpp

OBJ_LIB		=	$(SRC_LIB:.cpp=.o)

HEAD		=	$(NAME).hpp

INC			=	-I ~/.brew/include/

LIB			=	-L ~/.brew/lib/ -lglfw3 -framework OpenGL

all:		$(NAME).dylib

$(NAME).dylib:	$(OBJ_LIB)
	@g++ -shared -o $(NAME).dylib $(OBJ_LIB) $(LIB)
	@printf "\033[33mCompilation of %-40s \033[34m[\033[32m✔\033[34m]\033[0m\n" $(NAME)

%.o:		%.cpp $(HEAD)
	@$(CC) $(CFLAGS) -fpic -c $< -o $@ $(INC)
	@printf "\t%-48s\033[34m[\033[32m✔\033[34m]\033[0m\n" $<

clean:
	@printf "\033[31mRemove %s objects\033[0m\n" $(NAME)
	@rm -rf $(OBJ_LIB)

fclean:			clean
	@printf "\033[31mRemove binary\033[0m\n"
	@rm -rf $(NAME).dylib

re:			fclean all

install:
	@if [ ! -d "~/.brew" ] ; \
	then \
		brew update; \
	fi;
	@mkdir -p ~/Library/Caches
	@mkdir -p ~/Library/Caches/Homebrew
	@~/.brew/bin/brew install homebrew/versions/glfw3

.PHONY:		all re fclean clean
