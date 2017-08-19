/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_filler_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:57:55 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/18 15:57:05 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler_token	*set_t_filler_token(t_filler_token *token, int x, int y)
{
	if (!token)
	{
		if (!(token = (t_filler_token*)malloc(sizeof(t_filler_token))))
			return (NULL);
		token->x = x;
		token->y = y;
		token->prev = NULL;
		token->next = NULL;
		return (token);
	}
	while (token->next)
		token = token->next;
	if (!(token->next = set_t_filler_token(token->next, x, y)))
		return (NULL);
	token->next->prev = token;
	token = token->next;
	return (token);
}
