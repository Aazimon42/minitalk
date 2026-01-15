# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-maio <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 14:47:44 by edi-maio          #+#    #+#              #
#    Updated: 2026/01/15 19:04:07 by edi-maio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

HEADER = libftprintf.h

SOURCES = ft_printf.c \
		ft_putchar.c \
		ft_putnbr_base.c \
		ft_putptrhexa.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_slen.c \
		ft_strncmp.c

OBJ = $(SOURCES:.c=.o)

%.o : %.c $(HEADER)
	cc $(CFLAGS) $< -c -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
