/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_token_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:52:13 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 13:48:35 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_token_map(t_filler_var *v)
{
	char	*ptr;
	int		i;

	if (!(v->token_map = (char**)malloc(sizeof(char*) * v->map_height + 1)))
		return (0);
	i = -1;
	while (++i < v->token_map_height)
	{
		if ((get_next_line(v->fd, &ptr) <= 0))
			return (0);
	//	putf(ptr);//
		//putf("\n");//
		v->token_map[i] = ptr;
	}
	v->token_map[i] = NULL;
	return (1);
}
