/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:45:34 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 16:14:20 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_place(t_map *map, t_case *piece, uint8_t i_map)
{
	uint8_t			x_map;
	uint8_t			y_map;
	uint8_t			i;
	uint8_t			x;
	uint8_t			y;

	i = 0;
	x_map = i_map % map->size;
	y_map = i_map / map->size;
	while (i < 4)
	{
		x = x_map + piece[i].x;
		y = y_map + piece[i].y;
		if (map->map[x + y * map->size] != '.' || x >= map->size ||
				y >= map->size)
			return (0);
		++i;
	}
	while (i > 0)
	{
		x = x_map + piece[--i].x;
		y = y_map + piece[i].y;
		map->map[x + y * map->size] = piece[0].letter;
	}
	return (1);
}

static void		ft_clean(t_map *map, t_case *piece, uint8_t i_map)
{
	uint8_t			x_map;
	uint8_t			y_map;
	uint8_t			i;
	uint8_t			x;
	uint8_t			y;

	i = 0;
	x_map = i_map % map->size;
	y_map = i_map / map->size;
	while (i < 4)
	{
		x = x_map + piece[i].x;
		y = y_map + piece[i].y;
		if (map->map[x + y * map->size] == piece[0].letter)
			map->map[x + y * map->size] = '.';
		++i;
	}
}

static void		ft_put_pieces(t_map *map, t_pieces *pieces,
		uint8_t nb_pieces, uint8_t *sol_found)
{
	uint8_t		i_map;
	int			size_sq;

	if (nb_pieces == pieces->nb_of_pieces)
		*sol_found = 1;
	if (*sol_found == 1)
		return ;
	i_map = 0;
	size_sq = map->size * map->size;
	while (i_map < size_sq && !(*sol_found))
	{
		if (ft_place(map, pieces->pieces[nb_pieces], i_map))
			ft_put_pieces(map, pieces, nb_pieces + 1, sol_found);
		if (*sol_found == 0)
			ft_clean(map, pieces->pieces[nb_pieces], i_map);
		++i_map;
	}
}

static void		ft_free_pieces(t_pieces *pieces)
{
	int i;

	i = 0;
	while (i < pieces->nb_of_pieces)
	{
		free(pieces->pieces[i]);
		i++;
	}
	free(pieces->pieces);
	free(pieces);
}

int				ft_resolver(char *input)
{
	t_map		*map;
	t_pieces	*pieces;
	uint8_t		sol_found;
	uint8_t		map_size;

	sol_found = 0;
	if (!(pieces = ft_get_pieces(input)))
		return (0);
	map_size = ft_sqrt(pieces->nb_of_pieces) * 2;
	while (!sol_found)
	{
		if (!(map = ft_create_map(map_size)))
			return (0);
		ft_put_pieces(map, pieces, 0, &sol_found);
		if (!sol_found)
		{
			free(map);
			++map_size;
		}
	}
	ft_print_map(map->map, map_size);
	ft_free_pieces(pieces);
	free(map);
	return (1);
}
