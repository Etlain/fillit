/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:59:21 by abara             #+#    #+#             */
/*   Updated: 2016/01/18 10:47:25 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		check_nb_link(char *str)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '#')
			++nb;
		++index;
	}
	if (nb == 0)
		return (0);
	return (1);
}

static int		check_link_line(char *str)
{
	static char	*check;
	int			index;
	int			nb;

	nb = 0;
	if (!check)
		check = str;
	index = 0;
	if (check_nb_link(str) == 0 || check_nb_link(check) == 0)
	{
		check = str;
		return (0);
	}
	while (check[index] != '\0')
	{
		if (check[index] == '#')
		{
			if (str[index] == '#')
				++nb;
		}
		++index;
	}
	check = str;
	return (nb == 0 ? 1 : 0);
}

static int		check_link_spe(char *str)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	nb = help_fun(str, index, nb);
	index = 0;
	if (nb == 2)
	{
		while (str[index] != '#')
			++index;
		return (str[index + 1] != '#');
	}
	if (nb == 3)
	{
		while (str[index] != '#')
			++index;
		if (str[index + 1] != '#' || str[index + 2] != '#')
			return (1);
	}
	return (0);
}
/*
static int		nb_line_link(char **tab, int j)
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

static int		check_ord_link(t_tab *list)
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
*/
static int		check_link_help(t_tab *list)
{
	int		line;

	line = 0;
	while (line < 4)
	{
		/*if (check_link_line(list->tab[line]) != 0
				|| check_link_spe(list->tab[line]) != 0)
			return (1);*/
		printf("check link line: %d\n check link spe: %d\n", check_link_line(list->tab[line]), check_link_spe(list->tab[line]));
		++line;
	}
	ft_putchar('\n');
	return (0);
}

int		check_link(char ***dim)
{
	t_tab	*list;

	list = get_in_list(dim);
	while (list)
	{
		if (check_link_help(list) != 0 )//|| check_ord_link(list) != 0)
			return (1);
		list = list->next;
	}
	return (0);
}
