/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_tetra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:22:14 by abara             #+#    #+#             */
/*   Updated: 2016/01/13 18:51:26 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		isempty_line_h(char *str)
{
	int		x;
	int		index;

	index = 0;
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '#')
			++index;
		++x;
	}
	if (index != 0)
		return (0);
	return (1);
}

static char		**cut_line_h(char **tab, int index)
{
	while (tab[index] != NULL)
	{
		tab[index] = tab[index + 1];
		++index;
	}
	return (tab);
}

static char		**cut_line_v(char **tab, int index)
{
	int		x;
	int		rindex;

	rindex = index;
	x = 0;
	while (tab[x] != NULL)
	{
		index = rindex;
		while (tab[x][index] != '\n')
		{
			tab[x][index] = tab[x][index + 1];
			++index;
		}
		tab[x][index] = '\0';
		++x;
	}
	return (tab);
}

static int		isempty_line_v(char **tab, int y)
{
	int		index;
	int		x;

	x = 0;
	index = 0;
	while (tab[x] != NULL)
	{
		if (tab[x][y] == '#')
			++index;
		++x;
	}
	if (index != 0)
		return (0);
	return (1);
}

char	**cut_it_all(char **tab)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (tab[x] != NULL)
	{
		if (isempty_line_h(tab[x]) != 0)
		{
			tab = cut_line_h(tab, x);
			--x;
		}
		++x;
	}
	x = 0;
	while (tab[x][y] != '\0')
	{
		if (isempty_line_v(tab, y) != 0)
		{
			tab = cut_line_v(tab, y);
			--y;
		}
		++y;
	}
	return (tab);
}
