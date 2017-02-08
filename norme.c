/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:01:46 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/07 12:01:48 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	incre_zero(int *incre, int *zero)
{
	*incre += 1;
	*zero = 0;
}

void	zero_zero(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

void	escape_norm(int *ret, int *i)
{
	ret[i[0]] = i[2] - i[1];
	i[0] += 1;
	ret[i[0]] = i[4] - i[3];
	i[0] += 1;
}
