/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:38:05 by abara             #+#    #+#             */
/*   Updated: 2016/01/13 18:53:02 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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

char	**create_map(int power)
{
	char	**map;
	int		x;
	int		y;
	//int		power;

	x = 0;
	//power = get_power(nb);
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

static void	main_control(char ***dim, char **tab)
{
	int		nb;

	nb = 0;
	while (dim[nb] != NULL)
		nb++;
	dim = cut_tetra(dim);
	turn_letter(tab);
	resolver(dim, nb);
}

int			main(int argc, char	**argv)
{
	char	**tab;
	char	***dim;

	if (argc != 2)
	{
		ft_putendl("error");
		return (0);
	}
	ft_putendl("Ok");
	tab = get_in_tab(argv[1]);
	ft_putendl("getin");
	if (tab == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	dim = three_dim(tab);
	ft_putendl("three_dim");
	if (check_maps(tab) != 0 || check_isnbrtrue(tab) != 0 || check_link(dim) != 0)
	{
		ft_putendl("error");
		return (0);
	}
	ft_putendl("checks");
	main_control(dim, tab);
	return (0);
}
