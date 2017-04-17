/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 14:06:45 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/17 19:34:21 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

// freeeeeeeee

# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_map
{
	char	*map;
	int		size;
}				t_map;

void	ft_usage(void);
char	*ft_get_input(char *filename);
int		ft_check_input(char *input);
int		ft_resolver(char *input);
void	ft_print_map(char *str, int size);
void	ft_print_map(char *str, int size);

#endif
