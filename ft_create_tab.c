/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 11:07:40 by mtacnet           #+#    #+#             */
/*   Updated: 2017/01/31 10:44:50 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab(char *buff)
{
	char		**tab;
	int			i;

	tab = ft_memalloc(sizeof(*tab) * 5);
	i = 0;
	while (i < 4)
	{
		tab[i] = ft_strsub(buff, i * 5, 4);
		i++;
	}
	return (tab);
}
