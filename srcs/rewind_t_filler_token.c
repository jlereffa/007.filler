/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind_t_filler_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:31:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/11 10:33:38 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	rewind_t_filler_token(t_filler_token **token)
{
	while ((*token)->prev)
		*token = (*token)->prev;
}
