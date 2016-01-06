/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:33:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/06 16:34:02 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.h"

t_tab	*add_link(t_tab *list, char **tab)
{
	t_tab	*tmp;
	t_tab	*tmp2;
	int		index;

	index = 0;
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

void	show_list(t_tab *list)
{
	int		index;

	while (list)
	{
		index = 0;
		while (index < 4)
		{
			printf("%s", list->tab[index]);
			index++;
		}
		printf("\n");
		list = list->next;
	}
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
		index++;
	}
	//show_list(list);
	return (list);
}
