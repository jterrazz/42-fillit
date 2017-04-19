/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:54:14 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 15:52:51 by jterrazz         ###   ########.fr       */
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
		ft_putstr("Blyat ca marche pas\n");
		return (NULL);
	}
	ret = read(fd, input, 546);
	if (ret == -1)
	{
		ft_putstr("Ptn ca c'est de la gestion derreur");
		return (NULL);
	}
	close(fd);
	return (input);
}
