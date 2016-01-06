#include "Header.h"

int		check_nb_link(char *str)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '#')
			nb++;
		index++;
	}
	if (nb == 0)
		return (0);
	return (1);
}

int		check_link_line(char *str)
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
				nb++;
		}
		index++;
	}
	check = str;
	return (nb == 0 ? 1 : 0);
}

int		check_link_spe(char *str)
{
	int		index;
	int		nb;

	index = 0;
	nb = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '#')
			nb++;
		index++;
	}
	index = 0;
	if (nb == 2)
	{
		while (str[index] != '#')
			index++;
		return (str[index + 1] != '#');
	}
	if (nb == 3)
	{
		while (str[index] != '#')
			index++;
		return (str[index + 1] != '#' || str[index + 2] != '#');
	}
	return (0);
}

int		check_link_help(t_tab *list)
{
	int		line;

	line = 0;
	while (line < 4)
	{
		if (check_link_line(list->tab[line]) != 0
				|| check_link_spe(list->tab[line]) != 0)
			return (1);
		line++;
	}
	return (0);
}

int		check_link(char ***dim)
{
	t_tab	*list;

	list = get_in_list(dim);
	while (list)
	{
		if (check_link_help(list) != 0)
		{
			return (1);
		}
		list = list->next;
	}
	return (0);
}
