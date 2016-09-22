# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtenigin <vtenigin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/25 11:11:04 by vtenigin          #+#    #+#              #
#    Updated: 2016/08/03 16:55:00 by vtenigin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = bsq

SRC = checkvalid.c\
		makestr.c\
		make_map.c\
		print_result.c\
		bsq.c\
		main.c

CFLAGS += -Wall -Wextra -Werror

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) -I bsq.h

clean:
	/bin/rm -f $(SRC:.c=.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
