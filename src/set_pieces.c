/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:38:26 by plogan            #+#    #+#             */
/*   Updated: 2017/04/19 14:55:29 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_set_pieces(t_pieces *pieces, char *input) // check is secure
{
	int		i;
	int		j;
	int		i_case;

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
				pieces->pieces[i][i_case].letter = i + 'A';
				i_case++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
