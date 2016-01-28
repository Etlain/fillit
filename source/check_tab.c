/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:18:40 by abara             #+#    #+#             */
/*   Updated: 2016/01/28 12:46:38 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		check_line_size(char *str)
{
	int		size;

	size = 0;
	while (str[size] != '\0')
		++size;
	if (size < 5 || size > 5)
		return (1);
	return (0);
}

static int		check_line(char **tab, int *pack)
{
	int		line;

	line = 0;
	*pack = 1;
	while (tab[line] != NULL)
	{
		if (line + 1 == 5 * *pack)
		{
			if (tab[line][0] != '\n')
				return (1);
			line++;
			(*pack)++;
		}
		if (check_line_size(tab[line]) != 0)
			return (1);
		line++;
	}
	return (0);
}

static int		check_char(char **tab, int *maxline, int *nbsign)
{
	int		line;
	int		c;

	line = 0;
	while (tab[line] != NULL)
	{
		c = 0;
		while (tab[line][c] != '\0')
		{
			if (tab[line][c] != '.' && tab[line][c] != '#'
					&& tab[line][c] != '\n')
			{
				return (1);
			}
			if (tab[line][c] == '#')
				++(*nbsign);
			++c;
		}
		++line;
	}
	*maxline = line - 1;
	return (0);
}

static int		check_nbline(char **tab, int pack, int maxline, int nbsign)
{
	if (!tab)
		return (-1);
	if (((maxline - pack) % 4) != 0 || ((pack + 1) * 4) != nbsign)
	{
		return (1);
	}
	return (0);
}

int				check_maps(char **tab)
{
	int		maxline;
	int		pack;
	int		nbsign;

	pack = 1;
	nbsign = 0;
	maxline = 0;
	if (check_char(tab, &maxline, &nbsign) != 0)
		return (1);
	if (check_line(tab, &pack) != 0)
		return (1);
	pack--;
	if (check_nbline(tab, pack, maxline + 1, nbsign) != 0)
		return (1);
	return (0);
}
