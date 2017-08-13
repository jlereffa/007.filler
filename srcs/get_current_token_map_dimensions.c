/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_token_map_dimensions.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:52:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 10:19:24 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_token_map_dimensions(t_filler_var *v)
{
	char	*ptr;
	char	*to_free;

	if ((get_next_line(0, &ptr) <= 0))//"Piece X Y"
		return (0);
	to_free = ptr;
	ptr += 6;
	v->token_map_height = ft_atoi(ptr);
	while (*ptr >= '0' && *ptr <= '9')//To Y
		ptr++;
	v->token_map_lenght = ft_atoi(ptr);
	free(to_free);
	return (1);
}
