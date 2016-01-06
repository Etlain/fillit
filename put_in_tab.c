#include "Header.h"

//////////////////////////////////////////////////////////////////////////////
//					  FONCTION DE RECUPERATION DE DONNEE					//
//////////////////////////////////////////////////////////////////////////////
// 1. Fonction récupère le nombre de ligne :CHECKED							//
// 2. Fonction qui place chaque ligne dans le tableau 2D :CHECKED			//
// 3. Fonction qui place chaque ligne dans une chaine de caractère :CHECKED	//
//	Now working																//
//////////////////////////////////////////////////////////////////////////////

#include <unistd.h>

int		get_line(char *fname)
{
	char	buf;
	int		line;
	int		fd;
	int		index;

	index = 0;
	line = 0;
	fd = open(fname, O_RDONLY);
	while (read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			line++;
		index++;
	}
	if (line != 0 || index != 0)
		line++;
	close(fd);
	return (line);
}

char	*get_in_str(char *fname, int index, char *str)
{
	char	buf;
	int		line;
	int		fd;
	int		i;

	i = 0;
	line = 0;
	fd = open(fname, O_RDONLY);
	while (line < index && read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			line++;
	}
	while (line == index && read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			line++;
		str[i] = buf;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_str(char *fname, int index)
{
	char	*str;
	char	buf;
	int		fd;
	int		size;
	int		line;

	size = 0;
	line = 0;
	fd = open(fname, O_RDONLY);
	while (line < index && read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			line++;
	}
	while (line == index && read(fd, &buf, 1) != 0)
	{
		if (buf == '\n')
			line++;
		size++;
	}
	str = (char *)malloc(sizeof(str) * size + 1);
	get_in_str(fname, index, str);
	//printf("%s", str);
	return (str);
}

char	**get_in_tab(char *fname)
{
	char	**tab;
	int		line;
	int		index;

	index = 0;
	line = get_line(fname);
	tab = (char **)malloc(sizeof(*tab) * line);
	while (index < line)
	{
		tab[index] = get_str(fname, index);
		index++;
	}
	//printf("line : %d\n", line);						LINE
	tab[line - 1] = NULL;
	return (tab);
}
