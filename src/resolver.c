/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:45:34 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 14:53:48 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pieces		*ft_get_pieces(char *input)
{
	int			i;
	int			count;
	t_pieces	*pieces;

	i = 0;
	count = 0;
	if (!(pieces = (t_pieces *)malloc(sizeof(t_pieces))))
		return (0);
	while (input[i])
	{
		if (i % 21 == 0)
			count++;
		i++;
	}
	pieces->nb_of_pieces = count;
	pieces->pieces = (t_case **)malloc(sizeof(t_case *) * count);
	if (pieces->pieces == NULL)
		return (0);
	ft_set_pieces(pieces, input);
	ft_optimize_pieces(pieces);
	return (pieces);
}

int				ft_place(t_map *map, t_case *piece, int i_map)
{
	int			x_map;
	int			y_map;
	int			i;
	int			x;
	int			y;

	i = 0;
	x_map = i_map % map->size;
	y_map = i_map / map->size;
	while (i < 4)
	{
		x = x_map + piece[i].x;
		y = y_map + piece[i].y;
		if (map->map[x + y * map->size] != '.' || x >= map->size || y >= map->size)
			return (0);
		i++;
	}
	while (i > 0)
	{
		i--;
		x = x_map + piece[i].x;
		y = y_map + piece[i].y;
		map->map[x + y * map->size] = piece[0].letter;
	}
	return (1);
}

void			ft_clean(t_map *map, t_case *piece, int i_map)
{
	int			x_map;
	int			y_map;
	int			i;
	int			x;
	int			y;

	i = 0;
	x_map = i_map % map->size;
	y_map = i_map / map->size;
	while (i < 4)
	{
		x = x_map + piece[i].x;
		y = y_map + piece[i].y;
		if (map->map[x + y * map->size] == piece[0].letter)
			map->map[x + y * map->size] = '.';
		i++;
	}
}

void			ft_put_pieces(t_map *map, t_pieces *pieces, int nb_pieces, int *sol_found)
{
	int			i_map;
	int			size_sq;

	if (nb_pieces == pieces->nb_of_pieces)
		*sol_found = 1;
	if (*sol_found == 1)
		return ;
	i_map = 0;
	size_sq = map->size * map->size;
	while (i_map < size_sq && !(*sol_found))
	{
		if (ft_place(map, pieces->pieces[nb_pieces], i_map)) // Renvois 0 si pas possible
			ft_put_pieces(map, pieces, nb_pieces + 1, sol_found);
		if (*sol_found == 0)
			ft_clean(map, pieces->pieces[nb_pieces], i_map);
		i_map++;
	}
}

int				ft_resolver(char *input)
{
	t_map		*map;
	t_pieces	*pieces;
	int			sol_found;
	int			map_size;

	sol_found = 0;
	if (!(pieces = ft_get_pieces(input)))
		return (0); // check if it handles null
	map_size = ft_sqrt(pieces->nb_of_pieces) * 2;
	while (!sol_found)
	{
		if (!(map = ft_create_map(map_size)))
			return (0);
		ft_put_pieces(map, pieces, 0, &sol_found);
		if (!sol_found)
			map_size++;
	}
	ft_print_map(map->map, map_size);
	return (1);
}
