/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:09:42 by abara             #+#    #+#             */
/*   Updated: 2016/01/08 14:40:20 by abara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

int		help_fun(char *str, int index, int nb)
{
	while (str[index] != '\0')
	{
		if (str[index] == '#')
			++nb;
		++index;
	}
	return (nb);
}

t_tab	*add_link(t_tab *list, char **tab)
{
	t_tab	*tmp;
	t_tab	*tmp2;

	tmp = malloc(sizeof(t_tab));
	tmp2 = list;
	tmp->next = NULL;
	tmp->tab = tab;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = tmp;
	}
	else
	{
		if (tmp)
		{
			tmp->next = list;
			return (tmp);
		}
	}
	return (tmp2);
}

t_tab	*get_in_list(char ***dim)
{
	t_tab	*list;
	int		index;

	list = NULL;
	index = 0;
	while (dim[index])
	{
		list = add_link(list, dim[index]);
		++index;
	}
	return (list);
}
