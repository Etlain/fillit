# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 09:06:02 by mmouhssi          #+#    #+#              #
#*   Updated: 2016/01/19 17:31:31 by mmouhssi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft/libft.a

SRC = check_isnbtrue.c check_link.c check_tab.c cut_tetra.c linked_list.c \
      main.c power.c put_in_tab.c resolver.c tetra.c three_dim.c turn_letter.c \
      get_next_line.c check_nb_link.c ft_letter.c link.c

PATH_SRC = source/

FLAGS = -Wall -Wextra -Werror

LIBFT = -C libft/

all: 
	make $(LIBFT)
	gcc -o $(NAME) $(FLAGS) $(addprefix $(PATH_SRC), $(SRC)) $(LIB)

clean :
	make clean $(LIBFT)

fclean:
	make fclean $(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
