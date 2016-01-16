/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:01:24 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/16 19:26:34 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct		s_tab
{
	char			**tab;
	struct s_tab	*next;
}					t_tab;

typedef struct		s_pos
{
	int				i;
	int				j;
	int				index;
	int				check;
}					t_pos;

int					check_maps(char **tab);
int					check_isnbrtrue(char **tab);
char				**get_in_tab(char *fname);
void				turn_letter(char **tab);
char				***three_dim(char	**tab);
int					check_link(char ***dim);
void				show_list(t_tab *list);
t_tab				*add_link(t_tab *list, char **tab);
t_tab				*get_in_list(char ***dim);
int					get_power(int nb);
int					resolver(char ***dim, int nb);
void				add_tetra(char **map, char **dim, int l, int k);
char				***cut_tetra(char ***dim);
void				show_dim(char ***dim);
void				show_tab(char **tab);
void				del_tetra(char **tab, char **tetra, int i, int j);
int					verif_tetra(char **tab, char **tetra, int i, int j);
char				**cut_it_all(char **tab);
int					ft_pos_tetra(char **map, char **tetra, int *i, int *j);
char				**create_map(int nb);
int					help_fun(char *str, int index, int nb);
int					check_add_tetra(char **tab, char **tetra, int k, int l);

#endif
