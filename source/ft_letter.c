/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 11:53:51 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/01/22 13:07:55 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

char		ft_letter(char **tetra)
{
	int	i;
	int j;

	i = 0;
	while (tetra[i] != '\0')
	{
		j = 0;
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] >= 'A' && tetra[i][j] <= 'Z')
				return (tetra[i][j]);
			++j;
		}
		++i;
	}
	return (0);
}
