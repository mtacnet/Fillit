/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <atgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:10:46 by atgerard          #+#    #+#             */
/*   Updated: 2017/01/30 12:23:37 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_the_square(int n)
{
	int ret;

	ret = 0;
	while (ret * ret < n)
		ret++;
	return (ret);
}
