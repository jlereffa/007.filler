/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_players_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:38:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 20:44:28 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	determine_players_token(t_filler_var *v)
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
	v->enemy_token = player == 1 ? 'X' : 'O';
	v->enemy_token_to_chase = player == 1 ? 'X' : 'o';
	free(ptr);
	return (1);
}
