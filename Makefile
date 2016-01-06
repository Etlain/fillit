# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/01/05 18:30:11 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC = check_isnbtrue.c check_link.c check_tab.c cut_tetra.c linked_list.c \
	  main.c power.c put_in_tab.c resolver.c tetra.c three_dim.c turn_letter.c \
	  libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: 
	gcc -o $(NAME) $(FLAGS) $(SRC)
	./$(NAME)

fclean:
	rm -r $(NAME)

re: fclean all
