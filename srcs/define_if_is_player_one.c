/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_if_is_player_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:38:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 12:47:40 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	define_if_is_player_one(t_filler_var *v)
{
	char	*ptr;
	char	*to_free;

	if (get_next_line(0, &ptr) <= 0)
		return (0);
	putf(ptr);//
	putf("\n");//
	to_free = ptr;
	ptr += 10;
	v->is_player_one = *ptr - 48;
	free(to_free);
	return (1);
}
