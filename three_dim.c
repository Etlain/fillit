#include "Header.h"

void	bloc_size(char **tab, int *blocsize)
{
	int		x;
	int		y;

	x = 0;
	while (tab[x] != NULL)
	{
		y = 0;
		while (tab[x][y] != '\0')
		{
			if (x + 1 == 5 * *blocsize)
				*blocsize = *blocsize + 1;
			y++;
		}
		x++;
	}
}

char	***tab_in(char ***dim, char **tab)
{
	int		index;
	int		line;
	int		x;

	line = 0;
	index = 0;
	while (dim[index] != NULL)
	{
		x = 0;
		while (x < 4)
		{
			dim[index][x] = (char *)malloc(sizeof(dim) * 5);
			dim[index][x] = tab[line];
			dim[index][4] = NULL;
			line++;
			x++;
		}
		line++;
		index++;
	}
	return (dim);
}

char	***three_dim(char	**tab)
{
	int		blocsize;
	char	***dim;
	int		index;

	index = 0;
	blocsize = 1;
	bloc_size(tab, &blocsize);
	dim = (char ***)malloc(sizeof(**dim) * blocsize + 1);
	dim[blocsize] = NULL;
	while (index < blocsize)
	{
		dim[index] = (char **)malloc(sizeof(*dim) * 4 + 1);
		index++;
	}
	dim = tab_in(dim, tab);
	return (dim);
}
