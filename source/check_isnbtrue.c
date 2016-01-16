/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isnbtrue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:46:36 by abara             #+#    #+#             */
/*   Updated: 2016/01/13 18:51:44 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		check_nbtrue_help(char **tab, int line, int *pack, int *index)
{
	int		x;

	x = 0;
	while (tab[line][x] != '\0')
	{
		if (tab[line][x] == '#')
			(*index)++;
		x++;
	}
	if (line + 1 == 5 * *pack)
	{
		if (*index != 4)
			return (1);
		(*pack)++;
		*index = 0;
	}
	return (0);
}

static int		check_nbtrue(char **tab)
{
	int		line;
	int		index;
	int		pack;

	pack = 1;
	line = 0;
	index = 0;
	while (tab[line] != NULL)
	{
		if (check_nbtrue_help(tab, line, &pack, &index) != 0)
			return (1);
		line++;
	}
	return (0);
}

int				check_isnbrtrue(char **tab)
{
	if (check_nbtrue(tab) != 0)
		return (1);
	return (0);
}
