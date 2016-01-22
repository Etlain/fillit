/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:59:21 by abara             #+#    #+#             */
/*   Updated: 2016/01/22 15:05:06 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		nb_line_link(char **tab, int j)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (tab[i] != NULL)
	{
		if (tab[i][j] == '#')
			nb++;
		i++;
	}
	return (nb);
}

int		check_ord_link(t_tab *list)
{
	int	nb;
	int i;
	int j;

	j = 0;
	i = 0;
	while (list->tab[i][j] != '\0')
	{
		i = 0;
		nb = nb_line_link(list->tab, j);
		if (nb == 2)
		{
			while (list->tab[i][j] != '#')
				i++;
			if (list->tab[i + 1][j] != '#')
				return (1);
		}
		if (nb == 3)
		{
			while (list->tab[i][j] != '#')
				i++;
			if (list->tab[i + 1][j] != '#')
				return (1);
		}
		j++;
	}
	return (0);
}
