/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:45:34 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/17 19:50:47 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		 	*ft_create_map(char *input)
{
	t_map *map;

	(void)input;

	if(!(map = (t_map *)malloc(sizeof(t_map)))) // A verifier par le grand mickael
		return (NULL);
	map->size = 8;
	map->map = ft_strnew(8 * 8);
	ft_memset(map->map, '.', 8 * 8);
	if (map->map == NULL)
		return (NULL);
	return (map);
}

//int				ft_place(t_map *map, char *input, int nb_piece)
//{
//	if (nb_piece == 3)
//		return (0);
//	return (1);
//}

//int				ft_clean(t_map *map, int nb_piece)
//{
//	return (0);
//}

void			ft_put_pieces(t_map *map, t_map *map_f, char *input, int nb_piece)
{
	int i;
	int size_sq;

	i = 0;
	size_sq = map->size * map->size;
	while (i < size_sq)
	{
//		if (ft_place(map, map_f, input, nb_piece)) // Renvois 0 si pas possible ou si derniere piece
//			ft_put_pieces(map, map_f input, nb_piece + 1);
//		else
//			ft_clean(map, nb_piece);
		i++;
	}
}

int				ft_resolver(char *input)
{
	t_map	*map;
	t_map	*map_f;

	map = ft_create_map(input);
	if(!(map_final = ft_create_map(input)))
		return (0);
	ft_put_pieces(map, map_f input, 0);
	return (1);
}
