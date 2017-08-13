/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map_dimensions_and_jump_useless_line.c :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:53:45 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 10:14:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_map_dimensions_and_jump_useless_line(t_filler_var *v)
{
	char	*ptr;
	char	*to_free;

	DEB
	if (get_next_line(0, &ptr) <= 0)
		return (0);
	DEB
	to_free = ptr;
	ptr += 8;
	DEB
	v->map_height = ft_atoi(ptr);
	DEB
	while (*ptr >= '0' && *ptr <= '9')//To Y
		ptr++;
	DEB
	v->map_lenght = ft_atoi(ptr);
	free(to_free);
	DEB
	if (get_next_line(0, &to_free) <= 0)
		return (0);
	DEB
	free(to_free);//free useless ptr
	DEB
	return (1);
}
