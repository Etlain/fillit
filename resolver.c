/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:07:01 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/06 18:07:17 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

char	**create_map(int nb)
{
	char	**map;
	int		x;
	int		y;
	int		power;

	x = 0;
	power = get_power(nb);
	map = (char **)malloc(sizeof(*map) * power + 1);
	while (x != power)
	{
		map[x] = (char *)malloc(sizeof(*map) * power + 1);
		y = 0;
		while (y != power)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	map[power] = NULL;
	return (map);
}

t_pos	boucle(char ***dim, char **map, t_pos pos, int nb)
{
	while (map[pos.i][pos.j] != '\0' && pos.index < nb)
	{
		add_tetra(map, dim[pos.index], pos.i, pos.j);
		if (verif_tetra(map, dim[pos.index]) == 0)
		{
			del_tetra(map, dim[pos.index]);
		}
		else if (verif_tetra(map, dim[pos.index]) == 1)
		{
			pos.j = -1;
			pos.i = 0;
			pos.index++;
		}
		pos.j++;
	}
	return (pos);
}

t_pos	condition(char ***dim, char **map, t_pos pos, int nb)
{
	if (pos.i == get_power(nb) - 1 && pos.j == get_power(nb))
	{
		pos.index--;
		ft_pos_tetra(map, dim[pos.index], &pos.i, &pos.j);
		if (map[pos.i][pos.j + 1] == '\0')
		{
			pos.i++;
			pos.j = 0;
		}
		else
			pos.j++;
		del_tetra(map, dim[pos.index]);
	}
	else
	{
		pos.i++;
		pos.j = 0;
	}
	return (pos);
}

t_pos	check_over(t_pos pos, int cnb)
{
	printf("%d, %d\n", pos.index, cnb);
	if (pos.index == cnb)
		pos.check = 1;
	else
		pos.check = 0;
	return (pos);
}

void	resolve_it(t_pos pos, char ***dim, char **map, int nb)
{
	int		cnb;

	cnb = nb;
	while (pos.check == 0)
	{
		while (map[pos.i] != NULL)
		{
			pos = boucle(dim, map, pos, nb);
			pos = condition(dim, map, pos, nb);
		}
		pos = check_over(pos, cnb);
		if (pos.check == 0)
		{
			map = create_map(nb + 1);
			pos.i = 0;
			pos.j = 0;
			pos.index = 0;
		}
	}
}

int		resolver(char ***dim, int nb)
{
	t_pos	pos;
	char	**map;

	pos.i = 0;
	pos.j = 0;
	pos.index = 0;
	pos.check = 0;
	map = create_map(nb);
	resolve_it(pos, dim, map, nb);
	ft_putendl_tab(map);
	return (0);
}
