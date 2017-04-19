/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:29:54 by plogan            #+#    #+#             */
/*   Updated: 2017/04/19 16:14:29 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		*ft_create_map(int n)
{
	t_map		*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = n;
	map->map = ft_strnew(n * n);
	ft_memset(map->map, '.', n * n);
	if (map->map == NULL)
		return (NULL);
	return (map);
}
