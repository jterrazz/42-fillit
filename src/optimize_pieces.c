/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:49:42 by plogan            #+#    #+#             */
/*   Updated: 2017/04/19 15:58:50 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_optimize_pieces(t_pieces *pieces)
{
	int		i;

	i = 0;
	while (i < pieces->nb_of_pieces)
	{
		while (pieces->pieces[i][0].x && pieces->pieces[i][1].x
				&& pieces->pieces[i][2].x && pieces->pieces[i][3].x)
		{
			pieces->pieces[i][0].x--;
			pieces->pieces[i][1].x--;
			pieces->pieces[i][2].x--;
			pieces->pieces[i][3].x--;
		}
		while (pieces->pieces[i][0].y && pieces->pieces[i][1].y
				&& pieces->pieces[i][2].y && pieces->pieces[i][3].y)
		{
			pieces->pieces[i][0].y--;
			pieces->pieces[i][1].y--;
			pieces->pieces[i][2].y--;
			pieces->pieces[i][3].y--;
		}
		i++;
	}
}
