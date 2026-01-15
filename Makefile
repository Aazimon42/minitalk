# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-maio <edi-maio@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/10 19:29:25 by edi-maio          #+#    #+#              #
#    Updated: 2026/01/15 19:04:53 by edi-maio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRVFILES = server.c

CLIENTFILES = client.c

SRVSRCS = $(addprefix srcs/,$(SRVFILES))

CLIENTSRCS = $(addprefix srcs/,$(CLIENTFILES))

SRVOBJS = $(SRVSRCS:.c=.o)

CLIENTOBJS = $(CLIENTSRCS:.c=.o)

.o: .c
	cc $(CFLAGS) -I $(INCLUDES) -c $< -o $@

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(PRINTF) $(SRVOBJS)
	cc $(CFLAGS) $(SRVOBJS) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): $(LIBFT) $(PRINTF) $(CLIENTOBJS)
	cc $(CFLAGS) $(CLIENTOBJS) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C printf

clean:
	rm -f $(SRVOBJS)
	rm -f $(CLIENTOBJS)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(SERVER)
	rm -f $(CLIENT)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re
