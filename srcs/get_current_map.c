/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:54:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/18 12:38:45 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	fill_map_string_from_line(t_filler_var *v, char *ptr, int i)
{
	int	j;

	ptr += 4;
	j = 0;
	while (*ptr)
	{
		if (*ptr == '.')
			v->map[i][j] = '.';
		else if (*ptr == 'O' || *ptr == 'o' || *ptr == 'X' || *ptr == 'x')
		{
			if ((v->is_player_one == 1 && (*ptr == 'O' || *ptr == 'o')) ||
				(v->is_player_one == 2 && (*ptr == 'X' || *ptr == 'x')))
				v->map[i][j] = 'P';
			else
				v->map[i][j] = 'T';
		}
		ptr++;
		j++;
	}
	v->map[i][j] = '\0';
	return (1);
}

int			get_current_map(t_filler_var *v)
{
	char	*to_free;
	int		i;

	if (!(v->map = (char**)malloc(sizeof(char*) * v->map_height + 1)))
		return (0);
	i = -1;
	while (++i < v->map_height)
	{
		if (!(v->map[i] = (char*)malloc(sizeof(char) * v->map_lenght + 1)) ||
			((get_next_line(v->fd, &to_free) <= 0)))
			return (0);
		fill_map_string_from_line(v, to_free, i);
		free(to_free);
	}
	v->map[i] = NULL;
	return (1);
}
