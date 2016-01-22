/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:59:21 by abara             #+#    #+#             */
/*   Updated: 2016/01/22 15:10:39 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		empty_line(char **check, char *str, int i, int t)
{
	static int nbr_d;

	if (!nbr_d || i == 0)
		nbr_d = 0;
	if (((check_nb_link(*check) == 0 && check_nb_link(str) > 0) ||
			(check_nb_link(*check) > 0 && check_nb_link(str) == 0))
			&& t == 1)
	{
		if (nbr_d < 4)
		{
			*check = str;
			t = 0;
			return (1);
		}
	}
	nbr_d = check_nb_link(str) + nbr_d;
	if (check_nb_link(str) == 0 || check_nb_link(*check) == 0)
	{
		*check = str;
		return (0);
	}
	return (2);
}

static int		check_link_line(char *str, int i)
{
	static char	*check;
	static int	t;
	int			index;
	int			nb;
	int			e_l;

	if (!check || i == 0)
		check = str;
	if (!t || i == 0)
		t = 0;
	if ((e_l = empty_line(&check, str, i, t)) != 2)
		return (e_l);
	index = 0;
	nb = 0;
	while (check[index] != '\0')
	{
		if (check[index] == '#' && str[index] == '#')
		{
			t = 1;
			nb++;
		}
		index++;
	}
	check = str;
	return (nb == 0 ? 1 : 0);
}

static int		check_link_spe(char *str)
{
	int		index;
	int		nb;

	nb = check_nb_link(str);
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

static int		check_link_help(t_tab *list)
{
	int		line;

	line = 0;
	while (line < 4)
	{
		if (check_link_line(list->tab[line], line) != 0
				|| check_link_spe(list->tab[line]) != 0)
			return (1);
		line++;
	}
	return (0);
}

int				check_link(char ***dim)
{
	t_tab	*list;

	list = get_in_list(dim);
	while (list)
	{
		if (check_link_help(list) != 0 || check_ord_link(list) != 0)
			return (1);
		list = list->next;
	}
	return (0);
}
