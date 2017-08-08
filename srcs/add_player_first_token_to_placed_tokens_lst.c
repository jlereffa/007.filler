/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_player_first_token_to_placed_tokens_lst.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:53:00 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 11:53:14 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	add_player_first_token_to_placed_tokens_lst(t_filler_var *v)//VALID
{
	int	i;
	int	j;
	t_filler_token	*tmp;//TO DEL

	i = 0;
	j = 0;
	while (v->plateau[i] && !v->player_token_is_found)
	{
		while (v->plateau[i][j] && !v->player_token_is_found)
		{
			if (v->plateau[i][j] == v->player_token)
			{
				if (!(v->placed_tokens = set_t_filler_token(v->placed_tokens,
					i, j)))
					return (0);
				v->player_token_is_found = 1;
				tmp = v->placed_tokens;//TO DEL
			}
			j++;
		}
		i++;
		j = 0;
	}
	while (tmp)//TO DEL
	{
		ft_putstr_fd("placed_token : x{", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("} y{", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putendl_fd("}", 2);
		tmp = tmp->next;
	}
	return (1);
}
