/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:09:19 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/07 12:22:27 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_env		*env1;

	env1 = NULL;
	env1 = (t_env*)malloc(sizeof(t_env));
	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit [source file]\n");
		return (1);
	}
	else
	{
		if (ft_verif(argv[1]) == 1)
		{
			ft_putstr("error\n");
			return (1);
		}
		else
			ft_stock_tetro(argv[1], env1);
	}
	return (0);
}
