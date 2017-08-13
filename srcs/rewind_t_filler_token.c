/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind_t_filler_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:31:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 10:23:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	rewind_t_filler_token(t_filler_token **token)
{
	if (!token || !*token)
		return (0);
	while ((*token)->prev)
		*token = (*token)->prev;
	return (1);
}
