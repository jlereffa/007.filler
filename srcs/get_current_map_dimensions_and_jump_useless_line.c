/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map_dimensions_and_jump_useless_line.c :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:53:45 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/10 21:54:01 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_map_dimensions_and_jump_useless_line(t_filler_var *v)
{
	char	*ptr;
	char	*to_free;

	if ((get_next_line(0, &ptr) == -1))//"Plateau X Y:"
		return (0);
	to_free = ptr;
	while (!(*ptr >= '0' && *ptr <= '9'))//To X
		ptr++;
	v->map_height = ft_atoi(ptr);
	while (*ptr >= '0' && *ptr <= '9')//To Y
		ptr++;
	v->map_lenght = ft_atoi(ptr);
	free(to_free);
	if ((get_next_line(0, &to_free) == -1))//Cut out useless ptr
		return (0);
	free(to_free);//free useless ptr
	return (1);
}
