/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_if_is_player_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:38:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/10 20:35:07 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	define_if_is_player_one(t_filler_var *v)
{
	char	*line;
	char	*ptr;

	if ((get_next_line(0, &line)) == -1)
		return (0);
	ptr = line;
	while (*line != '1' && *line != '2')
		line++;
	v->is_player_one = ft_atoi(line) == 1 ? 1 : 2;
	free(ptr);
	return (1);
}