/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:31:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 19:34:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler_token			*fill_token_to_place(char **token_map,
						t_filler_token *token_to_place)
{
	int	x;
	int	y;
	t_filler_piece *tmp;//TO DEL

	x = 0;
	y = 0;
	while (token[x])
	{
		while (token[x][y])
		{
			if (token[x][y] == '*')
			{
				if (!(token_to_place = handle_t_token_lst(token_to_place, x, y)))
					return (NULL);
			}
			y++;
		}
		x++;
		y = 0;
	}
	while (token_to_place->prev)
		token_to_place = token_to_place->prev;
	tmp = token_to_place;//TO DELL
	while (tmp)//TO DEL
	{
		ft_putstr_fd("piece : x{", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("} y{", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putendl_fd("}", 2);
		tmp = tmp->next;
	}
	return (token_to_place);
}
