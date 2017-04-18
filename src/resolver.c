/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 17:45:34 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/18 15:52:29 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map		 	*ft_create_map(int n)
{
	t_map *map;

	if(!(map = (t_map *)malloc(sizeof(t_map)))) // A verifier par le grand mickael
		return (NULL);
	map->size = n;
	map->map = ft_strnew(n * n);
	ft_memset(map->map, '.', n * n);
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

//void			ft_put_pieces(t_map *map, t_map *map_f, t_pieces *pieces, int nb_piece)
//{
//	int		i;
//	int		size_sq;
//
//	i = 0;
//	size_sq = map->size * map->size;
//	while (i < size_sq)
//	{
//		if (ft_place(map, map_f, input, nb_piece)) // Renvois 0 si pas possible ou si derniere piece
//			ft_put_pieces(map, map_f input, nb_piece + 1);
//		else
//			ft_clean(map, nb_piece);
//		i++;
//	}
//}

int				ft_set_pieces(t_pieces *pieces, char *input) // check is secure
{
	int i;
	int j;
	int i_case;

	i = 0;
	while (i < pieces->nb_of_pieces) // POUR CHAQUE PIECE
	{
		i_case = 0;
		pieces->pieces[i] = (t_case *)malloc(sizeof(t_case) * 4);
		if (pieces->pieces[i] == NULL)
			return (0);
		j = i * 21;
		while (j % 21 != 20) // On cherche chaque case
		{
			if (input[j] == '#')
			{
				pieces->pieces[i][i_case].x = (j - i * 21) % 5;
				pieces->pieces[i][i_case].y = (j - i * 21) / 5;
				i_case++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

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




	printf("Il y a %i pieces\n", pieces->nb_of_pieces); //DELLLLLLLLLLLLLL
	printf("%i, %i\n", pieces->pieces[1][0].x, pieces->pieces[1][0].y);
	printf("%i, %i\n", pieces->pieces[1][1].x, pieces->pieces[1][1].y);
	printf("%i, %i\n", pieces->pieces[1][2].x, pieces->pieces[1][2].y);
	printf("%i, %i\n", pieces->pieces[1][3].x, pieces->pieces[1][3].y);



	return (pieces);
}

int				ft_resolver(char *input)
{
	t_map		*map;
	t_map		*map_f;
	t_pieces	*pieces;
	
	if (!(pieces = ft_get_pieces(input)))
		return (0); // check if it handles null
	// Qgrqndir la map si pas de solution (partie du plus petit);
	if (!(map_f = ft_create_map(8)) || !(map = ft_create_map(8)))
		return (0);
//	ft_put_pieces(map, map_f, pieces, 0);
	return (1);
}
