/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tetro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <atgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 11:36:43 by atgerard          #+#    #+#             */
/*   Updated: 2017/01/30 12:26:19 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_split_tetro(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] == '\n')
				j++;
		}
		i++;
	}
	return (j);
}
