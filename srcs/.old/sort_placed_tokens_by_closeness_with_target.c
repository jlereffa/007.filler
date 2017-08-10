/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_placed_tokens_by_closeness_with_target.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:08:22 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 12:08:47 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	establish_closeness(t_filler_token *token, int x, int y)
{
	int	ret_x;
	int	ret_y;

	while (token)
	{
		ret_x = (x - token->x) < 0 ? (x - token->x) * -1 : x - token->x;
		ret_y = (y - token->y) < 0 ? (y - token->y) * -1 : y - token->y;
		token->closeness = ret_x + ret_y;
		token = token->next;
	}
}

void		sort_placed_tokens_by_closeness_with_target(t_filler_token **token,
			t_filler_var *v)
{
	int				sorted;
	t_filler_token	*tmp;
	t_filler_token	*ptr;

	sorted = 0;
	establish_closeness(*token, E_COORD_X, E_COORD_Y);
	while (!sorted)
	{
		sorted = 1;
		while ((*token)->prev)
			*token = (*token)->prev;
		ptr = *token;
		while (ptr)
		{
			if (ptr->next && ptr->closeness > ptr->next->closeness)
			{
				sorted = 0;
				if (ptr->prev)
					ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				tmp = ptr->next->next;
				ptr->next->next = ptr;
				ptr->prev = ptr->next;
				ptr->next = tmp;
			}
			ptr = ptr->next;
		}
	}
	while ((*token)->prev)
		*token = (*token)->prev;
	tmp = *token;//TO DEL
	while (tmp)//TO DEL
	{
		ft_putstr_fd("closeness : {", 2);
		ft_putnbr_fd(tmp->closeness, 2);
		ft_putstr_fd("}\n", 2);
		tmp = tmp->next;
	}
}
