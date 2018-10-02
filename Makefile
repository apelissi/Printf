# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 14:48:06 by apelissi          #+#    #+#              #
#    Updated: 2018/09/20 21:58:53 by apelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

NAME = libftprintf.a 

SRC = afficher_str.c\
	  ft_memcpy.c\
	afficher_constchar.c\
	afficher_unsigned.c\
	ft_printf.c\
	afficher_int.c	\
	afficher_nb.c	\
	check_spe.c		\
	is_identifieur.c\
	afficher_percent.c\
	taille_nb.c\
	afficher_ptr.c	\
	ft_atoi.c	\
	taille_unsigned.c \
	ft_strlen.c \
	afficher_ws.c \
	get_uintmax.c \
	get_intmax.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	$(CC) $(CFLAGS)  $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
