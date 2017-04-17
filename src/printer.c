/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:29:20 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/17 19:37:36 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_map(char *str, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j == size)
		{
			ft_putchar('\n');
			j = 0;
		}
		ft_putchar(str[i]);
		j++;
		i++;
	}
	ft_putchar('\n');
}
