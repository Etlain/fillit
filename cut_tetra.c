#include "Header.h"

//Ceci est un prototype et peut ne pas être nécessaire
//WORKING NOW

int		isempty_line_h(char *str)
{
	int		x;
	int		index;

	index = 0;
	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '#')
			index++;
		x++;
	}
	if (index != 0)
		return (0);
	return (1);
}

char	**cut_line_h(char **tab, int index)
{
	while (tab[index] != NULL)
	{
		tab[index] = tab[index + 1];
		index++;
	}
	return (tab);
}

char	**cut_line_v(char **tab, int index)
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
			index++;
		}
		tab[x][index] = '\0';
		x++;
	}
	return (tab);
}

int		isempty_line_v(char **tab, int y)
{
	int		index;
	int		x;

	x = 0;
	index = 0;
	while (tab[x] != NULL)
	{
		if (tab[x][y] == '#')
			index++;
		x++;
	}
	if (index != 0)
		return (0);
	return (1);
}

char	**cut_it_all(char **tab)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	y = 0;
	count = 0;
	while (tab[x] != NULL)
	{
		if (isempty_line_h(tab[x]) != 0)
		{
			tab = cut_line_h(tab, x);
			x = 0;
		}
		else
			x++;
	}
	x = 0;
	while (tab[x][y] != '\0')
	{
		if (isempty_line_v(tab, y) != 0)
		{
			tab = cut_line_v(tab, y);
			y = 0;
		}
		else
			y++;
	}
	//show_tab(tab);
	return (tab);
}

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
