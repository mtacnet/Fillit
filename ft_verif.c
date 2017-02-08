/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:01:36 by mtacnet           #+#    #+#             */
/*   Updated: 2017/02/07 12:22:43 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif(char *file)
{
	char	*buff;
	int		fd;
	int		ret;
	int		i;

	i = 0;
	buff = ft_strnew(21);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ((int)NULL);
	while ((ret = read(fd, buff, 21)))
	{
		i++;
		buff[ret] = '\0';
		if ((ft_count_htag(buff) == 0) || (ft_verif_char(buff) == 0) ||
				(ft_verif_line(buff) == 0) || (ft_is_tetro(buff) == 0))
			return (1);
	}
	if (buff[20] != '\0')
		return (1);
	if (!i)
		return (1);
	close(fd);
	return (0);
}

int		ft_count_htag(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

int		ft_verif_char(char *str)
{
	int		i;
	int		is_char;

	i = 0;
	is_char = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#')
		{
			is_char++;
			i++;
		}
		else if (str[i] == '\n')
			i++;
		else
			i++;
	}
	if (is_char == 16)
		return (1);
	return (0);
}

int		ft_verif_line(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		i += 4;
		if (str[i] == '\n')
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

int		ft_is_tetro(char *str)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if ((i - 5 >= 0) && (str[i - 5] == '#'))
				link++;
			if ((i - 1 >= 0) && (str[i - 1] == '#'))
				link++;
			if ((i + 5 < ft_strlen(str)) && (str[i + 5] == '#'))
				link++;
			if ((i + 1 < ft_strlen(str)) && (str[i + 1] == '#'))
				link++;
		}
		i++;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}
