/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 11:53:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/22 13:12:06 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void				del_tetra(char **tab, char **tetra, int i, int j)
{
	char	c;

	c = ft_letter(tetra);
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				tab[i][j] = '.';
			++j;
		}
		j = 0;
		++i;
	}
}

int					ft_pos_tetra(char **map, char **tetra, int *i, int *j)
{
	char	c;

	*i = 0;
	c = ft_letter(tetra);
	while (map[*i] != '\0')
	{
		*j = 0;
		while (map[*i][*j] != '\0')
		{
			if (map[*i][*j] == c)
			{
				if (map[*i + 1] != NULL && *j >= 0 &&
						map[*i + 1][*j - 1] == c)
					--(*j);
				return (1);
			}
			++(*j);
		}
		++(*i);
	}
	return (0);
}

int					check_add_tetra(char **tab, char **tetra, int k, int l)
{
	int i;
	int j;
	int init_l;

	i = 0;
	init_l = l;
	while (tab[k] != NULL && tetra[i] != NULL)
	{
		j = 0;
		while (tab[k][l] != '\0')
		{
			if (tetra[i][j] != '\0')
			{
				if (tetra[i][j] >= 'A' && tetra[i][j] <= 'Z'
						&& tab[k][l] >= 'A' && tab[k][l] <= 'Z')
					return (1);
				++j;
			}
			++l;
		}
		++i;
		l = init_l;
		++k;
	}
	return (0);
}

void				add_tetra(char **tab, char **tetra, int k, int l)
{
	int i;
	int j;
	int init_l;

	i = 0;
	init_l = l;
	while (tab[k] != NULL && tetra[i] != NULL)
	{
		j = 0;
		while (tab[k][l] != '\0')
		{
			if (tetra[i][j] != '\0')
			{
				if (tetra[i][j] >= 'A' && tetra[i][j] <= 'Z'
						&& tab[k][l] == '.')
					tab[k][l] = tetra[i][j];
				++j;
			}
			++l;
		}
		++i;
		l = init_l;
		++k;
	}
}

int					verif_tetra(char **tab, char **tetra, int i, int j)
{
	int		nbr;
	char	c;

	nbr = 0;
	c = ft_letter(tetra);
	while (tab[i] != '\0')
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				++nbr;
			++j;
		}
		j = 0;
		++i;
	}
	if (nbr == 4)
		return (1);
	return (0);
}
