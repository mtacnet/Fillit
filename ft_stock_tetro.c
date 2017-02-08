/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_tetro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 11:17:59 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/07 12:23:30 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				ft_tab_len(char ***tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
**	ret[0] = position du 2eme # par rapport au premier (x)
**	ret[1] = position du 2eme # par rapport au premier (y)
**	ret[2] = position du 3eme # par rapport au premier (x)
**	ret[3] = position du 3eme # par rapport au premier (y)
**	ret[4] = position du 4eme # par rapport au premier (x)
**	ret[5] = position du 4eme # par rapport au premier (y)
**	i[0] = i
**	i[1] = x[0]
**	i[2] = x[1]
**	i[3] = y[0]
**	i[4] = y[1]
*/

int				*ft_get_pos_tab(char **tab, int nb, int *i)
{
	int		*ret;

	if (!(ret = (int *)ft_memalloc(sizeof(ret) * 8)))
		return (NULL);
	while (tab[i[3]][i[1]] != '#')
	{
		while (i[1] < 4 && tab[i[3]][i[1]] != '#')
			i[1]++;
		if (tab[i[3]][i[1]] != '#')
			incre_zero(&i[3], &i[1]);
	}
	i[2] = i[1] + 1;
	i[4] = i[3];
	while (i[4] < 4)
	{
		while (i[2] < 4)
		{
			if (tab[i[4]][i[2]] == '#')
				escape_norm(ret, i);
			i[2]++;
		}
		incre_zero(&i[4], &i[2]);
	}
	ret[6] = nb;
	return (ret);
}

int				**get_pos(char ***tab)
{
	int		**ret;
	int		i;
	int		l;
	int		t[5];

	l = ft_tab_len(tab);
	i = 0;
	if (!(ret = (int **)ft_memalloc(sizeof(ret) * (l + 1))))
		return (NULL);
	while (i < l)
	{
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
		t[3] = 0;
		t[4] = 0;
		ret[i] = ft_get_pos_tab(tab[i], i, t);
		i++;
	}
	return (ret);
}

int				ft_stock_tetro(char *file, t_env *env1)
{
	char		***tetro;
	char		buff[1024];
	int			fd;
	int			ret;
	int			i;

	i = -1;
	env1->nbp = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, buff, 1024)))
		buff[ret] = '\0';
	env1->nbp = ft_split_tetro(buff);
	if (!(tetro = (char ***)ft_memalloc(sizeof(tetro) * (env1->nbp + 1))))
		return (0);
	if (env1->nbp > 26)
	{
		ft_putstr("error\n");
		return (1);
	}
	else
		while (++i < env1->nbp)
			tetro[i] = ft_create_tab(&buff[i * 21]);
	ft_go_backtracking(env1, get_pos(tetro));
	return (0);
}
