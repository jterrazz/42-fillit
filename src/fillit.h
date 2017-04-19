/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:06:45 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/19 15:05:43 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// freeeeeeeee
// convert local ft to static

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_map
{
	char		*map;
	uint8_t		size;
}				t_map;

typedef struct	s_case
{
	uint8_t		x;
	uint8_t		y;
	char		letter;
}				t_case;

typedef struct	s_pieces
{
	uint8_t		nb_of_pieces;
	t_case		**pieces;
}				t_pieces;

void			ft_optimize_pieces(t_pieces *pieces);
t_map			*ft_create_map(int n);
void			ft_usage(void);
char			*ft_get_input(char *filename);
int				ft_check_input(char *input);
int				ft_resolver(char *input);
void			ft_print_map(char *str, int size);
void			ft_print_map(char *str, int size);
int				ft_set_pieces(t_pieces *pieces, char *input);

#endif
