/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:18:14 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/07 11:56:29 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map(int size)
{
	char	**ret;
	int		i;

	i = 0;
	if (!(ret = (char **)ft_memalloc(sizeof(ret) * size + 1)))
		return (NULL);
	while (i < size)
	{
		ret[i] = ft_strnew(size);
		ft_memset(ret[i], '.', size);
		i++;
	}
	return (ret);
}
