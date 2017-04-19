/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:54:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 16:41:27 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_input(char *filename)
{
	char	*input;
	int		ret;
	int		fd;

	if (!(input = ft_strnew(546)))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	ret = read(fd, input, 546);
	if (ret == -1)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	close(fd);
	return (input);
}
