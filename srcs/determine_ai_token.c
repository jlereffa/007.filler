/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_ai_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:38:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/31 17:25:41 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	determine_ai_token(t_filler_var *v, int fd)
{
	char	*line;
	char	*ptr;
	int		player;

	line = NULL;
	get_next_line(0, &line);
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	ptr = line;
	while (*line != 'p')
		line++;
	player = ft_atoi(line + 1);
	v->player_token = player == 1 ? 'O' : 'X';
	v->ennemy_token = player == 1 ? 'X' : 'O';
	v->ennemy_token_to_chase = player == 1 ? 'X' : 'O';
	free(ptr);
}