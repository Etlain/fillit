/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:38:05 by abara             #+#    #+#             */
/*   Updated: 2016/01/08 18:56:20 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

char	***cut_tetra(char ***dim)
{
	int		index;

	index = 0;
	while (dim[index] != NULL)
	{
		dim[index] = cut_it_all(dim[index]);
		index++;
	}
	return (dim);
}

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

int		main(void)
{
	char	*fname;
	char	*fname2;
	char	**tab;
	char	***dim;
	int		nb;

	nb = 0;
	fname = "all.txt";
	fname2 = "test.txt";
	tab = get_in_tab("testhard");
	//tab = get_in_tab(fname2);
	check_maps(tab);
	check_isnbrtrue(tab);
	dim = three_dim(tab);
	while (dim[nb] != NULL)
	{
		nb++;
	}
	printf("Check_links : %d\n", check_link(dim));
	printf("cases = %d\n", nb);
	dim = cut_tetra(dim);
	turn_letter(tab);
	resolver(dim, nb);
	return (0);
}
