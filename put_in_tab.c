/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:16:25 by abara             #+#    #+#             */
/*   Updated: 2016/01/08 13:16:34 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

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

	index = 0;
	line = get_line(fname);
	tab = (char **)malloc(sizeof(*tab) * line);
	while (index < line)
	{
		tab[index] = get_str(fname, index);
		index++;
	}
	tab[line - 1] = NULL;
	return (tab);
}
