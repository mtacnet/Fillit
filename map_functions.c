/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:02:56 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/07 12:02:58 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**clear_map(char **map, int cur)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] >= 'A' + cur)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	return (map);
}

int		actual_x(char **map, int cur)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x] != 'A' + cur)
	{
		if (!map[y][x++])
		{
			x = 0;
			y++;
		}
	}
	return (x);
}

int		actual_y(char **map, int cur)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (map[y][x] != 'A' + cur)
	{
		if (!map[y][x++])
		{
			x = 0;
			y++;
		}
	}
	return (y);
}
