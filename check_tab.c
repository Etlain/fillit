#include "Header.h"

//////////////////////////////////////////////////////////////////
//			 FONCTION DE VERIFICATION DES DONNEE				//
//////////////////////////////////////////////////////////////////
// 1. Nombre d'input cohérent :CHECKED                          //
// 2. Taille des lines cohérentes :CHECKED                      //
// 3. Charactères cohérents :CHECKED							//
// 4. Tetriminos cohérents :CHECKED								//
//	Now Working													//
//////////////////////////////////////////////////////////////////

int		check_line_size(char *str, int line, int maxline)
{
	int		size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	if (!maxline || !line)
		return (0);
/*	if (line == maxline)
		size++;*/
	if (size != 5)
	{
		printf("size : %d", size);		//REMOVE
		return (1);
	}
	return (0);
}

int		check_line(char **tab, int maxline, int	*pack)
{
	int		line;

	line = 0;
	*pack = 1;
	while (tab[line] != NULL)
	{
		if (line + 1 == 5 * *pack)
		{
			if (tab[line][0] != '\n')
				return (1);
			line++;
			*pack = *pack + 1;
		}
		if (check_line_size(tab[line], line, maxline) != 0)
		{
			printf(" Line : %d\n", line);	//REMOVE
			return (1);
		}
		line++;
	}
	return (0);
}

int		check_char(char **tab, int	*maxline, int *nbsign)
{
	int		line;
	int		c;

	line = 0;
	while (tab[line] != NULL)
	{
		c = 0;
		while (tab[line][c] != '\0')
		{
			if (tab[line][c] != '.' && tab[line][c] != '#' && tab[line][c] != '\n')
			{
				printf("Pos : %d:%d\n", line, c);  //REMOVE
				printf("%c", tab[line][c]);		//REMOVE
				return (1);
			}
			if (tab[line][c] == '#')
				*nbsign = *nbsign + 1;
			c++;
		}

		line++;
	}
	*maxline = line - 1;
	return (0);
}

int		check_nbline(char **tab, int pack, int maxline, int nbsign)
{
	if (!tab)
		return (-1);
	if (((maxline - pack) % 4) != 0 || ((pack + 1) * 4) != nbsign)
	{
		printf("%d - %d : 4 = %d\n", maxline, pack,((maxline - pack) % 4));//
		return (1);
	}
	return (0);
}

int		check_maps(char **tab)
{
	int		maxline;
	int		pack;
	int		nbsign;

	pack = 1;
	nbsign = 0;
	maxline = 0;
	printf("check_map : %d\n", check_char(tab, &maxline, &nbsign));
	printf("Check_line : %d\n", check_line(tab, maxline, &pack));
	pack--;
	if (pack > 25)
		return (1);
	printf("Check_nbline : %d\n", check_nbline(tab, pack, maxline + 1, nbsign));
	return (0);
}
