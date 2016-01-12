# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/01/12 16:51:44 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = check_isnbtrue.c check_link.c check_tab.c cut_tetra.c linked_list.c \
	  main.c power.c put_in_tab.c resolver.c tetra.c three_dim.c turn_letter.c \
	  libft/libft.a

FLAGS = -Wall -Wextra -Werror

LIBFT = -C libft/

all: 
	make $(LIBFT)
	gcc -o $(NAME) $(FLAGS) $(SRC)

clean :
	make clean $(LIBFT)

fclean:
	make fclean $(LIBFT)
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re
