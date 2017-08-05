/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_t_filler_piece_lst.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:25:25 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 19:30:14 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler_token	*handle_t_token_lst(t_filler_token *token, int x,
				int y)
{
	if (!token)
	{
		if (!(token = (t_filler_piece*)malloc(sizeof(t_filler_piece))))
			return (NULL);
		token->x = x;
		token->y = y;
		token->prev = NULL;
		token->next = NULL;
		return (token);
	}
	while (token->next)
		token = token->next;
	if (!(token->next = handle_t_piece_lst(token->next, x, y)))
		return (NULL);
	token->next->prev = token;
	token = token->next;
	return (token);
}
