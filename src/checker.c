/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:15:17 by jterrazz          #+#    #+#             */
/*   Updated: 2017/04/17 16:31:20 by jterrazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_piece(char *str)
{
	int nb_hash;
	int nb_char_valid;
	int i;

	nb_hash = 0;
	nb_char_valid = 0;
	while(nb_char_valid < 20)
	{
		i = 0;)
		if (str[i] == '.' || str [i] == '#')
			i++;
		else if (str[i] == '\n' && i == 4)
			i = 0;
		else
			return (NULL);
		nb_char_valid++;
	}
}

int		ft_check_input()
{
	
}
