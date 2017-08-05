/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_ai_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:38:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 11:52:03 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	determine_ai_token(t_filler_var *v)
{
	char	*line;
	char	*ptr;
	int		player;

	if ((get_next_line(0, &line)) == -1)
		return (0);
	ptr = line;
	while (*line != '1' && *line != '2')
		line++;
	player = ft_atoi(line);
	v->player_token = player == 1 ? 'O' : 'X';
	v->ennemy_token = player == 1 ? 'X' : 'O';
	v->ennemy_token_to_chase = player == 1 ? 'X' : 'O';
	free(ptr);
	return (1);
}
