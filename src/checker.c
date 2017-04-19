/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:15:17 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 15:52:22 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		hash_is_valid(char *str, int i, int *nb_next, int *nb_hash)
{
	int		x;
	int		y;
	int		count;

	*nb_hash = *nb_hash + 1;
	count = 0;
	x = i % 5;
	y = i / 5;
	if (x != 0 && str[i - 1] == '#')
		++count;
	if (x != 3 && str[i + 1] == '#')
		++count;
	if (y != 0 && str[i - 5] == '#')
		++count;
	if (y != 3 && str[i + 5] == '#')
		++count;
	*nb_next += count;
	return (count);
}

static int		is_piece(char *str)
{
	int		nb_hash;
	int		k;
	int		i;
	int		nb_next;

	nb_hash = 0;
	i = 0;
	k = 0;
	nb_next = 0;
	while (k < 20)
	{
		if (str[k] == '#' && !hash_is_valid(str, k, &nb_next, &nb_hash))
			return (0);
		if (str[k] == '.' || str[k] == '#')
			++i;
		else if (str[k] == '\n' && i == 4)
			i = 0;
		else
			return (0);
		++k;
	}
	if (nb_hash != 4 || nb_next < 6)
		return (0);
	return (1);
}

int				ft_check_input(char *input)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(input);
	if (len == 0)
		return (0);
	while (input[i])
	{
		if (!(i % 21) && !is_piece(&input[i]))
			return (0);
		else if (i % 21 == 20)
		{
			if (input[i] == '\n' && i == len - 1)
				return (0);
			if (input[i] != '\n')
				return (0);
		}
		++i;
	}
	return (1);
}
