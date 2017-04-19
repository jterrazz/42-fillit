/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:05:46 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 13:41:54 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char *input;

	if (argc == 2)
	{
		input = ft_get_input(argv[1]);
		if (input == NULL)
			return (0);
		if (!ft_check_input(input))
		{
			ft_putstr("error\n");
			return (0);
		}
		if (!ft_resolver(input))
			return (0);
	}
	else
		ft_usage();
	return (0);
}
