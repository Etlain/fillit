/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:16:25 by abara             #+#    #+#             */
/*   Updated: 2016/01/16 20:32:33 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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
	return (str);
}

char	**get_in_tab(char *fname)
{
	char	**tab;
	int		line;
	int		index;
	int		fd;

	index = 0;
	fd = open(fname, O_RDONLY);
	line = get_line(fname);
	tab = (char **)malloc(sizeof(*tab) * line);
	while (index < line)
	{
		get_next_line(fd, &tab[index]);
		ft_putstr(tab[index]);
		index++;
	}
	if (tab[line - 2][1] == '\0' || tab[0][0] == '\0')
		return (NULL);
	tab[line - 1] = NULL;
	return (tab);
}
