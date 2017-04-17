/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:45:34 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/17 19:38:13 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		 	*ft_create_map(char *input)
{
	t_map *map;

	(void)input;

	map = (t_map *)malloc(sizeof(t_map)); // A verifier par le grand mickael
	if (map == NULL)
		return (NULL);
	map->size = 8;
	map->map = ft_strnew(8 * 8);
	ft_memset(map->map, '.', 8 * 8);
	if (map->map == NULL)
		return (NULL);
	return (map);
}

//int				ft_put_piece(t_map *map, char *input, int nb_piece)
//{
//	if (nb_piece == 3)
//		return (0);
//	return (1);
//}

//int				ft_clean_piece(t_map *map, int nb_piece)
//{
//	return (0);
//}

//void			ft_put_pieces(t_map *map, char *input, int nb_piece)
//{
//	int i;
//	int size_sq;
//
//	i = 0;
//	size_sq = map->size * map->size;
//	while (i < size_sq)
//	{
//		if (ft_put_piece(map, input, nb_piece)) // Renvois 0 si pas possible ou si derniere piece
//			ft_put_pieces(map, input, nb_piece + 1);
//		else
//			ft_clean_piece(map, nb_piece);
//		i++;
//	}
//}

int				ft_resolver(char *input)
{
	t_map	*map;

	map = ft_create_map(input);
	ft_print_map(map->map, map->size);
	if (map == NULL)
		return (0);
//	ft_put_pieces(map, input, 0);
	return (1);
}
