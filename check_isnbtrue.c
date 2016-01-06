#include "Header.h"

//////////////////////////////////////////////////////////////////
//			 FONCTION DE VERIFICATION DES DONNEE				//
//////////////////////////////////////////////////////////////////
// 1. Nombre de # par 4 lignes cohérent :CHECKED                //
// 2. Lien entre les tetriminos cohérents :X                    //
//	Not Working													//
//////////////////////////////////////////////////////////////////

int		check_nbtrue_help(char **tab, int line, int *pack, int *index)
{
	int		x;

	x = 0;
	while (tab[line][x] != '\0')
	{
		if (tab[line][x] == '#')
			*index = *index + 1;
		x++;
	}
	if (line + 1 == 5 * *pack)
	{
		if (*index != 4)
			return (1);
		*pack = *pack + 1;
		*index = 0;
	}
	return (0);
}

int		check_nbtrue(char **tab)
{
	int		line;
	int		index;
	int		pack;

	pack = 1;
	line = 0;
	index = 0;
	while (tab[line] != NULL)
	{
		if (check_nbtrue_help(tab, line, &pack, &index) != 0)
			return (1);
		line++;
	}
	return (0);
}

int		check_isnbrtrue(char **tab)
{
	printf("check_nbtrue : %d\n", check_nbtrue(tab));
	return (0);
}