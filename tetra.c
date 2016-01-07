/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 11:53:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/07 23:23:25 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

char	ft_letter_tetra(char **tetra)
{
	int	i;
	int j;

	i = 0;
	while (tetra[i] != '\0')
	{
		j = 0;
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] >= 'A' && tetra[i][j] <= 'Z')
				return (tetra[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

void	del_tetra(char **tab, char **tetra)
{
	char	c;
	int		i;
	int		j;

	c = ft_letter_tetra(tetra);
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_pos_tetra(char **map, char **tetra, int *i, int *j)
{
	char	c;

	*i = 0;
	c = ft_letter_tetra(tetra);
	while (map[*i] != '\0')
	{
		*j = 0;
		while (map[*i][*j] != '\0')
		{
			if (map[*i][*j] == c)
			{
				if (map[*i + 1] != NULL && *j >= 0 &&
						map[*i + 1][*j - 1] == c)
					(*j)--;
				return (1);
			}
			(*j)++;
		}
		(*i)++;
	}
	return (0);
}

void	add_tetra(char **tab, char **tetra, int k, int l)
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
				j++;
			}
			l++;
		}
		i++;
		l = init_l;
		k++;
	}
}

int		verif_tetra(char **tab, char **tetra)
{
	int		i;
	int		j;
	int		nbr;
	char	c;

	i = 0;
	nbr = 0;
	c = ft_letter_tetra(tetra);
	while (tab[i] != '\0')
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == c)
				nbr++;
			j++;
		}
		i++;
	}
	if (nbr == 4)
		return (1);
	return (0);
}
