/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:38:26 by plogan            #+#    #+#             */
/*   Updated: 2017/04/19 16:05:37 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_set_pieces(t_pieces *pieces, char *input)
{
	int		i;
	int		j;
	int		i_case;

	i = 0;
	while (i < pieces->nb_of_pieces)
	{
		i_case = 0;
		pieces->pieces[i] = (t_case *)malloc(sizeof(t_case) * 4);
		if (pieces->pieces[i] == NULL)
			return (0);
		j = i * 21;
		while (j % 21 != 20)
		{
			if (input[j] == '#')
			{
				pieces->pieces[i][i_case].x = (j - i * 21) % 5;
				pieces->pieces[i][i_case].y = (j - i * 21) / 5;
				pieces->pieces[i][i_case++].letter = i + 'A';
			}
			j++;
		}
		i++;
	}
	return (1);
}

t_pieces	*ft_get_pieces(char *input)
{
	int			i;
	uint8_t		count;
	t_pieces	*pieces;

	i = 0;
	count = 0;
	if (!(pieces = (t_pieces *)malloc(sizeof(t_pieces))))
		return (0);
	while (input[i])
	{
		if (i % 21 == 0)
			++count;
		++i;
	}
	pieces->nb_of_pieces = count;
	pieces->pieces = (t_case **)malloc(sizeof(t_case *) * count);
	if (pieces->pieces == NULL)
		return (0);
	if (ft_set_pieces(pieces, input) == 0)
		return (0);
	ft_optimize_pieces(pieces);
	return (pieces);
}
